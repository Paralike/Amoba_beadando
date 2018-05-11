#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include"widget.hpp"
#include<string>
class stattex : public widget
{
protected:
    std::string _kijelzo;
public:
    stattex(int x, int y, int sx, int sy, std::string);
    //string szov;
    void rajzol();
    bool ertekel(int, int) {return false;};
    void kap(genv::event) {};
} ;

#endif // STATICTEXT_HPP_INCLUDED
