#include "Exercise30.h"

#include <Tools.h>
#include <math.h>

Exercise30::Exercise30()
:AbstractSolver(true)
{
}

Exercise30::~Exercise30()
{

}

void Exercise30::SetDefaultValues()
{
_size = 5;
cout<<"Using power "<<_size<<endl;
}

void Exercise30::AskForParams()
{
 _size = Tools::Cin::GetValue<int> ( "Wich power do you want to use ?",4);
}

void Exercise30::Solve()
{
  long sum = 0;
  int max = pow10(_size+2);
  for(int i = 10/*//*pow10(_size-1)*/;i<max;i++)  
  {  
    if (i == Evaluate(i))
    {
      cout<<"another solution found :"<<i<<endl;
      sum+=i;
    }  
  }
  cout<<"the sum of all elements is "<<sum<<endl;
}

int Exercise30::Evaluate(int value)
{
  int remaind = value;
  int toReturn = 0;
  for(int i = _size+2;i>=0;--i)
  {
    int power = pow10(i);
    int val = remaind / power;    
    toReturn += pow(val,_size);   
    remaind = remaind % power;
  }  
  return toReturn;
}