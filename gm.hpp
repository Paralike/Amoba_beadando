#ifndef GM_HPP_INCLUDED
#define GM_HPP_INCLUDED

#include<string>
#include<vector>

#include"widget.hpp"

#include "jatekmester.hpp"

class jatekmester;

class gm{
protected:
    std::vector<std::vector<widget*>> w;
    std::vector<widget*> static_obj;
    jatekmester* felu;
public:
    void frissit(jatekmester);
    void jatek();
    jatekmester* getfelu(){return felu;};
};

#endif // GM_HPP_INCLUDED
