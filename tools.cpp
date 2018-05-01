#include<string>
#include<vector>


#include"tools.hpp"
#include"graphics.hpp"


tools::tools()
{
    /*c = new checkbox(5,10,30,30);
    w.push_back(c);*/
    for(int i=1; i<16;i++)
    {
        for(int j=1; j<16;i++)
        {
            c = new checkbox(5*j,10*i,30,30);
            w.push_back(c);
        }
    }

}
