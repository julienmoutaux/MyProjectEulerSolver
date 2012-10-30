#include "Exercise41.h"

#include "PandigitalTool.h"
#include <PrimeTool.h>

int Exercise41::firstPrimes[] = {3,5,7,11,13,17,19,23,29,31};

void Exercise41::Solve()
{
    PandigitalTool pandigital ( 9 );
    PrimeTool prime ( "resources/primeList.txt" );
    int n;
    for ( long long i=pandigital.getSup(); i >0; --i )
    {
        if ( IsFastPrime ( i ) && ( n=pandigital.IsPandigitalCandidate ( i ) ) != -1 )
        {
            cout<<"largest "<<n<<"-digit pandigital prime existing : "<<i<<endl;
            if ( prime.IsPseudoPrime ( i,1000 ) )
                return;
            else
                cout<<"But is not prime..."<<endl;
        }
    }
}

void Exercise41::SetDefaultValues()
{

}

bool Exercise41::IsFastPrime ( long long value )
{
    if ( ( value % 2 ) == 0 )
        return false;
    for ( int i = 9; i>=0; --i )
        if ( ( value%firstPrimes[i] ) == 0 )
            return false;
    return true;
}



