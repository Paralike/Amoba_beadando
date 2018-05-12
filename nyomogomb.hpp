#ifndef NYOMOGOMB_HPP_INCLUDED
#define NYOMOGOMB_HPP_INCLUDED

#include<string>
#include<functional>

#include"widget.hpp"
#include "tools.hpp"

class tools;

class nyomogomb : public widget{
protected:
    std::string felirat;
    std::function<void()> _functor;
public:
    nyomogomb(int, int, int, int,std::string, std::function<void()>);
    void rajzol();
    bool ertekel(int, int);
    void kap(genv::event){};
    void markival(genv::event){};
    void gombreac();
    //void gombreac(std::function<void(*)>& func);
};
/*
class refresh : public nyomogomb{
    tools* _parent;
public:
    refresh(int, int, int, int, std::string, tools*);
    void gombreac();
};

*/

#endif // NYOMO_GOMB_H_INCLUDED
