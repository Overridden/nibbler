//
// IGraphic.hh for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Tue Apr  1 10:41:20 2014 lastrucci
// Last update Sun Apr  6 21:24:08 2014 Alexandre NGUYEN
//

#ifndef IGRAPHIC_HH_
# define IGRAPHIC_HH_

#define FPS 9
#define EXEC_TIME	1000000/FPS

enum		e_type
  {
    EMPTY = '.',
    FOOD = 'f',
    BODY = 'o',
    HEAD = 'x'
  };

enum		e_event
  {
    NOTHING,
    ECHAPS,
    LEFT,
    RIGHT,
    PAUSES
  };

class			IGraphic
{
public:
  virtual ~IGraphic() = 0;
  virtual bool		init_game(const int, const int) = 0;
  virtual bool		show_map(int, int) = 0;
  virtual bool		show_head(const int, const int) = 0;
  virtual bool		show_body(const int, const int) = 0;
  virtual bool		show_food(const int, const int) = 0;
  virtual bool		print() = 0;
  virtual e_event	event() = 0;
  virtual void		graphic_quit() = 0;
  virtual void		play_sound() = 0;
};

extern "C" IGraphic             *getInstance();

#endif
