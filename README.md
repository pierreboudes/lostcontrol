lostcontrol
===========

outdoor gardener robot


Demarrage rapide
1. mettre en place l'interface reseau wifi

term1$ sudo ifconfig wlan0 down
term2$ sudo hostapd hostapd.conf
term1$ sudo ifconfig wlan0 192.168.2.2 netmask 255.255.255.0 up

2. configurer le client
wifi "dagubot" (on peut modifier ce nom dans hostapd.conf)
192.168.2.3
dans le navigateur:
http://192.168.2.2/commande/

3. allumer le robot.
juste un switch, vérifier avant les court-circuits.

4. lancer le projet ROS
roscore
roslaunch systeme_robot outdoor1.launch

5. tester

