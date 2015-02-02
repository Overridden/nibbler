//
// map.cpp for  in /home/lastru_g/rendu/cpp_nibbler
//
// Made by lastrucci
// Login   <lastru_g@epitech.net>
//
// Started on  Fri Mar 28 16:39:54 2014 lastrucci
// Last update Sun Apr  6 20:37:36 2014 lastrucci
//

#include "./map.hh"

		/*	CTOR / DTOR	*/

Map::Map(const int x, const int y) : width(x), height(y)
{
  int		x1;
  int		y1;

  x1 = x;
  y1 = y;
  this->nb_food = 0;
  this->speed = EXEC_TIME;
  this->map = "";
  while (x1 > 0)
    {
      y1 = this->height;
      while (y1 > 0)
	{
	  this->map += EMPTY;
	  --y1;
	}
      --x1;
    }
  this->move_actual = MOVE_RIGHT;
  this->set_snake_begin();
}

Map::~Map()
{
}

void		Map::set_snake_begin()
{
  int		x[1];
  int		y[1];

  x[0] = ((this->width - 1) / 2) - 2;
  y[0] = (this->height - 1) / 2;

  x[1] = ((this->width - 1) / 2) - 1;
  y[1] = (this->height - 1) / 2;

  x[2] = ((this->width - 1) / 2) - 0;
  y[2] = (this->height - 1) / 2;

  this->snake = new Nibbler(x, y, 3);
  this->map[(this->width * y[0]) + x[0]] = BODY;
  this->map[(this->width * y[1]) + x[1]] = BODY;
  this->map[(this->width * y[2]) + x[2]] = HEAD;
}

		/*	GETTER		*/

const std::string		&Map::getMap() const
{
  return (this->map);
}

		/*	CHECK MAP	*/

bool		Map::move(IGraphic *glib)
{
  t_nibbler	*elem;

  elem = this->snake->ret_head();
  if (this->move_actual == MOVE_UP)
    {
      if (this->move_action(elem->width, elem->height - 1, glib) == 0)
	return (false);
    }
  else if (this->move_actual == MOVE_DOWN)
    {
      if (this->move_action(elem->width, elem->height + 1, glib) == 0)
	return (false);
    }
  else if (this->move_actual == MOVE_LEFT)
    {
      if (this->move_action(elem->width - 1, elem->height, glib) == 0)
	return (false);
    }
  else
    {
      if (this->move_action(elem->width + 1, elem->height, glib) == 0)
	return (false);
    }
  return (true);
}

bool		Map::move_action(int x, int y, IGraphic *glib)
{
  int		nb;
  int		pos;
  t_nibbler	*elem;
  t_nibbler	*elem_tail;

  pos = 0;
  elem_tail = this->snake->ret_tail();
  nb = (this->width * y) + x;
  if (nb == ((this->width * elem_tail->height) + elem_tail->width))
    pos = 1;
  if (x < 0 || y < 0 || x >= this->width || y >= this->height)
    {
      if (x < 0)
	x = this->width - 1;
      else if (x >= this->width)
	x = 0;
      if (y < 0)
	y = this->height - 1;
      else if (y >= this->height)
	y = 0;
      nb = (this->width * y) + x;
    }
  if (this->map[nb] == BODY && !( nb == ((this->width * elem_tail->height) + elem_tail->width)))
    {
      std::cout << "die potatos!!!" << std::endl;
      std::cout << "score : " << this->nb_food * 10 << "." << std::endl;
      return (false);
    }
  else if (this->map[nb] == FOOD)
    {
      this->map[nb] = HEAD;
      elem = this->snake->add_elem(x, y, 1);
      this->map[(this->width * elem->height) + elem->width] = BODY;
      ++this->nb_food;
      if (this->pop_food() == false)
	{
	  std::cout << "WIN !!!" << std::endl;
	  return (false);
	}
      glib->play_sound();
      return (true);
    }
  else
    {
      this->map[nb] = HEAD;
      elem = this->snake->ret_head();
      this->map[(this->width * elem->height) + elem->width] = BODY;
      elem = this->snake->add_elem(x, y, 0);
      if (pos == 0)
	this->map[(this->width * elem->height) + elem->width] = EMPTY;
    }
  return (true);
}

		/*	AFFICHAGE MAP	*/

void			Map::aff_map() const
{
  int		i;

  i = 0;
  while (this->map[i] != 0)
    {
      if (i % this->width == 0 && i != 0)
	std::cout << std::endl;
      std::cout << this->map[i];
      i++;
    }
  std::cout << std::endl;
}

			/*	LE JEU EN LUI MEME	*/

bool			Map::init_map_game(IGraphic *glib) const
{
  if (glib->init_game(this->width, this->height) == false)
    return (false);
  if (glib->show_map(this->width, this->height) == false)
    return (false);
  return (true);
}

