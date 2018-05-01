#include "graphics.hpp"
#include "widget.hpp"

#include<iostream>

widget::widget(int x, int y, int magassag, int szelesseg)//:_x(x),_y(y),_length(magassag),_height(szelesseg)
{
    this ->_x=x;
    this ->_y=y;
    this ->_height=magassag;
    this ->_length=szelesseg;
    _kijelolve=false;
}
bool widget::getkijelolve(){return _kijelolve;}

int widget::getertek() {return ertek;}

std::string *widget::getactual() {return actual;}

bool widget::getterjeszkedve(){return terjeszkedve;}

int widget::getallapot(){return allapot;}

//void widget::setertek(int ert){ertek=ert;}
