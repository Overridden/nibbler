/*
** objects.h for 203 in /home/nguye_1/rendu/203hotline
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Fri Mar 28 17:49:44 2014 Alexandre NGUYEN
** Last update Thu Apr  3 19:24:15 2014 Alexandre NGUYEN
*/

#ifndef OBJECTS_H_
# define OBJECTS_H_

#include "opengl.hpp"

void		cube(double x, double y, double z, double size, int methode);
void		draw();
void		draw_head(int x, int y);
void		draw_field(float width, float height);

#endif /* OBJECTS_H_ */
