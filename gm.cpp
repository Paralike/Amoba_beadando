#include<fstream>
#include<iostream>

#include "graphics.hpp"
#include "gm.hpp"

using namespace genv;


void gm::jatek()
{
    std::cout <<"a"<<std::endl;
    gout.open(XX,YY);
    event ev;
    int kivalasztottelem=-1;
    //bool te=true; //kapcsoló ahoz hogy a lenyíló ablak egy ütemmel le legyen maradva és ezáltal ne nyissa meg az alatta lévõ widgetet ha a lenyíló ablak ütközne azzal
    while(gin >> ev && ev.keycode!=key_escape)
    {

        for (widget * wg : w)
        wg->rajzol();
        if(ev.type == ev_mouse && ev.button==btn_left || (ev.button==btn_wheelup||ev.button==btn_wheeldown))
            for(widget * wg:w)
                if(wg->getkijelolve())
                    wg->markival(ev);

        if(ev.type == ev_mouse && ev.button==btn_left)
        {
            for(size_t i=0; i<w.size(); i++)
                if(w[i]->ertekel(ev.pos_x,ev.pos_y,kivalasztottelem))
                    kivalasztottelem=i;
            //w[kivalasztottelem]->gombreac([=]() {w[0]->markival(ev);});
            w[kivalasztottelem]->gombreac();
            if(kivalasztottelem!=-1)
                gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);
        }
        if(kivalasztottelem!=-1)
        {
            //std::cout << w[1]->getterjeszkedve()<<std::endl;
            //w[kivalasztottelem]->gombreac([&](){w[0]->setertek(0);});
            //if(!te)
                w[kivalasztottelem]->kap(ev);

            //te=w[kivalasztottelem]->getterjeszkedve();
            for (widget * wg : w)
                wg->rajzol();
            w[kivalasztottelem]->rajzol();
        }
        gout << refresh;
    }
}
