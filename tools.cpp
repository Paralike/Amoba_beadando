#include<string>
#include<vector>


#include"tools.hpp"
#include"graphics.hpp"


tools::tools(int nagysag)
{
    /*c = new checkbox(5,10,30,30);
    w.push_back(c);*/

    for(int i=0; i<nagysag; i++)
    {
        std::vector<int >tempw;
        for(int j=0; j<nagysag; j++)
        {
            tempw.push_back(new checkbox(5+30*j,10+30*i,30,30));
        }
        d.push_back(tempg);
    }
    /*for(int i=0; i<=nagysag;i++)
        for(int j=0; j<=nagysag;j++){
            //w[j][i]=new checkbox(5+30*j,10+30*i,30,30);
            w.push_back(new checkbox(5+30*j,10+30*i,30,30));
        }*/

}
