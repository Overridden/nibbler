//
// sdl.hh for  in /home/lastru_g/rendu/cpp_nibbler/lib_sdl
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sat Apr  5 15:24:58 2014 lastrucci
// Last update Sun Apr  6 15:55:12 2014 lastrucci
//

#ifndef SDL_HH_
# define SDL_HH_

#include <SDL/SDL.h>

class		Sdl
{
public:
  SDL_Surface	*my_SDL_LoadBMP(char *);
  int		my_SDL_Init(Uint32);
  SDL_Surface	*my_SDL_SetVideoMode( int,  int,  int,  Uint32);
  void		my_SDL_WM_SetCaption( char *, char *);
  void		my_SDL_WM_SetIcon(SDL_Surface *,  Uint8 *);
  int		my_SDL_FillRect(SDL_Surface *,  SDL_Rect *,  Uint32);
  int		my_SDL_Flip( SDL_Surface *);
  int		my_SDL_BlitSurface( SDL_Surface *,  SDL_Rect *,
				SDL_Surface *, SDL_Rect *);
  int		my_SDL_PollEvent(SDL_Event *);
  void		my_SDL_FreeSurface(SDL_Surface *);
  void		my_SDL_Quit();
};

#endif
