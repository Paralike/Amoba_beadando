#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include<vector>
#include<string>


class jatekmester{
    std::vector<std::vector<int>> palya;
    bool jatekosfigyelo=false; //false = player1 true = player 2
    bool jatekosfigyelo2=false; //false = player1 true = player 2 1 utemet hagy az egészre rá hogy ne léjenek egymásra, egy ütemen bellül
public:
jatekmester(int);
void palyairo(int, int, int);
int palyaallapot(int, int);
bool telipalya();
void szabalyfigyelo(int, int,int,int&);
bool korfigyelo(std::string);
void figyelo_allito(std::string,bool);
};

#endif // JATEKMESTER_HPP_INCLUDED
