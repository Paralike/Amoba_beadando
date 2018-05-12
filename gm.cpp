#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>

#include "graphics.hpp"
#include "gm.hpp"
#include "jatekmester.hpp"

using namespace genv;



void gm::jatek()
{
    //std::cout <<"a"<<std::endl;
    jatekmester felugyelo(w.size());

    gout.open(XX,YY);
    event ev;
    int kivalasztottelemi=-1;
    int kivalasztottelemj=-1;
    //bool te=true; //kapcsoló ahoz hogy a lenyíló ablak egy ütemmel le legyen maradva és ezáltal ne nyissa meg az alatta lévõ widgetet ha a lenyíló ablak ütközne azzal
    /*for (widget * wg : w)
        wg->rajzol();*/
    for(size_t i=0; i<w.size(); i++)
        for(size_t j=0; j<w.size(); j++)
            w[j][i]->rajzolallapottal(felugyelo.palyaallapot(j,i));
    for (size_t i=0; i<3; i++)
        static_obj[i]->rajzol();
    //int counterplayer1=0;
    //int counterplayer2=0;
    //bool nyert=false;
    while(gin >> ev && ev.keycode!=key_escape)
    {

        /*if(ev.type == ev_mouse && ev.button==btn_left || (ev.button==btn_wheelup||ev.button==btn_wheeldown))
            for(widget * wg:w)
                if(wg->getkijelolve())
                    wg->markival(ev);
        */
        if(ev.type == ev_key && ev.keycode==key_f5)
        {
            //std::cout << "a" <<std::endl;
            //nyert=false;
            //teli=false;
            felugyelo.figyelo_allito("jatekosfigyelo",false);
            felugyelo.figyelo_allito("jatekosfigyelo2",false);
            felugyelo.torolnyert();
            //counterplayer1=0;
            //counterplayer2=0;
            felugyelo.torlo();
            /*for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                {
                    w[j][i]->beallito(0);
                }*/
            gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);
            for(size_t i=0; i<w.size(); i++)
                for(size_t j=0; j<w.size(); j++)
                    w[j][i]->rajzolallapottal(felugyelo.palyaallapot(j,i));
            for (size_t i=0; i<3; i++)
                static_obj[i]->rajzol();

        }
        //std::cout << nyert <<std::endl;
        if(!felugyelo.getnyert() && !felugyelo.telipalya())
        {
            if(ev.type == ev_mouse && ev.button==btn_left)
            {
                //Játékos
                if(!felugyelo.korfigyelo(" "))
                {
                    for(size_t i=0; i<w.size(); i++)
                        for(size_t j=0; j<w.size(); j++)
                            if(w[j][i]->ertekel(ev.pos_x,ev.pos_y))
                            {
                                kivalasztottelemi=i;
                                kivalasztottelemj=j;
                                felugyelo.figyelo_allito("jatekosfigyelo",true);
                            }

                    if(kivalasztottelemi!=-1&&felugyelo.palyaallapot(kivalasztottelemj,kivalasztottelemi)!=0)
                    {
                        kivalasztottelemi=-1;
                        kivalasztottelemj=-1;
                        felugyelo.figyelo_allito("jatekosfigyelo",false);
                    }

                    /*for(size_t i=0; i<w.size(); i++)
                        if(w[i]->ertekel(ev.pos_x,ev.pos_y))
                            kivalasztottelem=i;*/
                    //w[kivalasztottelem]->gombreac([=]() {w[0]->markival(ev);});
                    if(kivalasztottelemi!=-1)
                    {
                        felugyelo.palyairo(kivalasztottelemj,kivalasztottelemi,1);
                        //w[kivalasztottelemj][kivalasztottelemi]->beallito(1);
                        w[kivalasztottelemj][kivalasztottelemi]->gombreac();
                        gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);

                        felugyelo.szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,1);
                        //teli=felugyelo.telipalya();
                        //std::cout << counterplayer1<<std::endl;
                        /*if(counterplayer1>=5)
                            nyert=true;*/
                    }
                }
                if(!felugyelo.getnyert()&&!felugyelo.telipalya()&&felugyelo.korfigyelo(" "))
                {
                    for(size_t i=0; i<w.size(); i++)
                        for(size_t j=0; j<w.size(); j++)
                            if(w[j][i]->ertekel(ev.pos_x,ev.pos_y))
                            {
                                kivalasztottelemi=i;
                                kivalasztottelemj=j;
                                felugyelo.figyelo_allito("jatekosfigyelo",false);
                            }

                    if(kivalasztottelemi!=-1&&felugyelo.palyaallapot(kivalasztottelemj,kivalasztottelemi)!=0)
                    {
                        kivalasztottelemi=-1;
                        kivalasztottelemj=-1;
                        felugyelo.figyelo_allito("jatekosfigyelo",true);
                    }

                    if(kivalasztottelemi!=-1)
                    {
                        felugyelo.palyairo(kivalasztottelemj,kivalasztottelemi,2);
                        w[kivalasztottelemj][kivalasztottelemi]->gombreac();
                        //gout << move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<color(255,255,255);

                        //w[kivalasztottelemj][kivalasztottelemi]->beallito(2);
                        felugyelo.szabalyfigyelo(kivalasztottelemj,kivalasztottelemi,2);
                        //teli=felugyelo.telipalya();
                        //std::cout << counter<<std::endl;
                        /*if(counterplayer2>=5)
                            nyert=true;*/
                    }

                }
            }



            if(kivalasztottelemj!=-1)
            {
                w[kivalasztottelemj][kivalasztottelemi]->kap(ev);
                for(size_t i=0; i<w.size(); i++)
                    for(size_t j=0; j<w.size(); j++)
                        w[j][i]->rajzolallapottal(felugyelo.palyaallapot(j,i));

                for (size_t i=0; i<3; i++)
                    static_obj[i]->rajzol();
                //w[kivalasztottelemj][kivalasztottelemi]->rajzol();
            }
            felugyelo.figyelo_allito("jatekosfigyelo2",felugyelo.korfigyelo("jatekosfigyelo"));
        }
        if(felugyelo.getnyert())
        {
            if(felugyelo.palyaallapot(kivalasztottelemj, kivalasztottelemi)==1)
                static_obj[3]->rajzol();
            if(felugyelo.palyaallapot(kivalasztottelemj, kivalasztottelemi)==2)
                static_obj[4]->rajzol();
        }
        if(felugyelo.telipalya())
            static_obj[5]->rajzol();

        gout << refresh;
    }
}

