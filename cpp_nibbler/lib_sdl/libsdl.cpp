//
// libsdl.cpp for  in /home/lastru_g/rendu/cpp_nibbler/lib_sfml
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Tue Apr  1 17:13:23 2014 lastrucci
// Last update Sun Apr  6 17:42:58 2014 lastrucci
//

#include <string>
#include "libsdl.hh"

MySdl::MySdl()
{
  this->sdl = new Sdl();
  this->screen = NULL;
  this->food = NULL;
  this->body = NULL;
  this->head = NULL;
}

MySdl::~MySdl()
{
}

SDL_Surface	*MySdl::load_image_surface(char *path)
{
  SDL_Surface	*surface;

  if ((surface = this->sdl->my_SDL_LoadBMP(path)) == NULL)
    std::cerr << "load image fail -> path name = " << path << std::endl;
  return (surface);
}

bool		MySdl::graphic_init()
{
  char		path_food[] = "./lib_sdl/pack_images_sdz/food.bmp";
  char		path_body[] = "./lib_sdl/pack_images_sdz/body.bmp";
  char		path_head[] = "./lib_sdl/pack_images_sdz/Untitled.bmp";

  if (this->sdl->my_SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      std::cerr << "initialisation SDL fail" << std::endl;
      return (false);
    }
  this->food = this->load_image_surface(path_food);
  this->head = this->load_image_surface(path_head);
  this->body = this->load_image_surface(path_body);
  if (this->food == NULL || this->head == NULL ||
      this->body == NULL)
    return (false);
  return (true);
}

bool		MySdl::creat_window(const int x, const int y)
{
  SDL_Surface   *surface;
  char		path_icone[] = "./lib_sdl/pack_images_sdz/icone.bmp";
  char		path_name_windowd[] = "snake nokia 3310 power !!!";

  if ((this->screen = this->sdl->my_SDL_SetVideoMode(x * SIZE, y * SIZE, 32, SDL_HWSURFACE)) == NULL)
    {
      std::cerr << "open windows fail" << std::endl;
      return (false);
    }
  if (this->fill_screen(153, 153, 102) == false)
    return (false);
  this->sdl->my_SDL_WM_SetCaption(path_name_windowd, NULL);
  if ((surface = load_image_surface(path_icone)) == NULL)
    return (false);
  this->sdl->my_SDL_WM_SetIcon(surface, NULL);
  return (true);
}

bool		MySdl::fill_part_screen(SDL_Surface *surface, const char r,
					const char g, const char b)
{
  if (this->sdl->my_SDL_FillRect(surface, NULL, SDL_MapRGB
		   (surface->format, (Uint8)r, (Uint8)g, (Uint8)b)) == -1)
    {
      std::cerr << "fill screen fail" << std::endl;
      return (false);
    }
  return (true);
}

bool		MySdl::fill_screen(const char r, const char g, const char b)
{
  return (fill_part_screen(this->screen, r, g, b));
}

bool		MySdl::update_screen()
{
  if (this->sdl->my_SDL_Flip(this->screen) == -1)
    {
      std::cerr << "update screen fail" << std::endl;
      return (false);
    }
  return (true);
}

bool		MySdl::stuck_image(const int x, const int y, SDL_Surface *surface)
{
  SDL_Rect pos;

  pos.x = y;
  pos.y = x;
  if (this->sdl->my_SDL_BlitSurface(surface, NULL, this->screen, &pos) == -1)
    {
      std::cerr << "stuck new rect fail" << std::endl;
      return (false);
    }
  return (true);
}

bool		MySdl::past_image(const int x, const int y, const e_type choice)
{
  if (choice == FOOD)
    return (this->stuck_image(x, y, this->food));
  else if (choice == BODY)
    return (this->stuck_image(x, y, this->body));
  else if (choice == HEAD)
    return (this->stuck_image(x, y, this->head));
  return (true);
}

		/*	partie commune	*/

bool		MySdl::init_game(const int x, const int y)
{
  if (this->graphic_init() == false)
    return (false);
  if (this->creat_window(x, y) == false)
    return (false);
  return (true);
}

bool		MySdl::show_map(int width, int heigth)
{
  width = width;
  heigth = heigth;
  if (this->fill_screen(153, 153, 102) == false)
    return (false);
  return (true);
}

bool		MySdl::show_head(const int x, const int y)
{
  if (this->past_image(y * SIZE, x * SIZE, HEAD) == false)
    return (false);
  return (true);
}

bool		MySdl::show_body(const int x, const int y)
{
  if (this->past_image(y * SIZE, x * SIZE, BODY) == false)
    return (false);
  return (true);
}

bool		MySdl::show_food(const int x, const int y)
{
  if (this->past_image(y * SIZE, x * SIZE, FOOD) == false)
    return (false);
  return (true);
}

bool		MySdl::print()
{
  if (this->update_screen() == false)
    return (false);
  return (true);
}

e_event		MySdl::event()
{
  SDL_Event	event;

  if (this->sdl->my_SDL_PollEvent(&event) == 0)
    return (NOTHING);
  if (event.type == SDL_QUIT)
    return (ECHAPS);
  else if(event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (ECHAPS);
      else if (event.key.keysym.sym == SDLK_RIGHT)
	return (RIGHT);
      else if (event.key.keysym.sym == SDLK_LEFT)
	return (LEFT);
    }
  return (NOTHING);
}

void		MySdl::graphic_quit()
{
  if (this->food != NULL)
    this->sdl->my_SDL_FreeSurface(this->food);
  if (this->head != NULL)
    this->sdl->my_SDL_FreeSurface(this->head);
  if (this->body != NULL)
    this->sdl->my_SDL_FreeSurface(this->body);
  this->sdl->my_SDL_Quit();
}

void		MySdl::play_sound()
{
}

		/*----------------------*/

extern "C" IGraphic		*getInstance()
{
  return ((IGraphic *)new MySdl());
}
