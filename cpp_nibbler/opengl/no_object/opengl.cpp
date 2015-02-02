//
// tutorial.cpp for opengl tutp in /home/nguye_1/projects/OpenGL
//
// Made by Alexandre NGUYEN
// Login   <nguye_1@epitech.net>
//
// Started on  Thu Feb 13 15:25:03 2014 Alexandre NGUYEN
// Last update Mon Sep 22 17:30:57 2014 Alexandre NGUYEN
//
#include "opengl.hpp"

#include <ctime>
#include <iomanip>

double angleZ = 0;
double angleX = 0;

int	mov;
int	lenght = 50;
int	width = 50;
float	x = width/2;
float	y = lenght/2;
float	z = 0;

int		graphic()
{
  unsigned int width = LARGEUR_FENETRE;
  unsigned int height = HAUTEUR_FENETRE;

  sf::RenderWindow App(sf::VideoMode(width, height, 32), "Nibbler - so awesome 0.0",
		       sf::Style::Default, sf::ContextSettings(24, 8, 4, 2, 0)
);

  App.setFramerateLimit(FPS);
  glMatrixMode( GL_PROJECTION );
  glEnable(GL_DEPTH_TEST);
  gluPerspective(70,(double)width/height,0.001,1000);

  sf::Event event;
  while (App.isOpen())
    {
      while (App.pollEvent(event))
	{
	  switch (event.type)
	    {
	    case sf::Event::KeyPressed:
	      switch (event.key.code)
		{
		case sf::Keyboard::Escape:
		  App.close();
		  break;
		case sf::Keyboard::Right:
		  mov = 1;
		  break;
		case sf::Keyboard::Left:
		  mov = -1;
		  break;
		case sf::Keyboard::Up:
		  mov = 2;
		  break;
		case sf::Keyboard::Down:
		  mov = -2;
		  break;
		default:
		  break;
		}
	      break;
	    default:
	      break;
	    }
	}
      Dessiner();
      App.display();
    }
  return 0;
}

void		Dessiner()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  switch (mov)
    {
    case 1:
      ++x;
      break;
    case -1:
      --x;
      break;
    case 2:
      ++y;
      break;
    case -2:
      --y;
      break;
    }
  gluLookAt(width * 4, -40 , 120, x * 2, y * 8, 0, 0, 0, 1);
  draw_field(width,lenght);
  draw_head(x, y);

  // glFlush();
}

int	main()
{
   graphic();
}
