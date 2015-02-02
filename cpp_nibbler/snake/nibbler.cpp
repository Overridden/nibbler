//
// nibbleur.cpp for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Thu Mar 27 19:24:27 2014 lastrucci
// Last update Sun Apr  6 19:01:26 2014 lastrucci
//

#include "./nibbler.hh"

				/*	CTOR DTOR	*/

Nibbler::Nibbler(const int *x, const int *y, const int nb)
{
  this->body = new std::list<t_nibbler *>;
  int		i;

  i = 0;
  while (i < nb)
    {
      this->Push_front(x[i], y[i]);
      i++;
    }
}

Nibbler::~Nibbler()
{
}

				/*************************/

/*si pos == 0 retourne la position de la queu que l'on as retirer
  si pos == 1, on retourne l'ensienne position de la tete (et mais pas la nouvelle)*/
t_nibbler			*Nibbler::add_elem(const int x, const int y,
						   const char pos)
{
  t_nibbler				*elem;

  elem = this->ret_head();
  this->Push_front(x, y);
  if (pos == 0)
    return (this->pop_back());
  return (elem);
}

t_nibbler			*Nibbler::new_elem(const int x,
							   const int y) const
{
  t_nibbler				*elem = new t_nibbler;

  elem->width = x;
  elem->height = y;
  return (elem);
}

t_nibbler			*Nibbler::ret_head() const
{
  return (*(this->body->begin()));
}

t_nibbler			*Nibbler::ret_tail() const
{
  return (this->body->back());
}

t_nibbler			*Nibbler::pop_back()
{
  t_nibbler		*elem;

  elem = this->body->back();
  this->body->pop_back();
  return (elem);
}

void				Nibbler::Push_front(const int x, const int y)
{
  this->body->push_front(new_elem(x, y));
}
