#ifndef NC_HH__
#define NC_HH__

#include <ncurses.h>
#include "nc_lib.hh"
#include "../IGraphic.hh"

class nc : public IGraphic, public nc_lib{
public:
nc();
~nc();
    virtual e_event event();
    virtual bool init_game(int,int);
    virtual bool show_map(int,int);
    virtual bool show_head(int,int);
    virtual bool show_body(int,int);
    virtual bool show_food(int,int);
    virtual bool print();
    virtual void graphic_quit();
    virtual void play_sound();
private:
};

#endif
