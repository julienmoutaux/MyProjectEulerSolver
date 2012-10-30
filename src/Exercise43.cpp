#include "Exercise43.h"

#include <PandigitalTool.h>
#include <cmath>

int Exercise43::PrimeArray[] = {1,1,2,3,5,7,11,13,17};
long long Exercise43::Coef[10];

void Exercise43::Solve()
{
  BuildCoefArray();  
  PandigitalTool tool(0,9);
  long long sum = 0;  
  cout<<"Building pandigital list"<<endl;
  list<long long> myList = tool.BuildAllPandigitals();
  cout<<"Ok the list is build now searching sum"<<endl;
  for(list<long long>::iterator iter = myList.begin();iter != myList.end();++iter)
  {
    if (HasDivisibilityProperty(*iter))
    {
      cout<<"Adding "<<(*iter)<<endl;
      sum+= (*iter);
    }
  }
  cout<<"the sum of sub-string divisible pandigital values is "<<sum<<endl;
}

void Exercise43::BuildCoefArray()
{
  for(int i = 0;i<10;++i)  
    Coef[9-i] = pow10(i);     
}

int Exercise43::GetPart(long long value, int i)
{  
 value %= Coef[i-2];
 return value / Coef[i+1] ;
}

bool Exercise43::HasDivisibilityProperty(long long value)
{
  for(int i = 2;i<=8;++i)
  {    
    if (GetPart(value,i)%PrimeArray[i] != 0)
      return false;
  }
  return true;
}

void Exercise43::SetDefaultValues()
{

}