bool			Map::ret_gettimeofday(struct timeval *tv) const
{
  Encaps		tmp;

  if (tmp.my_gettimeofday(tv, NULL) != 0)
    {
      std::cerr << "error manage time" << std::endl;
      return (false);
    }
  return (true);
}

bool			Map::prepare_map(IGraphic *glib) const
{
  int			x;
  int			y;
  e_type		choice;

  y = 0;
  glib->show_map(this->width, this->height);
  while (y < this->height)
    {
      x = 0;
      while (x < this->width)
	{
	  choice = (e_type)this->map[y * this->width + x];
	  if (choice == HEAD)
	    {
	      if (glib->show_head(x, y) == false)
		return (false);
	    }
	  else if (choice == BODY)
	    {
	      if (glib->show_body(x, y) == false)
		return (false);
	    }
	  else if (choice == FOOD)
	    if (glib->show_food(x, y) == false)
	      return (false);
	  ++x;
	}
      ++y;
    }
  if (glib->print() == false)
    return (false);
  return (true);
}

bool			Map::shift(const e_event event, IGraphic *glib)
{
  if (event == ECHAPS)
    return (false);
  else if(event == RIGHT)
    {
      if (this->move_actual == MOVE_LEFT)
	this->move_actual = MOVE_UP;
      else if (this->move_actual == MOVE_UP)
	this->move_actual = MOVE_RIGHT;
      else if (this->move_actual == MOVE_RIGHT)
	this->move_actual = MOVE_DOWN;
      else
	this->move_actual = MOVE_LEFT;
      if (this->move(glib) == false)
	return (false);
      return (true);
    }
  else if(event == LEFT)
    {
      if (this->move_actual == MOVE_UP)
	this->move_actual = MOVE_LEFT;
      else if (this->move_actual == MOVE_LEFT)
	this->move_actual = MOVE_DOWN;
      else if (this->move_actual == MOVE_DOWN)
	this->move_actual = MOVE_RIGHT;
      else
	this->move_actual = MOVE_UP;
      if (this->move(glib) == false)
	return (false);
      return (true);
    }
  else if (event == NOTHING)
    if (this->move(glib) == false)
      return (false);
  return (true);
}

bool			Map::pop_food()
{
  int			x;
  int			y;
  int			nb;
  Encaps		tmp;

  x = tmp.my_rand() % this->width;
  y = tmp.my_rand() % this->height;
  nb = y * this->width + x;
  y = nb - 1;
  while (this->map[nb] != EMPTY && map[nb] != 0)
    ++nb;
  if (this->map[nb] == 0)
    {
      while (this->map[y] != EMPTY && y >= 0)
	--y;
      nb = y;
    }
  if (nb < 0)
    return (false);
  this->map[nb] = FOOD;
  return (true);
}

bool			Map::loop(IGraphic *glib)
{
  struct timeval	tv_beg;
  long			beg;
  struct timeval	tv_end;
  long			end;
  e_event		event;
  Encaps		tmp;

  if (this->ret_gettimeofday(&tv_beg) == false)
    return (false);
  beg = (tv_beg.tv_sec * 1000000 + tv_beg.tv_usec);
  if (this->ret_gettimeofday(&tv_end) == false)
    return (false);
  end = (tv_end.tv_sec * 1000000 + tv_end.tv_usec);
  while (end <= beg + this->speed)
    {
      if ((event = glib->event()) != NOTHING)
	{
	  if (this->shift(event, glib) == false)
	    return (false);
	  if (tmp.my_usleep(beg + this->speed - end) == -1)
	    return (false);
	  return (true);
	}
      if (this->ret_gettimeofday(&tv_end) == false)
	{
	  return (false);
	}
      end = (tv_end.tv_sec * 1000000 + tv_end.tv_usec);
      if (usleep(200) == -1)
	return (false);
    }
  return (this->shift(event, glib));
}

bool			Map::game(IGraphic *glib)
{
  char			fine = true;

  if (this->init_map_game(glib) == false)
    return (false);
  this->pop_food();
  if ((fine = this->prepare_map(glib)) == false)
    return (false);
  srand(time(NULL));
  while (fine == true)
    {
      if (this->nb_food  == (this->width / 2 * this->height / 2))
	this->speed = 1000000 / (FPS + 3);
      if (this->nb_food  == (this->width * this->height))
	this->speed = 1000000 / (FPS + 3);
      if ((fine = this->loop(glib)) == false)
	{
	  glib->graphic_quit();
	  return (false);
	}
      if ((fine = this->prepare_map(glib)) == false)
	{
	  glib->graphic_quit();
	  return (false);
	}
   }
  return (true);
}
