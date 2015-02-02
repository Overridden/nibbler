//
// encaps.hh for  in /home/lastru_g/rendu/cpp_nibbler/map
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sat Apr  5 16:55:03 2014 lastrucci
// Last update Sun Apr  6 18:54:14 2014 lastrucci
//

#ifndef ENCAPS_HH_
# define ENCAPS_HH_

#include <sys/time.h>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

class		Encaps
{
public:
  Encaps();
  ~Encaps();
public:
  int		my_gettimeofday(struct timeval *, struct timezone *);
  int		my_rand();
  time_t	my_time(time_t *);
  void		my_srand(unsigned int);
  int		my_usleep(useconds_t);
};

#endif
