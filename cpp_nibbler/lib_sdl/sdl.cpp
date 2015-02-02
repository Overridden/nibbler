//
// sdl.cpp for  in /home/lastru_g/rendu/cpp_nibbler/lib_sdl
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Sat Apr  5 15:25:02 2014 lastrucci
// Last update Sun Apr  6 18:23:25 2014 lastrucci
//

#include "sdl.hh"

SDL_Surface	*Sdl::my_SDL_LoadBMP(char *str)
{
  return (SDL_LoadBMP(str));
}

int		Sdl::my_SDL_Init(Uint32 nb)
{
  return (SDL_Init(nb));
}

SDL_Surface	*Sdl::my_SDL_SetVideoMode(int a, int z, int e,  Uint32 nb)
{
  return (SDL_SetVideoMode(a, z, e, nb));
}

void		Sdl::my_SDL_WM_SetCaption( char *str,  char *str2)
{
  SDL_WM_SetCaption(str, str2);
}

void		Sdl::my_SDL_WM_SetIcon(SDL_Surface *surface, Uint8 *nb)
{
  SDL_WM_SetIcon(surface, nb);
}

int		Sdl::my_SDL_FillRect(SDL_Surface *Surface,  SDL_Rect *Rect,  Uint32 nb)
{
  return (SDL_FillRect(Surface, Rect, nb));
}

int		Sdl::my_SDL_Flip( SDL_Surface *Surface)
{
  return (SDL_Flip(Surface));
}

int		Sdl::my_SDL_BlitSurface( SDL_Surface *Surface,  SDL_Rect *Rect,
					SDL_Surface *Surface1, SDL_Rect *Rect1)
{
  return (SDL_BlitSurface(Surface, Rect, Surface1, Rect1));
}

int		Sdl::my_SDL_PollEvent(SDL_Event *Event)
{
  return (SDL_PollEvent(Event));
}

void		Sdl::my_SDL_FreeSurface(SDL_Surface *Surface)
{
  SDL_FreeSurface(Surface);
}

void		Sdl::my_SDL_Quit()
{
  SDL_Quit();
}
