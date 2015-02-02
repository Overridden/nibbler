#ifndef NC_LIB_HH__
#define NC_LIB_HH__
#include <ncurses.h>

class nc_lib{
public:
  WINDOW *my_initscr();
  int my_erase();
  int my_cbreak();
  int my_keypad(WINDOW *, bool);
  int my_noecho();
  int my_nodelay(WINDOW *, bool);
  int my_curs_set(int);
  int my_mvprintw(int,int,const char *, char a);
  int my_beep();
  int my_endwin();
  int my_refresh();
  int my_getch();
};

#endif
