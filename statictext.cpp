#include "statictext.hpp"
#include <string>
#include "iostream"


stattex::stattex(int x, int y, int sx, int sy,std::string kij ): widget(x,y,sx,sy){
    _kijelzo=kij;

}

void stattex::rajzol() {
     genv::gout << genv::move_to(_x, _y) << genv::color(0,0,0) <<genv::box(_height,_length)<<genv::move_to(_x+5,_y+5)<<genv::color(255,255,255) << genv::text(_kijelzo);
}

