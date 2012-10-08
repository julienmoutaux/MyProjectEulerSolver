#include "Exercise35.h"

#include "PrimeTool.h"
#include <math.h>
#include "Tools.h"
#include <list>

using namespace std;

void Exercise35::Solve()
{
    int cpt = 0;
    PrimeTool prime( "resources/primeList.txt" );
    list<long long> candidates = prime.GetListOfPrimesTo(_max);
    cout<<"Test of "<<candidates.size()<<" elements"<<endl;
    for(list<long long>::iterator iter = candidates.begin();iter != candidates.end();iter++)
    {
        int rotation = (*iter);
        if (prime.IsPrime(rotation))
        {
            bool cont = true;
            do
            {
                rotation = Rotate(rotation);
                cont = prime.IsPrime(rotation);
            } while(rotation != (*iter) && cont);
            if (cont)            
                cpt++;
        }
    }
    cout<<cpt<<" circular primes found until "<<_max<<endl;
}

int Exercise35::Rotate(int value)
{
    int len = -1;
    int remaind = value;
    do
    {
        len++;
        remaind/=10;
    } while(remaind >0);
    int ret = value/10;
    int num = value%10;
    return ret + num * pow10(len);
}

void Exercise35::SetDefaultValues()
{
    _max= 1000000;
    cout<<"Using values until "<<_max<<endl;
}

void Exercise35::AskForParams()
{
    _max = Tools::Cin::GetValue<int> ( "What is the maximum values to test ?",1000000 );
}

Exercise35::Exercise35()
    :AbstractSolver(true)
{

}

Exercise35::~Exercise35()
{

}

