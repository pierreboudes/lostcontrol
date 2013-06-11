#!/usr/bin/python
# -*-coding:Latin-1 -*
# -*- coding:utf8 -*-
import pygame
from pygame import locals

pygame.init()

#On compte les joysticks
nb_joysticks = pygame.joystick.get_count()
#Et on en crée un s'il y a en au moins un
if nb_joysticks > 0:
	mon_joystick = pygame.joystick.Joystick(0)

	mon_joystick.init()

	#On compte les boutons
	nb_boutons = mon_joystick.get_numbuttons()

	print("Axes :", mon_joystick.get_numaxes())
	print("Boutons :", mon_joystick.get_numbuttons())
	print("Trackballs :", mon_joystick.get_numballs())
	print("Hats :", mon_joystick.get_numhats())

	continuer = 1
	while continuer:

			for event in pygame.event.get():
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 5:# si event sur R2 quitté le programme
					continuer = 0

				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 0:
					mon_fichier = open("/var/www/commande.txt", "w")
					mon_fichier.write("Bouton 1")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 1:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton 2")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 2:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("s")
					mon_fichier.close()					
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 3:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton 4")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 4:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton R1")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 6:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton L1")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 7:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton L2")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 8:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton Back")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button == 9:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Bouton Start")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button ==10:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Pad 1 appuyé ")
					mon_fichier.close()
				if event.type == pygame.locals.JOYBUTTONDOWN and event.button ==11:
					mon_fichier = open("commande.txt", "w")
					mon_fichier.write("Pad 2 appuyé ")
					mon_fichier.close()

				if event.type == pygame.locals.JOYAXISMOTION:

					if event.axis == 0 and event.value > 0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("d\n1.0 -1.0 ")
						mon_fichier.close()
					if event.axis == 0 and event.value < -0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("g\n1.0 1.0 ")
						mon_fichier.close()
					if event.axis == 1 and event.value > 0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("r\n-1.0 0.0 ")
						mon_fichier.close()
					if event.axis == 1 and event.value < -0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("a\n1.0 0.0 ")
						mon_fichier.close()

						
						
					if event.axis == 3 and event.value > 0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("d\n-0.5 -0.5 ")
						mon_fichier.close()
					if event.axis == 3 and event.value < -0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("g\n0.5 0.5 ")
						mon_fichier.close()
					if event.axis == 2 and event.value > 0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("r\n-2.0 0.0 ")
						mon_fichier.close()
					if event.axis == 2 and event.value < -0.5:
						mon_fichier = open("commande.txt", "w")
						mon_fichier.write("a\n2.0 0.0 ")
						mon_fichier.close()

else:
	print("Vous n'avez pas branché de Joystick...")
