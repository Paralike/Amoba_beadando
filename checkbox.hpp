#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class checkbox : public widget {

public:
    checkbox(int x, int y, int magassag, int szelesseg);
    virtual void rajzol() ;
    virtual bool ertekel(int, int );
    void kap(genv::event ev){};
    void beallito(int);

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
