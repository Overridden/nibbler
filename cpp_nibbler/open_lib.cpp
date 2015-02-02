//
// open_lib.cpp for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sun Apr  6 17:47:55 2014 lastrucci
// Last update Sun Apr  6 18:03:54 2014 lastrucci
//

#include "./open_lib.hh"

OpenLib::OpenLib()
{
}

OpenLib::~OpenLib()
{
}

void		*OpenLib::my_dlopen(const char *filename, int flags)
{
  return (dlopen(filename, flags));
}

void		*OpenLib::my_dlsym(void *handle, const char *symbol)
{
  return (dlsym(handle, symbol));
}

int		OpenLib::my_dlclose(void *handle)
{
  return (dlclose(handle));
}
