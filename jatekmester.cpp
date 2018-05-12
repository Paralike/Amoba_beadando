
#include"jatekmester.hpp"

#include <vector>
#include <iostream>

jatekmester::jatekmester(int meret){

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

    bool teli=true;

    //std::cout << palya.size() << std::endl;
    for(size_t i=0; i<palya.size(); i++)
        for(size_t j=0; j<palya.size(); j++)
            if(palya[j][i]==0)
                teli=false;

    return teli;
}

int jatekmester::palyaallapot(int j, int i){
    return palya[j][i];
}
