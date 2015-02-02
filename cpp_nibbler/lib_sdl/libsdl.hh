//
// libsdl.hh for  in /home/lastru_g/rendu/cpp_nibbler/lib_sfml
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Tue Apr  1 17:13:36 2014 lastrucci
// Last update Sun Apr  6 15:56:20 2014 lastrucci
//

#ifndef LIBSDL_HH_
# define LIBSDL_HH_

#include <iostream>
#include "sdl.hh"
#include "../IGraphic.hh"

#define	SIZE	30 // taille des image : 14 pxl -> 6 pxl de large vide entre 2 body

class		MySdl : public IGraphic
{
public:
  MySdl();
  ~MySdl();
private:
  Sdl		*sdl;
  SDL_Surface	*screen;
  SDL_Surface	*food;
  SDL_Surface	*body;
  SDL_Surface	*head;
  // load des image dans des surface
  SDL_Surface	*load_image_surface(char *);
public:
  // initialise la SDL
  bool		graphic_init();
   // cree la fenettre
  bool		creat_window(const int, const int);
  // replis SDL_Surface de la couleur des 3 char
  bool		fill_part_screen(SDL_Surface *, const char, const char, const char);
  // remplis la fennetre entiere de la couleur des 3 char
  bool		fill_screen(const char, const char, const char);
  // affiche la 'screen' (pour quans l'affichage dois changer)
  bool		update_screen();
  // colle l'image 'SDL_Surface *' en position des deux int
  bool		stuck_image(const int, const int, SDL_Surface *);
  // choisi quel image on veut coller et ou
  bool		past_image(const int, const int, const e_type);

  /*	partie commune	*/

  bool		init_game(const int, const int);
  bool		show_map(int, int);
  bool		show_head(const int, const int);
  bool		show_body(const int, const int);
  bool		show_food(const int, const int);
  bool		print();
  e_event	event();
   // quite la sdl et free les malloc de la sdl
  void		graphic_quit();
  void		play_sound();
};

extern "C" IGraphic       	*getInstance();

#endif
