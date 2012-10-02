#include "Exercise29.h"

#include <set>

#include "PrimeTool.h"
#include "Tools.h"

using namespace std;

Exercise29::Exercise29()
    :AbstractSolver(true)
{
    //ctor
}

Exercise29::~Exercise29()
{
    //dtor
}


void Exercise29::AskForParams()
{
    _maxA = Tools::Cin::GetValue<int>("What is the maximum value for A ?",100);
    _maxB = Tools::Cin::GetValue<int>("What is the maximum value for B ?",100);
}

void Exercise29::SetDefaultValues()
{
    _maxA = 100;
    _maxB = 100;
    cout<<"Solving for values max a = "<<_maxA<<" and b ="<<_maxB<<endl;
}
void Exercise29::Solve()
{
    PrimeTool primes("resources/primeList.txt");
    set<string> values;
    for(int a = 2; a<=_maxA; a++)
        for(int b = 2; b<=_maxB; b++)
            values.insert(primes.WriteToPrimeFactor(a,b));
    cout<<"We have "<<values.size()<<" different values for 'a' between 2 and "<<_maxA<<" and 'b' between 2 and "<<_maxB<<endl;
}
