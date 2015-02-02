//
// tutorial.hpp for tuto in /home/nguye_1/projects/OpenGL
//
// Made by Alexandre NGUYEN
// Login   <nguye_1@epitech.net>
//
// Started on  Thu Feb 13 16:33:59 2014 Alexandre NGUYEN
// Last update Sun Apr  6 15:16:46 2014 Alexandre NGUYEN
//

#ifndef TUTORIAL_HPP_
# define TUTORIAL_HPP_

#include "../IGraphic.hh"

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define LARGEUR_FENETRE 1500
#define HAUTEUR_FENETRE 700

#define CAM_POS_X	0
#define CAM_POS_Y	-50
#define CAM_POS_Z	6
#define CAM_LOOK_X	0
#define CAM_LOOK_Y	0
#define CAM_LOOK_Z	0

class		Opengl : public IGraphic
{
public:
  Opengl();
  ~Opengl();

private:
  sf::RenderWindow	*App;
  int			x;
  int			y;
  sf::Event		_event;
  sf::Music		bg_sound;
  sf::Music		eat_sound;
  GLuint		meat_boy;

public:
  bool		init_game(int, int);
  bool		show_map(int, int);
  bool		show_head(int, int);
  bool		show_body(int, int);
  bool		show_food(int, int);
  bool		print();
  e_event	event();
  void		graphic_quit();
  void		play_sound();

  void		draw_food(int x, int y);
  void		draw_head(int x, int y);
  void		draw_body(int x, int y);
  void		draw_field(float width, float height);
};

#endif /* TUTORIAL_HPP_ */
