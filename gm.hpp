#ifndef GM_HPP_INCLUDED
#define GM_HPP_INCLUDED

#include<string>
#include<vector>

#include"widget.hpp"


class gm{
protected:
    std::vector<std::vector<widget*>> w;
    std::vector<widget*> static_obj;
public:
    void jatek();
};

#endif // GM_HPP_INCLUDED
