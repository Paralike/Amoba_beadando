#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>

#include "graphics.hpp"
#include "gm.hpp"
#include "jatekmester.hpp"

using namespace genv;

void szabalyfigyelo(int, int, std::vector<std::vector<widget*>>,int,int&);
bool telipalya(std::vector<std::vector<widget*>>);

void gm::jatek()
{
    //std::cout <<"a"<<std::endl;
//    jatekmester felugyelo(w.size());

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
    for (size_t i=0; i<3; i++)
        static_obj[i]->rajzol();
    int counterplayer1=0;
    int counterplayer2=0;
    bool nyert=false;
    bool teli=false;
    bool jatekosfigyelo=false; //false = player1 true = player 2
    bool jatekosfigyelo2=false; //false = player1 true = player 2 1 utemet hagy az egészre rá hogy ne léjenek egymásra, egy ütemen bellül
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
            jatekosfigyelo=false;
            jatekosfigyelo2=false;
            counterplayer1=0;
            counterplayer2=0;
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                {
                    w[j][i]->beallito(0);
                }
            gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                    w[j][i]->rajzol();
            for (size_t i=0; i<3; i++)
                static_obj[i]->rajzol();

        }
        //std::cout << nyert <<std::endl;
        if(!nyert && !teli)
        {
            if(ev.type == ev_mouse && ev.button==btn_left)
            {
                //Játékos
                if(!jatekosfigyelo2)
                {
                    for(size_t i=0; i<w.size(); i++)
                        for(size_t j=0; j<w.size(); j++)
                            if(w[j][i]->ertekel(ev.pos_x,ev.pos_y))
                            {
                                kivalasztottelemi=i;
                                kivalasztottelemj=j;
                                jatekosfigyelo=true;
                            }

                    if(kivalasztottelemi!=-1&&w[kivalasztottelemj][kivalasztottelemi]->getallapot()!=0)
                    {
                        kivalasztottelemi=-1;
                        kivalasztottelemj=-1;
                        jatekosfigyelo=false;
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

                        szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,w,1,counterplayer1);
                        teli=telipalya(w);
                        //std::cout << counterplayer1<<std::endl;
                        if(counterplayer1>=5)
                            nyert=true;
                    }
                }
                if(!nyert&&!teli&&jatekosfigyelo2)
                {
                    for(size_t i=0; i<w.size(); i++)
                        for(size_t j=0; j<w.size(); j++)
                            if(w[j][i]->ertekel(ev.pos_x,ev.pos_y))
                            {
                                kivalasztottelemi=i;
                                kivalasztottelemj=j;
                                jatekosfigyelo=false;
                            }

                    if(kivalasztottelemi!=-1&&w[kivalasztottelemj][kivalasztottelemi]->getallapot()!=0)
                    {
                        kivalasztottelemi=-1;
                        kivalasztottelemj=-1;
                        jatekosfigyelo=true;
                    }

                    /*do
                    {
                        kivalasztottelemj=rand()%(w.size());
                        kivalasztottelemi=rand()%(w.size());
                    }
                    while(w[kivalasztottelemj][kivalasztottelemi]->getallapot()!=0);
                    //std::cout << kivalasztottelemj<<" "<<kivalasztottelemi<<std::endl;
                    //std::cout << kivalasztottelem<<std::endl;*/

                    if(kivalasztottelemi!=-1)
                    {
                        w[kivalasztottelemj][kivalasztottelemi]->beallito(1);
                        w[kivalasztottelemj][kivalasztottelemi]->gombreac();
                        //gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);

                        w[kivalasztottelemj][kivalasztottelemi]->beallito(2);
                        szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,w,2,counterplayer2);
                        teli=telipalya(w);
                        //std::cout << counter<<std::endl;
                        if(counterplayer2>=5)
                            nyert=true;
                    }

                }
            }



            if(kivalasztottelemj!=-1)
            {
                w[kivalasztottelemj][kivalasztottelemi]->kap(ev);
                for(size_t i=0; i<w.size(); i++)
                    for(size_t j=0; j<w.size(); j++)
                        w[j][i]->rajzol();
                for (size_t i=0; i<3; i++)
                    static_obj[i]->rajzol();
                //w[kivalasztottelemj][kivalasztottelemi]->rajzol();
            }
            jatekosfigyelo2=jatekosfigyelo;
        }
        if(counterplayer1>=5)
        {
            static_obj[3]->rajzol();
        }
        if(counterplayer2>=5)
        {
            static_obj[4]->rajzol();
        }
        gout << refresh;
    }
}

void szabalyfigyelo(int aktualislepes_j,int aktualislepes_i,std::vector<std::vector<widget*>> w, int szemely,int &counter)
{
    //std::cout << w.size() << std::endl;
    counter=0;
    //függőleges vonal
    int maxi=0;
    for(size_t i=0; i<w.size(); i++)
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
    for(size_t i=0; i<w.size(); i++)
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
        for(size_t aktualisj=aktualislepes_j-aktualislepes_i; aktualisj<w.size(); aktualisj++)
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
        for(size_t aktualisi=aktualislepes_i-aktualislepes_j+1; aktualisi<w.size(); aktualisi++)
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
        for(size_t i=1; i<w.size(); i++)
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
    for(size_t i=0; i<w.size(); i++)
        for(size_t j=0; j<w.size(); j++)
            if(w[j][i]->getallapot()==0)
                teli=false;

    return teli;
}


