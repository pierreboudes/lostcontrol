#!/usr/bin/env python
import rospy
import serial
import time

#nos messages
from systeme_robot.msg import Autopilote_trajectoire

def sendToArduino(data):    
    rospy.loginfo(rospy.get_name() + ": Recu {}, {}".format(data.vitesseRoueG, data.vitesseRoueD))
    gauche = int( data.vitesseRoueG )
    droite = int( data.vitesseRoueD )

    if (abs(gauche)<45):
        gauche = 0

    if (abs(droite)<45):
        droite = 0
#    gauche = 200
#    droite = -200

    message = "HB" # mode commande du pont H, en binaire
    if gauche < 0:
        message += chr(0) + chr(-gauche)
    else:
        message += chr(2) + chr(gauche)
    if droite < 0:
        message += chr(0) + chr(-droite)
    else:
        message += chr(2) + chr(droite)

    rospy.loginfo(rospy.get_name() + ": prepenvoi arduino {}".format(message))
    com.write(message)
    rospy.loginfo(rospy.get_name() + ": envoi arduino {}".format(message))
    
def listener():
    rospy.init_node("daguserie", anonymous=True)
    rospy.Subscriber("autopilote_trajectoire", Autopilote_trajectoire, sendToArduino)
    rospy.spin()

if __name__ == '__main__':
    com = serial.Serial('/dev/ttyDAGU', baudrate=115200)
    com.writeTimeout = 1 
    time.sleep(2) #on attend que le bootloader de l'arduino lache le port
    rospy.loginfo(rospy.get_name() + ": connexion serie avec l'arduino etablie")
    listener()
#    com.write("HCATCT")
