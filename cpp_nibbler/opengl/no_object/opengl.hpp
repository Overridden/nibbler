//
// tutorial.hpp for tuto in /home/nguye_1/projects/OpenGL
//
// Made by Alexandre NGUYEN
// Login   <nguye_1@epitech.net>
//
// Started on  Thu Feb 13 16:33:59 2014 Alexandre NGUYEN
// Last update Sat Apr  5 11:53:09 2014 Alexandre NGUYEN
//

#ifndef TUTORIAL_HPP_
# define TUTORIAL_HPP_

#include "./objects.h"

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define FPS 8
#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700

#define CAM_POS_X	0
#define CAM_POS_Y	-50
#define CAM_POS_Z	6
#define CAM_LOOK_X	0
#define CAM_LOOK_Y	0
#define CAM_LOOK_Z	0

void            Dessiner();
void		stop();
int             graphic();

#endif /* TUTORIAL_HPP_ */
