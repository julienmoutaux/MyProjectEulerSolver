#include "Exercise37.h"

#include "PrimeTool.h"

#include <math.h>
#include <list>

void Exercise37::Solve()
{
    PrimeTool prime ( "resources/primeList.txt" );
    list<long long> primes = prime.GetListOfPrimesTo(pow10(6));
    
    int nbCand = 0;
    long long sum = 0;
    
    list<long long>::iterator iter = primes.begin();
    while ((*iter) <10) iter++;
    for(;iter != primes.end();iter++)
    {
      bool isOk = true;
      long long remaind = (*iter)/10;
      long long size = 1;
      while (remaind>0 && isOk)
      {
	isOk = prime.IsPrime(remaind);
	remaind /=10;
	size++;
      }
      if (isOk)
      {
	for(long long i=1;i<size && isOk;i++)
	{
	  isOk = prime.IsPrime((*iter)%((long long)pow10(i)));
	}
      }
      if (isOk)
      {
	cout<<"A new candidate was found : "<<(*iter)<<endl;
	sum += (*iter);
	nbCand++;
      }
    }
    cout<<nbCand<<" candidates found. Sum of all these elements : "<<sum<<endl;
}

void Exercise37::SetDefaultValues()
{

}

Exercise37::Exercise37()
{

}

Exercise37::~Exercise37()
{

}

