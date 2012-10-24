#include "Exercise38.h"

#include <sstream>
#include <cmath>
#include "PandigitalTool.h"

void Exercise38::Solve()
{
  int maxCandidate,maxN;
  long long tempResult,maxResult = 0;
    PandigitalTool pandigital;
    PandigitalTool oldPandigital;
    for(int i = 1;i<99999;++i)
    {
      pandigital.BeginPandigitalConstruction();
      oldPandigital.BeginPandigitalConstruction();
      if (pandigital.AddToPandigitalConstuction(i))
      {
	oldPandigital.AddToPandigitalConstuction(i);
	for(int j = 2;j<7;++j)
	{
	  long long newValue = i*j;
	  if (pandigital.AddToPandigitalConstuction(newValue))
	    oldPandigital.AddToPandigitalConstuction(newValue);
	  else if (oldPandigital.IsPandigitalComplete())
	  {
	    tempResult = GetValue(i,j-1);
	    if (tempResult > maxResult)
	    {
	      maxCandidate = i;
	      maxN = j-1;
	      maxResult = tempResult;
	    }
	    //cout<<"New candidate : i = "<<i<<" and n = "<<j-1<<" Value : "<<GetValue(i,j-1)<<endl;
	    break;
	  }
	  else
	    break;
	}
      }
    }
    cout<<"The max value is "<<maxResult<<" using candidate = "<<maxCandidate<<" N = "<<maxN<<endl; 
}

long long Exercise38::GetValue(long long candidate, int n)
{
  stringstream ss;
  for(int i = 1;i<=n;++i)
    ss<<(candidate*i);
  istringstream iss(ss.str());
  long long value;
  iss>>value;
  return value;
}

void Exercise38::SetDefaultValues()
{

}

Exercise38::Exercise38()
{

}

Exercise38::~Exercise38()
{

}

