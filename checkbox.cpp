#include "checkbox.hpp"
#include "graphics.hpp"

#include<cmath>
using namespace genv;

checkbox::checkbox(int x, int y, int szelesseg, int magassag):widget(x,y,szelesseg,magassag)
{
    _kijelolve=false;
    allapot=0;
}

/*void checkbox::rajzol()
{

    gout << move_to(_x, _y) << color(255,255,255) << box(_length, _height);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_length-4, _height-4);
    //if(_kijelolve)
        if (allapot==1)
        {
            gout << color(255,255,255);
            gout << move_to(_x+4, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+5, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+_length-4, _y+4) << line(-_length+8, _height-8);
            gout << move_to(_x+_length-5, _y+4) << line(-_length+8, _height-8);
        }
        else if(allapot==2)
        {
            gout << color(255,0,0);
            gout << move_to(_x+4, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+5, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+_length-4, _y+4) << line(-_length+8, _height-8);
            gout << move_to(_x+_length-5, _y+4) << line(-_length+8, _height-8);
        }
}
*/
bool checkbox::ertekel(int egerx, int egery)
{
    if(egerx>(_x)&&egerx<(_x+_length)&&egery>_y&&egery<(_y+_height))
    {
        _kijelolve=true;
        //allapot=szemely;
    }
    /*else
        _kijelolve=false;*/
    return egerx>(_x)&&egerx<(_x+_length)&&egery>_y&&egery<(_y+_height);
}

void checkbox::beallito(int szemely){
    allapot=szemely;
}

void checkbox::rajzolallapottal(int birtokos){
    int keret=2;
    int xkezd=4;
gout << move_to(_x, _y) << color(255,255,255) << box(_length, _height);
    gout << move_to(_x+keret, _y+keret) << color(0,0,0) << box(_length-keret*2, _height-keret*2);
    //if(_kijelolve)
        if (birtokos==1)
        {
            gout << color(255,255,255);
            gout << move_to(_x+xkezd, _y+xkezd) << line(_length-xkezd*2, _height-xkezd*2);
            gout << move_to(_x+xkezd+1, _y+xkezd) << line(_length-xkezd*2, _height-xkezd*2);
            gout << move_to(_x+_length-xkezd, _y+xkezd) << line(-_length+xkezd*2, _height-xkezd*2);
            gout << move_to(_x+_length-xkezd+1, _y+xkezd) << line(-_length+xkezd*2, _height-xkezd*2);
        }
        else if(birtokos==2)
        {
            gout << color(255,0,0);
            /*for(int x=keret;x<x+_length-keret*2;x++){
                for(int y=keret;y<y+_height-keret*2;y++)
                    if(round(sqrt(pow(_x-x,2)+pow(_y-y,2)))<=1)
                        gout<<dot;
            }*/

            gout << move_to(_x+4, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+5, _y+4) << line(_length-8, _height-8);
            gout << move_to(_x+_length-4, _y+4) << line(-_length+8, _height-8);
            gout << move_to(_x+_length-5, _y+4) << line(-_length+8, _height-8);
        }
}
