#include <Exercise31.h>
#include <Tools.h>

int Exercise31::_coins[8] ={200,100,50,20,10,5,2,1};
int Exercise31::_nbCoins = 8;

void Exercise31::SetDefaultValues()
{
  _value = 200;
  cout<<"Trying to dispatch "<<_value<<" pence"<<endl;
}

Exercise31::Exercise31()
:AbstractSolver(true)
{

}

Exercise31::~Exercise31()
{

}

void Exercise31::AskForParams()
{
  _value = Tools::Cin::GetValue<int> ( "How many pence to dispatch ?",200);
}

void Exercise31::Solve()
{
  for(int i = 0;i<_nbCoins;i++)
  {    
    if (_coins[i] <= _value)
    {
      cout<<"There are "<<Recurse(i,_value)<<" combinations"<<endl;
      return;
    }
  }
  cout<<"Impossible to solve"<<endl;
}

int Exercise31::Recurse(int pos,int remain)
{
  int toReturn = 0;
  for(int i = pos;i<_nbCoins;i++)
  {
    if (_coins[i] < remain)          
      toReturn += Recurse(i,remain - _coins[i]);    
    else if (_coins[i] == remain)          
      toReturn++;    
  }
  return toReturn;
}