#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

checkbox::checkbox(int x, int y, int szelesseg, int magassag):widget(x,y,szelesseg,magassag)
{
    _kijelolve=false;
}

void checkbox::rajzol()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_length, _height);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_length-4, _height-4);
    if (_kijelolve) {
        gout << color(255,255,255);
        gout << move_to(_x+4, _y+4) << line(_length-8, _height-8);
        gout << move_to(_x+5, _y+4) << line(_length-8, _height-8);
        gout << move_to(_x+_length-4, _y+4) << line(-_length+8, _height-8);
        gout << move_to(_x+_length-5, _y+4) << line(-_length+8, _height-8);
    }
}

bool checkbox::ertekel(int egerx, int egery,int& kivalasztottelem)
{
    if(egerx>(_x)&&egerx<(_x+_length)&&egery>_y&&egery<(_y+_height))
        _kijelolve=true;
    else
        _kijelolve=false;
    return egerx>(_x)&&egerx<(_x+_length)&&egery>_y&&egery<(_y+_height);
}
