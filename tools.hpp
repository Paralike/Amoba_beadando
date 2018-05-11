#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

#include "gm.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "checkbox.hpp"
#include "statictext.hpp"

#include<vector>
#include<iostream>
#include<fstream>
#include <string>
#include <functional>

class checkbox;
class stattex;

class tools: public gm
{
    stattex* s1;
    stattex* s2;
    stattex* s3;
    stattex* s4;
    stattex* s5;
    public:
    tools(int);

};

#endif // TOOLS_HPP_INCLUDED
