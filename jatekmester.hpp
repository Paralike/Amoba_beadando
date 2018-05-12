#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include<vector>


class jatekmester{
    std::vector<std::vector<int>> palya;
public:
jatekmester(int);
void palyairo(int, int, int);
int palyaallapot(int, int);
bool telipalya();
void szabalyfigyelo(int, int,int,int&);
};

#endif // JATEKMESTER_HPP_INCLUDED
