#include "Exercise32.h"

#include <math.h>
#include <sstream>
#include <set>

using namespace std;

void Exercise32::Solve()
{
  long long result;
  set<long long> possibilities;
  long long sum = 0;
  for(long long i = 1;i<=9999;i++)
  {    
    long long j = 1;
    bool cont = true;
    do
    {
	result = i * j;
	  stringstream iss;
	  iss<<i<<j<<result;
	  string str = iss.str();	
	int sizeStr = str.size();
	if (sizeStr == 9)
	{	 
	  if (HasChar(str,'1') && HasChar(str,'2')&& HasChar(str,'3')&& HasChar(str,'4')&& HasChar(str,'5')&& HasChar(str,'6')&& HasChar(str,'7')&& HasChar(str,'8')&& HasChar(str,'9'))
	  {	      
	      if (possibilities.insert(result).second)
	      {
		cout<<"New Pandigital product : "<<i<<" x "<<j<<" = "<<result<<endl;	  
		sum+= result;
	      }
	  }
	}
	else if (sizeStr > 9)
	  cont = false;	  	
	j++;
    }while(cont);    
  }
  
  cout<<"The sum of all pandigital products is "<<sum<<endl;
}

bool Exercise32::IsPandigital(long long multiplicand,long long multiplier,long long product)
{
  stringstream iss;
  iss<<multiplicand<<multiplier<<product;
  string str = iss.str();
  return HasChar(str,'1') && HasChar(str,'2')&& HasChar(str,'3')&& HasChar(str,'4')&& HasChar(str,'5')&& HasChar(str,'6')&& HasChar(str,'7')&& HasChar(str,'8')&& HasChar(str,'9');
}

bool Exercise32::HasChar(string str, char value)
{
  size_t found = str.find(value);
  return (found!=string::npos);
}

void Exercise32::SetDefaultValues()
{

}

Exercise32::Exercise32()
{

}

Exercise32::~Exercise32()
{

}

