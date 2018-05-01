#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class checkbox : public widget {
    bool allapot;
public:
    checkbox(int x, int y, int magassag, int szelesseg);
    virtual void rajzol() ;
    virtual bool ertekel(int, int, int& );
    void kap(genv::event ev){};
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
