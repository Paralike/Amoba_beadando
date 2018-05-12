#include "nyomogomb.hpp"

#include "graphics.hpp"

#include<vector>
#include<iostream>
#include<string>


using namespace genv;

nyomogomb::nyomogomb(int x, int y, int szelesseg, int magassag, std::string f,std::function <void()> functor):widget(x,y,szelesseg,magassag)
{
    felirat=f;
    _functor=functor;
}

void nyomogomb::rajzol()
{
    if(_kijelolve)
    {
        gout << move_to(_x,_y)<<color(255,255,150)<<box(_length,_height);
        gout << move_to(_x+10,_y+_height*0.75)<<color(0,0,0)<<text(felirat);
    }
    else
    {
        gout << move_to(_x,_y)<<color(255,255,255)<<box(_length,_height);
        gout << move_to(_x+10,_y+_height*0.75)<<color(0,0,0)<<text(felirat);
    }

}
bool nyomogomb::ertekel(int egerx, int egery)
{
    if(egerx>_x && egerx<_x+_length && egery>_y && egery<_y+_height)
        _kijelolve=true;
    else
        _kijelolve=false;
    return _kijelolve;
}

void nyomogomb::gombreac(){
    _functor();
}

/*refresh::refresh(int x, int y, int szelesseg, int magassag, std::string f, tools* par):nyomogomb(x,y,szelesseg,magassag,f)
{
    _parent=par;
}

void refresh::gombreac()
{


    if(*_parent->k1->getactual()!="--"&&*_parent->k2->getactual()!="--")
        _parent->k3->sete(_parent->k1->getactual(),_parent->k2->getactual());
    int index;

    std::vector<std::string> emasolat=_parent->k1->gete();
    for(size_t i=0; i<emasolat.size(); i++)
        if(emasolat[i]==*_parent->k1->getactual())
            index=i;
    std::cout<<index<<std::endl;
    _parent->k1->torole(index);

    emasolat=_parent->k2->gete();
    for(size_t i=0; i<emasolat.size(); i++)
        if(emasolat[i]==*_parent->k2->getactual())
            index=i;
    std::cout<<index<<std::endl;
    _parent->k2->torole(index);
}
*/
