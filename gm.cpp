#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>

#include "graphics.hpp"
#include "gm.hpp"

using namespace genv;

void szabalyfigyelo(int, int, std::vector<std::vector<widget*>>,int,int&);
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
    //std::cout <<"a"<<std::endl;
    gout.open(XX,YY);
    event ev;
    int kivalasztottelemi=-1;
    int kivalasztottelemj=-1;
    //bool te=true; //kapcsoló ahoz hogy a lenyíló ablak egy ütemmel le legyen maradva és ezáltal ne nyissa meg az alatta lévõ widgetet ha a lenyíló ablak ütközne azzal
    /*for (widget * wg : w)
        wg->rajzol();*/
    for(size_t i=0; i<w.size(); i++)
        for(size_t j=0; j<w.size(); j++)
            w[j][i]->rajzol();
    int counter=0;
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
            //Játékos
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                    if(w[j][i]->ertekel(ev.pos_x,ev.pos_y))
                    {
                        kivalasztottelemi=i;
                        kivalasztottelemj=j;
                    }
            /*for(size_t i=0; i<w.size(); i++)
                if(w[i]->ertekel(ev.pos_x,ev.pos_y))
                    kivalasztottelem=i;*/
            //w[kivalasztottelem]->gombreac([=]() {w[0]->markival(ev);});
            w[kivalasztottelemj][kivalasztottelemi]->beallito(1);
            w[kivalasztottelemj][kivalasztottelemi]->gombreac();
            if(kivalasztottelemj!=-1&&kivalasztottelemj!=-1)
                gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);

            szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,w,1,counter);
            std::cout << counter<<std::endl;
            //Ai
            do
            {
                kivalasztottelemj=rand()%(w.size());
                kivalasztottelemi=rand()%(w.size());
            }
            while(w[kivalasztottelemj][kivalasztottelemi]->getallapot()!=0);
            //std::cout << kivalasztottelemj<<" "<<kivalasztottelemi<<std::endl;
            //std::cout << kivalasztottelem<<std::endl;
            w[kivalasztottelemj][kivalasztottelemi]->beallito(2);

            szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,w,2,counter);
            //std::cout << counter<<std::endl;
            counter=0;
        }

        //játékmester


        if(kivalasztottelemj!=-1)
        {
            w[kivalasztottelemj][kivalasztottelemi]->kap(ev);
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                    w[j][i]->rajzol();
            w[kivalasztottelemj][kivalasztottelemi]->rajzol();
        }
        gout << refresh;
    }
}

void szabalyfigyelo(int aktualislepes_j,int aktualislepes_i,std::vector<std::vector<widget*>> w, int szemely,int &counter)
{
    int maxi=0;
    for(int i=1;i<w.size();i++)
    {
        if(w[i-1][aktualislepes_i]->getallapot()==szemely)
        maxi++;
        if(w[i-1][aktualislepes_i]->getallapot()!=szemely)

    }
    if(maxi>counter)
        counter=maxi;
        /*do{
        counter++;
        }while( !(w[aktualislepes_j+1*counter][aktualislepes_i]->getallapot()==szemely &&aktualislepes_j+1<=w.size()) ||counter!=5);*/

    /*if(w[aktualislepes_j+1][aktualislepes_i]->getallapot()==szemely&&aktualislepes_j+1<=w.size())
    {
        counter++;
    }
    else if(w[aktualislepes_j-1][aktualislepes_i]->getallapot()==szemely&&aktualislepes_j-1>=w.size())
    {
        counter++;
    }
    else if(w[aktualislepes_j][aktualislepes_i+1]->getallapot()==szemely&&aktualislepes_i+1<=w.size())
    {
        counter++;
    }
    else if(w[aktualislepes_j][aktualislepes_i-1]->getallapot()==szemely&&aktualislepes_i-1<=w.size())
    {
        counter++;
    }
    else if(w[aktualislepes_j+1][aktualislepes_i+1]->getallapot()==szemely&&aktualislepes_i+1<=w.size()&&aktualislepes_j+1<=w.size())
    {
        counter++;
    }
    else if(w[aktualislepes_j-1][aktualislepes_i-1]->getallapot()==szemely&&aktualislepes_i-1>=w.size()&&aktualislepes_j-1>=w.size())
    {
        counter++;

    }
    else if(w[aktualislepes_j+1][aktualislepes_i-1]->getallapot()==szemely&&aktualislepes_j+1<=w.size()&&aktualislepes_i-1>=w.size())
    {
        counter++;

    }
    else if(w[aktualislepes_j-1][aktualislepes_i+1]->getallapot()==szemely&&aktualislepes_i+1<=w.size()&&aktualislepes_j-1>=w.size())
    {
        counter++;
    }*/
}
