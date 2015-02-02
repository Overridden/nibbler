//
// open_lib.hh for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sun Apr  6 17:47:50 2014 lastrucci
// Last update Sun Apr  6 18:03:17 2014 lastrucci
//

#ifndef OPEN_LIB_HH_
# define OPEN_LIB_HH_

#include <dlfcn.h>

class		OpenLib
{
public:
  OpenLib();
  ~OpenLib();
public:
  void		*my_dlopen(const char *, int);
  void		*my_dlsym(void *, const char *);
  int		my_dlclose(void *);
};

#endif
