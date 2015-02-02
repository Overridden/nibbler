#include "nc_lib.hh"
WINDOW *nc_lib::my_initscr(){return initscr();}
int nc_lib::my_erase(){return erase();}
int nc_lib::my_cbreak(){return cbreak();}
int nc_lib::my_keypad(WINDOW *w, bool b){return keypad(w,b);}
int nc_lib::my_noecho(){return noecho();}
int nc_lib::my_nodelay(WINDOW *w, bool b){return nodelay(w,b);}
int nc_lib::my_curs_set(int c){return curs_set(c);}
int nc_lib::my_beep(){return beep();}
int nc_lib::my_endwin(){return endwin();}
int nc_lib::my_refresh(){return refresh();}
int nc_lib::my_getch(){return getch();}
int nc_lib::my_mvprintw(int y,int x,const char *fmt,char a){
  return mvprintw(y, x, fmt, a);
}
//nc_lib::nc_lib(){}
//nc_lib::~nc_lib(){}
