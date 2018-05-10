#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>

#include "graphics.hpp"
#include "gm.hpp"

using namespace genv;

void szabalyfigyelo(int, int, std::vector<std::vector<widget*>>,int,int&);
bool telipalya(std::vector<std::vector<widget*>>);

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
    bool nyert=false;
    bool teli=false;
    while(gin >> ev && ev.keycode!=key_escape)
    {

        /*if(ev.type == ev_mouse && ev.button==btn_left || (ev.button==btn_wheelup||ev.button==btn_wheeldown))
            for(widget * wg:w)
                if(wg->getkijelolve())
                    wg->markival(ev);
        */
        //tesztfuggveny();
        if(ev.type == ev_key && ev.keycode==key_f5)
        {
            //std::cout << "a" <<std::endl;
            nyert=false;
            teli=false;
            counter=0;
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                {
                    w[j][i]->beallito(0);
                }
            gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                    w[j][i]->rajzol();
        }
        //std::cout << nyert <<std::endl;
        if(!nyert && !teli)
        {
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

                if(kivalasztottelemi!=-1&&w[kivalasztottelemj][kivalasztottelemi]->getallapot()!=0)
                {
                    kivalasztottelemi=-1;
                    kivalasztottelemj=-1;
                }

                /*for(size_t i=0; i<w.size(); i++)
                    if(w[i]->ertekel(ev.pos_x,ev.pos_y))
                        kivalasztottelem=i;*/
                //w[kivalasztottelem]->gombreac([=]() {w[0]->markival(ev);});
                if(kivalasztottelemi!=-1)
                {
                    w[kivalasztottelemj][kivalasztottelemi]->beallito(1);
                    w[kivalasztottelemj][kivalasztottelemi]->gombreac();
                    gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);

                    szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,w,1,counter);
                    teli=telipalya(w);
                    std::cout << counter<<std::endl;
                    if(counter>=5)
                        nyert=true;

                    //Ai
                    if(!nyert&&!teli)
                    {
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
                        teli=telipalya(w);
                        //std::cout << counter<<std::endl;
                        counter=0;
                    }
                }
            }



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
}

void szabalyfigyelo(int aktualislepes_j,int aktualislepes_i,std::vector<std::vector<widget*>> w, int szemely,int &counter)
{
    //std::cout << w.size() << std::endl;
    counter=0;
    //függőleges vonal
    int maxi=0;
    for(int i=0; i<w.size(); i++)
    {
        /*if(w[i][aktualislepes_i]->getallapot()==szemely)
            maxi++;*/
        if(w[i][aktualislepes_i]->getallapot()==szemely)
            maxi++;
        if(counter<maxi)
            counter=maxi;
        if(w[i][aktualislepes_i]->getallapot()!=szemely)
            maxi=0;

    }
    //vízszíntes vonal
    maxi=0;
    for(int i=0; i<w.size(); i++)
    {
        if(w[aktualislepes_j][i]->getallapot()==szemely)
            maxi++;
        if(counter<maxi)
            counter=maxi;
        if(w[aktualislepes_j][i]->getallapot()!=szemely)
            maxi=0;
    }
    //balról jobbra lefell menő átló
    maxi=0;
    if(aktualislepes_j>aktualislepes_i)
    {
        //int aktualisj=aktualislepes_j-aktualislepes_i+1;
        int aktualisi=0;
        for(int aktualisj=aktualislepes_j-aktualislepes_i; aktualisj<w.size(); aktualisj++)
        {

            if(w[aktualisj][aktualisi]->getallapot()==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(w[aktualisj][aktualisi]->getallapot()!=szemely)
                maxi=0;
            aktualisi++;
            //aktualisj++;
        }
    }
    else if(aktualislepes_j<=aktualislepes_i)
    {
        int aktualisj=0+1;
        for(int aktualisi=aktualislepes_i-aktualislepes_j+1; aktualisi<w.size(); aktualisi++)
        {
            if(aktualisi==w.size()-1&&w[aktualisj][aktualisi]->getallapot()==szemely)
                maxi++;
            if(w[aktualisj-1][aktualisi-1]->getallapot()==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(w[aktualisj-1][aktualisi-1]->getallapot()!=szemely)
                maxi=0;
            aktualisj++;
            //aktualisj++;
        }
    }
    else
    {
        /*int aktualisj=0+1;
        int aktualisi=0+1;*/
        for(int i=1; i<w.size(); i++)
        {
            if(w[i-1][i-1]->getallapot()==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(w[i-1][i-1]->getallapot()!=szemely)
                maxi=0;
            //aktualisj++;
        }
    }

    //balról jobbra felfelé menő átló
    maxi=0;
    int aktualisi=aktualislepes_i;
    int aktualisj=aktualislepes_j;
    /*std::cout << aktualisi<<" "<<aktualisj <<std::endl;
    std::cout <<std::endl;*/
    while(aktualisj>0&&aktualisi<w.size())
    {
        aktualisj--;
        aktualisi++;
    }
    aktualisj++;
    aktualisi--;
    /*std::cout << aktualisi<<" "<<aktualisj <<std::endl;
    std::cout <<std::endl;*/
    /*std::cout << aktualisj <<" "<<aktualisi<<std::endl;
    std::cout <<std::endl;*/
    if(aktualisi+aktualisj<w.size())
    {
        for(aktualisi; aktualisi>=0; aktualisi--)
        {
            if(aktualisi==0 && w[aktualisj][aktualisi]->getallapot()==szemely)
                maxi++;
            if(w[aktualisj-1][aktualisi+1]->getallapot()==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(w[aktualisj-1][aktualisi+1]->getallapot()!=szemely)
                maxi=0;
            aktualisj++;
        }
    }
    else
    {
        aktualisi--;
        aktualisj++;
        for(aktualisj; aktualisj<w.size(); aktualisj++)
        {
            //std::cout << aktualisj <<" "<<aktualisi<<std::endl;
            if(aktualisj==w.size()-1&&w[aktualisj][aktualisi]->getallapot()==szemely)
                maxi++;
            if(w[aktualisj-1][aktualisi+1]->getallapot()==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            //std::cout << maxi<<std::endl;
            if(w[aktualisj-1][aktualisi+1]->getallapot()!=szemely)
                maxi=0;
            //std::cout << aktualisj <<" "<<aktualisi<<std::endl;
            //std::cout << aktualisj-1 <<" "<<aktualisi+1<<std::endl;
            aktualisi--;
        }
        //std::cout<<std::endl;
    }

}

bool telipalya(std::vector<std::vector<widget*>> w)
{
    bool teli=true;
    //std::cout << teli << std::endl;
    int i=0;
    int j=0;
    for(size_t i=0; i<w.size(); i++)
        for(size_t j=0; j<w.size(); j++)
            if(w[j][i]->getallapot()==0)
                teli=false;

    return teli;
}
