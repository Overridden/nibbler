#include "nc.hh"

bool nc::init_game(int x,int y){
  my_initscr();
  my_erase();
  my_cbreak();
  my_keypad(stdscr, TRUE);
  my_noecho();
  my_nodelay(stdscr, TRUE);
  my_curs_set(0);
  for(int h = 0; h < y; h++){
      for(int w = 0; w < x; w++){
          if (my_mvprintw(h,w,"%c",' ') == ERR)
            return false;
        }
    }
  return true;
}
bool nc::show_map(int x,int y){
  for(int h = 0; h < y; h++){
      for(int w = 0; w < x; w++){
          if (my_mvprintw(h,w,"%c",EMPTY) == ERR)
            return false;
        }
    }
  return true;
}
bool nc::show_head(int x,int y){
  if (my_mvprintw(y,x,"%c",HEAD) == ERR)
    return false;
  return true;
}
bool nc::show_body(int x,int y){
  if (my_mvprintw(y,x,"%c",BODY) == ERR)
    return false;
  return true;
}
bool nc::show_food(int x,int y){
  if (my_mvprintw(y,x,"%c",FOOD) == ERR)
    return false;
  //mvprintw(my,0,"");
  return true;
}
bool nc::print(){
  my_refresh();
  return true;
}
void nc::graphic_quit(){
  my_endwin();
}
void nc::play_sound(){
  my_beep();
}
e_event nc::event(){
  int c = my_getch();
  switch(c){
    case KEY_RIGHT:
      return RIGHT;
      break;
    case KEY_LEFT:
      return LEFT;
      break;
    case 27:
      return ECHAPS;
      break;
    default:
      return NOTHING;
    }
}
IGraphic::~IGraphic(){}
nc::nc(){}
nc::~nc(){}
extern "C" IGraphic *getInstance(){
  return ((IGraphic *)new nc());
}
