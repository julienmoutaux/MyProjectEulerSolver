#include "Exercise48.h"

#include "Tools.h"

#include <math.h>

Exercise48::Exercise48()
:AbstractSolver(true)
{

}

Exercise48::~Exercise48()
{

}

void Exercise48::SetDefaultValues()
{
  _maxSerie = 1000;
  _length = 10;
  cout<<"Resolve for a serie of"<<_maxSerie<<" and a result truncate at "<<_length<<" chars"<<endl;  
}

void Exercise48::AskForParams()
{  
    _maxSerie = Tools::Cin::GetValue<long long> ( "What is the length of the serie ?",1000 );
    _length = Tools::Cin::GetValue<long long> ( "What is the length of the result ?",10 );
}

void Exercise48::Solve()
{
  long long result=0;
  long long temp;
  long long filter = pow10(_length);
  for (int i =1;i <= _maxSerie;i++)
  {
    temp = 1;   
    for (int j= 1;j<=i;j++)
    {
      temp *=i;
      temp %= filter;      
    }    
    result += temp;
    result %= filter;    
  }
  cout<<"My result is "<<result<<endl;
  
}
