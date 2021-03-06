#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include<string>
#include <functional>
#include<vector>


const int XX=800;
const int YY=800;

class widget {
protected:
    int _x,_y,_length, _height;
    bool _kijelolve;
    int ertek;
    std::string actual[2];
    bool terjeszkedve; //a widgeten kívül csinál-e valamit ami miatt blokkolhatja egyik a másikat
    int allapot; //ha 1 akkor a felhasználóé ha 2 akkor a gépé
public:
    widget(int x, int y, int length,int height);
    virtual bool ertekel(int egerx, int egery)=0;
    virtual void rajzol() = 0;
    virtual void kap(genv::event ev) = 0;
    virtual void setkijelolve(bool kij){};
    virtual bool getkijelolve();
    virtual void markival(genv::event ev){};
    virtual int getertek();
    virtual std::string* getactual();
    virtual bool getterjeszkedve();
    virtual void gombreac(){};
    //virtual void setertek(int ert);
    virtual void sete(std::string*,std::string*){}; //e a kivalasztott vectorbeli elemek egy tombje
 //   virtual std::vector<std::string> gete(){};
    virtual void torole(int){};
    virtual void beallito(int){};
    virtual int getallapot();
    //csak ehhez a feladathoz
    virtual void rajzolallapottal(int){};
};

#endif // WIDGET_HPP_INCLUDED
