#include "ros/ros.h"
#include "std_msgs/String.h"

#include <turtlesim/Velocity.h>
#include <stdlib.h>

#include <string>
#include <sstream>

#include "systeme_robot/Telecommande_trajectoire.h"
#include "systeme_robot/Gps_trajectoire.h"
#include "systeme_robot/Accelerometre_trajectoire.h"

using namespace std;

/** DEBUT CLASSE TRAJECTOIRE **/

class Trajectoire
{
	public :
		Trajectoire();
		
		void telecommandeCallback(const systeme_robot::Telecommande_trajectoire msg);
		
		
		// A COMPLETER QUAND DISPONIBLE
		void gpsCallback(const systeme_robot::Gps_trajectoire msg);
		void accelerometreCallback(const systeme_robot::Accelerometre_trajectoire msg);
		
	private :
		ros::Publisher publisher;
		ros::Subscriber telecommandeSubscribe;
		
		ros::Subscriber gpsSubscribe;
		ros::Subscriber accelerometreSubscribe;
		
		/*Variables contenant les valeurs de chaques topics pour le calcul de trajectoire*/
		systeme_robot::Telecommande_trajectoire commandeManuel;
		systeme_robot::Gps_trajectoire gps;
		systeme_robot::Accelerometre_trajectoire accelerometre;
		
};

Trajectoire::Trajectoire()
{
	ros::NodeHandle n;
	publisher = n.advertise<turtlesim::Velocity>("turtle1/command_velocity",1000);
	telecommandeSubscribe = n.subscribe("telecommande_trajectoire", 1000, &Trajectoire::telecommandeCallback, this);
	
	/* le noeud Trajectoire surveille 2 autres topics : le topic du GPS et le topic de l'Accelerometre
	  J'invite ceux qui se charge du GPS notamment a modifier les fonctions correspondantes.
	*/
	gpsSubscribe = n.subscribe("gps_trajectoire", 1000, &Trajectoire::gpsCallback, this);
	accelerometreSubscribe = n.subscribe("accelerometre_trajectoire", 1000, &Trajectoire::accelerometreCallback, this);
	
}


void Trajectoire::telecommandeCallback(const systeme_robot::Telecommande_trajectoire msg)
{
	  /*
	  /turtle1/command_velocity : Topic pour faire deplacer la tortue.
	  ordreTortue : message envoyer a la tortue
	  */
	  turtlesim::Velocity ordreTortue;
	  
	  ordreTortue.linear = 0.0;
	  ordreTortue.angular = 0.0;
	  
	  
	  // Lecture du message
	  ordreTortue.linear = msg.vlineaire;
	  ordreTortue.angular = msg.vangulaire;
	  
	  // Copie du message dans la variable correspondante
	  commandeManuel.vlineaire = msg.vlineaire;
	  commandeManuel.vangulaire = msg.vangulaire;
	  
	  // L'ordre a transmettre a la tortue a ete genere, on envoie le tout
	  publisher.publish(ordreTortue);
}


void Trajectoire::gpsCallback(const systeme_robot::Gps_trajectoire msg)
{
	/** A COMPLETER **/
}
void Trajectoire::accelerometreCallback(const systeme_robot::Accelerometre_trajectoire msg)
{
	/** A COMPLETER **/
}
/**FIN CLASSE TRAJECTOIRE **/



int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Trajectoire");

  /* on cree l'objet qui va se charger de :
  	-surveiller le topic telecommande_trajectoire pour les commandes manuelles
  	-surveiller les topic gps_trajectoire et accelerometre_trajectoire pour le calcul de trajectoire
  */
  Trajectoire myTrajectoire;
  ros::spin();

  return 0;
}
