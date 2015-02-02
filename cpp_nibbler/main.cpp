//
// main.cpp for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Thu Mar 27 19:45:06 2014 lastrucci
// Last update Sun Apr  6 21:34:47 2014 Alexandre NGUYEN
//

#include <iostream>
#include <sstream>

#include "./open_lib.hh"
#include "./map/map.hh"
#include "./IGraphic.hh"

#define	SIZE_MIN	5
#define	SIZE_MAX	34

bool		verif_arg(const char *s1, const char *s2, int *width, int *height)
{
  std::stringstream	ss1(s1);
  std::stringstream	ss2(s2);

  ss1 >> *width;
  ss2 >> *height;
  if (*width < SIZE_MIN || *height < SIZE_MIN ||
      *width > SIZE_MAX || *height > SIZE_MAX)
    {
      std::cerr << "width and height > " << SIZE_MIN - 1
		<< " and < " << SIZE_MAX + 1 << std::endl;
      return (false);
    }
  return (true);
}

IGraphic	*test_open_dl(const char *path)
{
  void		*lib;
  IGraphic	*(*getInstance)();
  IGraphic	*glib;
  OpenLib	*use_lib = new OpenLib;

  if ((lib = use_lib->my_dlopen(path, RTLD_LAZY)) == NULL)
    {
      std::cerr << "troubleshot to loading graphic library -> "<< path << std::endl
		<< "try with: ./[library name]" << std::endl;
      return (NULL);
    }
  if ((getInstance = (IGraphic *(*)())use_lib->my_dlsym(lib, "getInstance")) == NULL)
    {
      std::cerr << "function getInstance not find" << std::endl;
      if (use_lib->my_dlclose(lib) != 0)
	{
	  std::cerr << "dclose fail" << std::endl;
	  return (NULL);
	}
      return (NULL);
    }
  glib = (*getInstance)();
  delete (use_lib);
  return (glib);
}

bool		game(const int width, const int height, IGraphic *glib)
{
  Map		*map = new Map(width, height);

  if (map->game(glib) == false)
    return (false);
  delete (map);
  return (true);
}

int		main(int ac, char **av)
{
  int		width;
  int		height;
  IGraphic	*glib;

  if (ac != 4)
    {
      std::cerr << "usage : ./nibbler [width] [height] [library name]"
  		<< std::endl;
      return (1);
    }
  if (verif_arg(av[1], av[2], &width, &height) == false)
    {
      std::cerr << "usage : ./nibbler [width] [height] [library name]"
  		<< std::endl;
      return (1);
    }
  if ((glib = test_open_dl(av[3])) == NULL)
    return (1);
  if (game(width, height, glib) == false)
    return (1);
  return (0);
}
