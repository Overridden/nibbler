//
// map.hh for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Wed Mar 26 10:13:39 2014 lastrucci
// Last update Sun Apr  6 18:40:15 2014 lastrucci
//

#ifndef IMAP_HH_
# define IMAP_HH_

#include <string>
#include <iostream>
#include "./encaps.hh"
#include "../snake/nibbler.hh"
#include "../IGraphic.hh"

enum		e_move
  {
    MOVE_UP = 0,
    MOVE_RIGHT = 1,
    MOVE_DOWN = 2,
    MOVE_LEFT = 3
  };

class			Map
{
private:
  void			set_snake_begin();
public:
  Map(const int, const int);
  ~Map();
private:
  std::string		map;
  int			speed;
  Nibbler		*snake;
  int			nb_food;
  const int		width;
  const int		height;
  e_move		move_actual;
public:
  const std::string	&getMap() const;
  int			getHeight() const;
  int			getLenght() const;

  /**/

  bool			move(IGraphic *);
  bool			move_action(int, int, IGraphic *);

  /*affichage de la map en caractere ascii*/

  void			aff_map() const;

  // le jeu en lui meme
  bool			init_map_game(IGraphic *) const;
  bool			ret_gettimeofday(struct timeval *) const;
  bool			prepare_map(IGraphic *) const;
  bool			shift(const e_event, IGraphic *);
  bool			pop_food();
  bool			loop(IGraphic *);
  bool			game(IGraphic *);
};

#endif
