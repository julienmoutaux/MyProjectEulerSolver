#include "Exercise3.h"

#include "PrimeTool.h"
#include "Tools.h"
#include <math.h>

Exercise3::Exercise3():
    AbstractSolver(true)
{
    //ctor
}

Exercise3::~Exercise3()
{
    //dtor
}

void Exercise3::AskForParams()
{
    _number = Tools::Cin::GetValue<long long>("For which value do you want to know the maximum prime?",600851475143);
}

void Exercise3::Solve()
{
    PrimeTool * primes = new PrimeTool("resources/primeList.txt");
    long long max = sqrt(_number)+1;
    cerr<<"Finding primes until "<<max<<endl;
    list<long long> pf = primes->GetListOfPrimesTo(max);
    cerr<<pf.size()<<" primes found"<<endl;
    for(list<long long>::reverse_iterator iter = pf.rbegin();iter != pf.rend();iter++)
        if (!(_number%(*iter)))
        {
            cerr<<"The largest prime factor of "<<_number<<" is "<<*iter<<endl;
            break;
        }

    delete primes;
}

void Exercise3::SetDefaultValues()
{
    _number = 600851475143;
    cout<<"Finding the maximum prime of"<<_number<<endl;
}
