lostcontrol
===========

outdoor gardener robot


Démarrage rapide en mode telecommandé [telecommande.org](telecommande.org)


Pour créer votre propre commande (mettons un pilote automatique) :
- recopier sous un autre nom, disons pilote.cpp, et modifier le fichier [telecommande.cpp](systeme_robot/src/telecommande.cpp) de façon à émettre votre propre message de commande (deux entiers entre -300 et 300, pour la puissance des moteurs sur chacune des rangées de roues)
- recopier sous un autre nom et modifier le fichier [outdoor1.launch](systeme_robot/launch/outdoor1.launch) de façon à lancer le noeud pilote
