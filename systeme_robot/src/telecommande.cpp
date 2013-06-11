#define AGE_FICHIER_MAX 2

#include "ros/ros.h"
#include <turtlesim/Velocity.h>
#include <stdlib.h>

#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <time.h>

#include "std_msgs/String.h"
#include <string>
#include <fstream>
#include <sstream>

#include "systeme_robot/Telecommande_trajectoire.h"
#define TRUNCATE(x,_min,_max) ((x) < (_min) ? (_min):((x) > (_max) ? (_max): (x)))
#define ZEROBELOWTHRESOLD(x, _thresold) ( (x) > (_thresold) || (x) < -(_thresold)   ? (x):0)

#define START_MYLOG std::ofstream fichierlog("/tmp/monlog", std::ios::out );
#define WRITE_MYLOG(x) {fichierlog << (x);}
#define CLOSE_MYLOG fichierlog.close();

int main(int argc, char **argv)
{
	//Initialisation du systeme ROS
	ros::init(argc,argv,"Telecommande");
	
	//lien vers le systeme
	ros::NodeHandle n;
	
	/* 
	Publisher sur le topic entre le node Telecommande et le node Trajectoire.
	*/
	ros::Publisher publisher = n.advertise<systeme_robot::Telecommande_trajectoire>("telecommande_trajectoire",1000);
	
	
	// Frequence de 10hz
	ros::Rate loop_rate(10);
	
	
	// variables de la telecommande
	int fd = open("/var/www/commande.txt", O_RDONLY);
	if( fd == -1)
	{
		ROS_INFO("Erreur ouverture de /var/www/commande.txt");
		ros::shutdown();
	}
	struct stat info;
	time_t lastUpdate;
	
	time_t currentTime;
	long int differenceSecondes;
	
	// Message echangee entre le node Telecommande et le node Trajectoire
	systeme_robot::Telecommande_trajectoire msg;
	
	START_MYLOG;

	while(ros::ok())
	{		
		ros::spinOnce();
		
		loop_rate.sleep();
		
		/** CONDITIONS D'ARRET DE LA TELECOMMANDE **/
		
		// On verifie l'heure de creation du fichier avec fstat, le temps de la derniere modification 
		// se trouve dans info.st_mtime		
		if( fstat(fd, &info) != 0)
		{
			ROS_INFO("Erreur fstat de /var/www/commande.txt");
		}
		
		// On recupere le temps actuelle
		time(&currentTime);
		
		// On regarde la difference
		differenceSecondes = difftime(currentTime, info.st_mtime);

		// ouvrir fichier
		std::ifstream fichier("/var/www/commande.txt", std::ios::in );
		
		// si la difference est superieur a un certain nombre de seconde ou si on ne le lit pas
		if( differenceSecondes >= AGE_FICHIER_MAX || !fichier)
		{
		  char buf[64];
		  sprintf(buf,"Stop %ld", differenceSecondes);
		  ROS_INFO("%s",buf);
		  WRITE_MYLOG(buf);

		  msg.mode = "s";
		  msg.vlineaire = 0.0;
		  msg.vangulaire = 0.0;
		  msg.vitesseRoueG = 0;
		  msg.vitesseRoueD = 0;
		}
		else
		{
		  // on lit le fichier								
		  int x;
		  fichier >> x;
		  int y;
		  fichier >> y;

		  char buf[1024];
		  sprintf(buf,"ordre: %d %d", x, y);
		  ROS_INFO("%s", buf);
		  WRITE_MYLOG(buf);

		  float g, d;
		  g = (x + y) / 2.0;
		  d = (y - x) / 2.0;
		  
		  g = TRUNCATE(g, -200, 200);
		  d = TRUNCATE(d, -200, 200);

		  g = ZEROBELOWTHRESOLD(g,5);
		  d = ZEROBELOWTHRESOLD(d,5);

		  msg.vitesseRoueG = g;
		  msg.vitesseRoueD = d;			       	 
		}		
		if (fichier) fichier.close();
		publisher.publish(msg);		
		
	}
	CLOSE_MYLOG;
}
