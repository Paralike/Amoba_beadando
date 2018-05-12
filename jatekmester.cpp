#include"jatekmester.hpp"

#include <vector>
#include <iostream>
#include <string>

jatekmester::jatekmester(int meret)
{

    for(int i=0; i<meret; i++)
    {
        std::vector<int>tempw;
        for(int j=0; j<meret; j++)
            tempw.push_back(0);
        palya.push_back(tempw);
    }
}

void jatekmester::palyairo(int j, int i,int szemely)
{
    palya[j][i]=szemely;
}

bool jatekmester::telipalya()
{

    teli=true;
    for(size_t i=0; i<palya.size(); i++)
        for(size_t j=0; j<palya.size(); j++)
            if(palya[j][i]==0)
                teli=false;

    return teli;
}

int jatekmester::palyaallapot(int j, int i)
{
    return palya[j][i];
}

void jatekmester::szabalyfigyelo(int aktualislepes_j,int aktualislepes_i, int szemely)
{
    //std::cout << w.size() << std::endl;
    int counter=0;
    //függőleges vonal
    int maxi=0;
    for(size_t i=0; i<palya.size(); i++)
    {
        /*if(w[i][aktualislepes_i]->getallapot()==szemely)
            maxi++;*/
        if(palya[i][aktualislepes_i]==szemely)
            maxi++;
        if(counter<maxi)
            counter=maxi;
        if(palya[i][aktualislepes_i]!=szemely)
            maxi=0;

    }
    //vízszíntes vonal
    maxi=0;
    for(size_t i=0; i<palya.size(); i++)
    {
        if(palya[aktualislepes_j][i]==szemely)
            maxi++;
        if(counter<maxi)
            counter=maxi;
        if(palya[aktualislepes_j][i]!=szemely)
            maxi=0;
    }
    //balról jobbra lefell menő átló
    maxi=0;
    if(aktualislepes_j>aktualislepes_i)
    {
        //int aktualisj=aktualislepes_j-aktualislepes_i+1;
        int aktualisi=0;
        for(size_t aktualisj=aktualislepes_j-aktualislepes_i; aktualisj<palya.size(); aktualisj++)
        {

            if(palya[aktualisj][aktualisi]==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(palya[aktualisj][aktualisi]!=szemely)
                maxi=0;
            aktualisi++;
            //aktualisj++;
        }
    }
    else if(aktualislepes_j<=aktualislepes_i)
    {
        int aktualisj=0+1;
        for(size_t aktualisi=aktualislepes_i-aktualislepes_j+1; aktualisi<palya.size(); aktualisi++)
        {
            if(aktualisi==palya.size()-1&&palya[aktualisj][aktualisi]==szemely)
                maxi++;
            if(palya[aktualisj-1][aktualisi-1]==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(palya[aktualisj-1][aktualisi-1]!=szemely)
                maxi=0;
            aktualisj++;
            //aktualisj++;
        }
    }
    else
    {
        /*int aktualisj=0+1;
        int aktualisi=0+1;*/
        for(size_t i=1; i<palya.size(); i++)
        {
            if(palya[i-1][i-1]==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(palya[i-1][i-1]!=szemely)
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
    while(aktualisj>0&&aktualisi<palya.size())
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
    if(aktualisi+aktualisj<palya.size())
    {
        for(aktualisi; aktualisi>=0; aktualisi--)
        {
            if(aktualisi==0 && palya[aktualisj][aktualisi]==szemely)
                maxi++;
            if(palya[aktualisj-1][aktualisi+1]==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            if(palya[aktualisj-1][aktualisi+1]!=szemely)
                maxi=0;
            aktualisj++;
        }
    }
    else
    {
        aktualisi--;
        aktualisj++;
        for(aktualisj; aktualisj<palya.size(); aktualisj++)
        {
            //std::cout << aktualisj <<" "<<aktualisi<<std::endl;
            if(aktualisj==palya.size()-1&&palya[aktualisj][aktualisi]==szemely)
                maxi++;
            if(palya[aktualisj-1][aktualisi+1]==szemely)
                maxi++;
            if(counter<maxi)
                counter=maxi;
            //std::cout << maxi<<std::endl;
            if(palya[aktualisj-1][aktualisi+1]!=szemely)
                maxi=0;
            //std::cout << aktualisj <<" "<<aktualisi<<std::endl;
            //std::cout << aktualisj-1 <<" "<<aktualisi+1<<std::endl;
            aktualisi--;
        }
        //std::cout<<std::endl;
    }
    if(counter>=5)
        nyert=true;
    else
        nyert=false;
}

bool jatekmester::korfigyelo(std::string le)
{
    if(le=="jatekosfigyelo")
        return jatekosfigyelo;
    else
        return jatekosfigyelo2;
}

void jatekmester::figyelo_allito(std::string mit,bool mire)
{
    if(mit=="jatekosfigyelo")
        jatekosfigyelo=mire;
    if(mit=="jatekosfigyelo2")
        jatekosfigyelo2=mire;
}

void jatekmester::torlo()
{
    for(size_t i=0; i<palya.size(); i++)
        for(size_t j=0; j<palya.size(); j++)
            palya[j][i]=0;
}

bool jatekmester::getnyert()
{
    return nyert;
}

void jatekmester::torolnyert(){
    nyert=false;
}
