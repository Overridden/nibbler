//
// tutorial.cpp for opengl tutp in /home/nguye_1/projects/OpenGL
//
// Made by Alexandre NGUYEN
// Login   <nguye_1@epitech.net>
//
// Started on  Thu Feb 13 15:25:03 2014 Alexandre NGUYEN
// Last update Fri Dec  5 12:31:27 2014 Alexandre NGUYEN
//
#include "libopengl.hh"

Opengl::Opengl()
{
}

Opengl::~Opengl()
{
}

bool		Opengl::init_game(int x, int y)
{
  unsigned int width = LARGEUR_FENETRE;
  unsigned int height = HAUTEUR_FENETRE;
  sf::Image image;

  this->x = x / 2;
  this->y = y / 2;
  this->App = new sf::RenderWindow(sf::VideoMode(width, height, 32), "Nibbler - so awesome 0.0",
				   sf::Style::Default, sf::ContextSettings(24, 8, 4, 2, 0));
  if (!this->bg_sound.openFromFile("opengl/music/meatboy.ogg"))
    {
      std::cout << "Failed to load music \"opengl/music/meatboy.ogg\"" << std::endl;
      return false;
    }
  if (!this->eat_sound.openFromFile("opengl/music/splash.ogg"))
    {
      std::cout << "Failed to load music \"opengl/music/splash.ogg\"" << std::endl;
      return false;
    }
  this->bg_sound.setLoop(true);
  this->bg_sound.setVolume(10.f);
  this->bg_sound.play();
  this->App->setFramerateLimit(FPS);
  glMatrixMode(GL_PROJECTION);
  glEnable(GL_DEPTH_TEST);
  if (!image.loadFromFile("opengl/texture/meat_boy.jpeg"))
    {
      std::cout << "Failed to load \"opengl/texture/meat_boy.jpeg\"" << std::endl;
      return false;
    }
  glGenTextures(1, &this->meat_boy);
  glBindTexture(GL_TEXTURE_2D, this->meat_boy);
  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  gluPerspective(70,(double)width/height,0.001,1000);

  return true;
}

e_event		Opengl::event()
{
  e_event	key_pressed;

  while (this->App->pollEvent(this->_event))
    {
      switch (this->_event.type)
	{
	case sf::Event::KeyPressed:
	  switch (this->_event.key.code)
	    {
	    case sf::Keyboard::Escape:
	      return ECHAPS;
	      break;
	    case sf::Keyboard::Right:
	      key_pressed = LEFT;
	      break;
	    case sf::Keyboard::Left:
	      key_pressed = RIGHT;
	      break;
	    default:
	      key_pressed = NOTHING;
	      break;
	    }
	  break;
	default:
	  key_pressed = NOTHING;
	  break;
	}
    }
  return key_pressed;
}

bool		Opengl::show_map(int width, int height)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(width * 4, -40 + y*8 , 50, this->x * 8, this->y * 8, 0, 0, 0, 1);
  this->draw_field(width, height);
  return true;
}

bool		Opengl::show_head(int x, int y)
{
  this->x = x;
  this->y = y;
  this->draw_head(x, y);
  return true;
}

bool		Opengl::show_body(int x, int y)
{
  this->draw_body(x, y);
  return true;
}

bool		Opengl::show_food(int x, int y)
{
  draw_food(x, y);
  return true;
}

void		Opengl::graphic_quit()
{
  this->App->close();
}

bool		Opengl::print()
{
  this->App->display();
  return true;
}

void		Opengl::play_sound()
{
  this->eat_sound.setVolume(200.f);
  this->eat_sound.play();
}

		/*----------------------*/

extern "C" IGraphic		*getInstance()
{
  return ((IGraphic *)new Opengl());
}
