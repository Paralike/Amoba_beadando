#include <iostream>


#include "graphics.hpp"
#include "tools.hpp"
#include "widget.hpp"

using namespace std;
//using namespace genv;

int main()
{
    /*gout.open(800,800);
    event ev;
    while(gin>>ev){
        gout<<text("asd")<<refresh;
    }*/
    tools amoba(10); // a pálya nagysága mindenképp nxn-es
    amoba.jatek();

    return 0;
}
