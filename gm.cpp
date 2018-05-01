#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>

#include "graphics.hpp"
#include "gm.hpp"

using namespace genv;

void szabalyfigyelo(int);
void tesztfuggveny()
{
    std::vector<std::vector<int>> d;
    for(int i=0; i<5; i++)
    {
        std::vector<int >tempg;
        for(int j=0; j<5; j++)
        {
            tempg.push_back(j);
            //g.push_back(j);
        }
        d.push_back(tempg);
    }
    d[1][1]=5;
    std::cout << d[1][1] <<std::endl;
    for(size_t i=0; i<d.size(); i++)
    {
        for(size_t j=0; j<d.size(); j++)
        {
            std::cout <<d[j][i]<<" ";
        }
        std::cout <<std::endl;
    }
}

void gm::jatek()
{
    std::cout <<"a"<<std::endl;
    gout.open(XX,YY);
    event ev;
    int kivalasztottelem=-1;
    //bool te=true; //kapcsoló ahoz hogy a lenyíló ablak egy ütemmel le legyen maradva és ezáltal ne nyissa meg az alatta lévõ widgetet ha a lenyíló ablak ütközne azzal
    /*for (widget * wg : w)
        wg->rajzol();*/
    for(size_t i=0; i<w.size(); i++)
    {
        for(size_t j=0; j<w.size(); j++)
        {
            w[j][i]->rajzol()
        }
    }
    while(gin >> ev && ev.keycode!=key_escape)
    {

        /*if(ev.type == ev_mouse && ev.button==btn_left || (ev.button==btn_wheelup||ev.button==btn_wheeldown))
            for(widget * wg:w)
                if(wg->getkijelolve())
                    wg->markival(ev);
        */
        //tesztfuggveny();
        if(ev.type == ev_mouse && ev.button==btn_left)
        {
            for(size_t i=0; i<w.size(); i++)
                if(w[i]->ertekel(ev.pos_x,ev.pos_y))
                    kivalasztottelem=i;
            //w[kivalasztottelem]->gombreac([=]() {w[0]->markival(ev);});
            w[kivalasztottelem]->beallito(1);
            w[kivalasztottelem]->gombreac();
            if(kivalasztottelem!=-1)
                gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);
            std::cout << kivalasztottelem<<std::endl;
            szabalyfigyelo(kivalasztottelem);
            //Ai
            do
            {
                kivalasztottelem=rand()%(w.size());
            }
            while(w[kivalasztottelem]->getallapot()!=0);

            std::cout << kivalasztottelem<<std::endl;
            w[kivalasztottelem]->beallito(2);

            szabalyfigyelo(kivalasztottelem);
        }

        //játékmester


        if(kivalasztottelem!=-1)
        {
            //std::cout << w[1]->getterjeszkedve()<<std::endl;
            //w[kivalasztottelem]->gombreac([&](){w[0]->setertek(0);});
            //if(!te)
            w[kivalasztottelem]->kap(ev);
            for (widget * wg : w)
                wg->rajzol();
            w[kivalasztottelem]->rajzol();
        }
        gout << refresh;
    }
}

void szabalyfigyelo(int aktualislepes)
{

}
