#include <Exercise27.h>

#include "Tools.h"
#include <PrimeTool.h>

Exercise27::Exercise27()
    :AbstractSolver ( true )
{
}

Exercise27::~Exercise27()
{
    //dtor
}

void Exercise27::AskForParams()
{
    cout<<"n² + an + b"<<endl;
    _aMax = Tools::Cin::GetValue<int> ( "What is the maximum value for |a| ?",1000 );
    _bMax = Tools::Cin::GetValue<int> ( "What is the maximum value for |b| ?",1000 );
}

void Exercise27::SetDefaultValues()
{
    _aMax = 1000;
    _bMax = 1000;
    cout<<"n² + an + b with |a| < "<<_aMax<<" and |b| < "<<_bMax<<endl;
}

void Exercise27::Solve()
{
    PrimeTool prime ( "resources/primeList.txt" );
    int maxSize = 0;
    int cpt;
    int aValue = 0,bValue = 0;
    for ( int a = - ( _aMax-1 ); a<_aMax; a++ )
        for ( int b = - ( _bMax-1 ); b<_bMax; b++ )
        {
            cpt=0;
            while ( prime.IsPrime ( Evaluate (cpt,a,b ) ) )
	      cpt++;
	    cpt--;                
            if ( cpt > maxSize )
            {
                aValue = a;
                bValue = b;
                maxSize = cpt;
            }
        }

    cout<<"a : "<<aValue<<" b : "<<bValue<<" length  "<<maxSize<<endl;
    cout<<"a * b ="<<aValue * bValue<<endl;
}

long Exercise27::Evaluate ( int n,int a,int b )
{
  return n*n + a*n + b;
}
