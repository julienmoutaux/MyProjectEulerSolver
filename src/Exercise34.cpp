#include "Exercise34.h"

#include <math.h>

int Exercise34::_maxFacto = 10;
long long * Exercise34::_factorials = NULL;

void Exercise34::Solve()
{
    if (_factorials == NULL)
        BuildListOfFactorials();

    for (int i = 0; i<_maxFacto; i++)
        cout<<i<<"="<<_factorials[i]<<" ";
    cout<<endl;
    
    /*
    for (int i1=0;i1<10;i1++)
      for (int i2=0;i2<10;i2++)
	for (int i3=0;i3<10;i3++)
	  for (int i4=0;i4<10;i4++)
	    for (int i5=0;i5<10;i5++)
	      for (int i6=0;i6<10;i6++)
		for (int i7=0;i7<10;i7++)
		  for (int i8=0;i8<10;i8++)
		{
		  long long val = i1 + i2*10 + i3*100 + i4 * 1000 + i5 * 10000 + i6 * 100000 + i7 * 1000000 + i8 * 10000000; 
		  //if (val > 2)
		  {
		    if (val == (_factorials[i1] + _factorials[i2] + _factorials[i3] + _factorials[i4] + _factorials[i5] + _factorials[i6] + _factorials[i7] + _factorials[i8]))
		      cout<<"Candidate "<<val<<endl;
		  }
		}*/

    long long sizeMax = _factorials[9]*7;

    cout<<"estimated sizeMax = "<<sizeMax<<endl;

    long long sum;
    for(long long i = 3; i<=sizeMax; i++)
    {
        sum = GetSumOfFactorials(i);
        if (i == sum)
            cout<<"new candidate : "<<i<<" result "<<sum<<endl;
    }
   
}

long long Exercise34::GetSumOfFactorials(long long value)
{
    if (value == 40585)
        int a = 0;
    long long sum2 = 0;
    long long remaind = value;
    int val;
    while(remaind >0)
    {
        val = remaind%10;
        sum2+=_factorials[val];
        if (sum2 > value)
            return -1;
        remaind/=10;
    }
    return sum2;
}

void Exercise34::BuildListOfFactorials()
{
    _factorials = new long long[_maxFacto]();
    _factorials[0] = 1;
    _factorials[1] = 1;
    for(int i = 2; i<_maxFacto; i++)
    {
        _factorials[i] = i * _factorials[i-1];
    }
}

void Exercise34::SetDefaultValues()
{

}

Exercise34::Exercise34()
{

}

Exercise34::~Exercise34()
{

}

