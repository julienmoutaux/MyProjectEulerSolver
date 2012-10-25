#include "Exercise39.h"

#include <cmath>

void Exercise39::Solve()
{
  int borneMax = 1000;
  map<int,int> values = BuildSqrableValues(borneMax);
  
  int results[borneMax];
  int posMax = 0;
  int valMax = 0;
  for(int i = 0;i<borneMax;i++)
    results[i] = 0;
  
  int powA,powB;
  map<int,int>::iterator iter;
  int pos,val;
  
  for(int a = 1;a<=borneMax;a++)
  {
    powA = a*a;
    for(int b = a;b<=borneMax;b++)
    {
      powB = b*b;
      iter = values.find(powA + powB);
      if (iter != values.end())
      {
	int perim = iter->second + a + b;
	if (perim <= 1000)
	{
	  pos = perim-1;
	  val = ++(results[pos]);
	  if (val > valMax)
	  {
	    valMax = val;
	    posMax = perim;
	  }
	}
      }
    }
  }
  cout<<"I found "<<valMax<<" different 3-tuple for p = "<<posMax<<endl;
}

map<int,int> Exercise39::BuildSqrableValues(int borneSup)
{
  map<int,int> toReturn;
  double sup =borneSup;
  
  for(int i =1;i<=sup;i++)
  {
    toReturn[i*i] = i;
  }
  return toReturn;
}

void Exercise39::SetDefaultValues()
{

}

void Exercise39::AskForParams()
{
    AbstractSolver::AskForParams();
}

Exercise39::Exercise39()
{

}

Exercise39::~Exercise39()
{

}

