//
// nibbler.hh for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Thu Mar 27 18:02:24 2014 lastrucci
// Last update Sun Apr  6 19:01:23 2014 lastrucci
//

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

#include <list>

typedef struct			s_nibbler
{
  int	width;
  int	height;
} t_nibbler;

class				Nibbler
{
public:
  Nibbler(const int *, const int *, const int);
  ~Nibbler();
private:
  std::list<t_nibbler *>	*body;
public:
  t_nibbler			*add_elem(const int, const int, const char);
  t_nibbler			*new_elem(const int, const int) const;
  t_nibbler			*ret_head() const;
  t_nibbler			*ret_tail() const;
  t_nibbler			*pop_back();
  void				Push_front(const int, const int);
};

#endif
