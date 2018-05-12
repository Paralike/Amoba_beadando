#include<string>
#include<vector>


#include"tools.hpp"


tools::tools(int nagysag)
{
    /*c = new checkbox(5,10,30,30);
    w.push_back(c);*/
    mer=nagysag;
    for(int i=0; i<nagysag; i++)
    {
        std::vector<widget* >tempw;
        for(int j=0; j<nagysag; j++)
        {
            tempw.push_back(new checkbox(5+30*j,100+30*i,30,30));
        }
        w.push_back(tempw);
    }
    s1 = new stattex(10,30,50,30,"player1: Feher");
    s2 = new stattex(150,30,50,30,"player2: Piros");
    s3 = new stattex(300,30,50,30,"Uj jatek: F5");
    s4 = new stattex(150,70,50,30,"Player1 nyert");
    s5 = new stattex(150,70,50,30,"Player2 nyert");
    s6 = new stattex(150,70,50,30,"Dontetlen");
    g1 = new nyomogomb(370,40,30,80,"refresh",[this](){this->reaction(1);});
    static_obj.push_back(s1);
    static_obj.push_back(s2);
    static_obj.push_back(s3);
    static_obj.push_back(g1);
    static_obj.push_back(s4);
    static_obj.push_back(s5);
    static_obj.push_back(s6);



    /*for(int i=0; i<=nagysag;i++)
        for(int j=0; j<=nagysag;j++){
            //w[j][i]=new checkbox(5+30*j,10+30*i,30,30);
            w.push_back(new checkbox(5+30*j,10+30*i,30,30));
        }*/

}


void tools::reaction(int i){
    if(i==1)
    {
        jatekmester* felugyelo=getfelu();
        felugyelo->figyelo_allito("jatekosfigyelo",false);
            felugyelo->figyelo_allito("jatekosfigyelo2",false);
            felugyelo->torolnyert();
            felugyelo->torlo();


    }
}
