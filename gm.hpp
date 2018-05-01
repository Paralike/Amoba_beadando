#ifndef GM_HPP_INCLUDED
#define GM_HPP_INCLUDED

#include<string>
#include<vector>

#include"widget.hpp"


class gm{
protected:
    std::vector<widget*> w;
public:
    //virtual void esemeny(std::string tortenes);
    void jatek();
};

#endif // GM_HPP_INCLUDED
