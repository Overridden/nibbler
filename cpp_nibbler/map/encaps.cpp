//
// encaps.cpp for  in /home/lastru_g/rendu/cpp_nibbler/map
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sat Apr  5 16:55:11 2014 lastrucci
// Last update Sun Apr  6 18:54:11 2014 lastrucci
//

#include "./encaps.hh"

Encaps::Encaps()
{
}

Encaps::~Encaps()
{
}

int		Encaps::my_gettimeofday(struct timeval *tv, struct timezone *tz)
{
  return (gettimeofday(tv, tz));
}

void		Encaps::my_srand(unsigned int seed)
{
  return (srand(seed));
}

time_t		Encaps::my_time(time_t *tloc)
{
  return (time(tloc));
}

int		Encaps::my_rand()
{
  return (rand());
}

int		Encaps::my_usleep(useconds_t usec)
{
  return (usleep(usec));
}
