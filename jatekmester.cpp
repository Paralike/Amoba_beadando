
#include"jatekmester.hpp"

#include <vector>

jatekmester::jatekmester(int meret){

    for(int i=0; i<meret; i++)
    {
        std::vector<int>tempw;
        for(int j=0; j<meret; j++)
        {
            tempw.push_back(0);
        }
        palya.push_back(tempw);
    }
}

bool telipalya()
{
    bool teli=true;
    //std::cout << teli << std::endl;
 /*   for(size_t i=0; i<palya.size(); i++)
        for(size_t j=0; j<palya.size(); j++)
            if(palya[j][i]==0)
                teli=false;
*/
    return teli;
}
