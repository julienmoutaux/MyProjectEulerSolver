#include "PandigitalTool.h"

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

PandigitalTool::PandigitalTool(int max,int min)
{
  _target = 1;  
    if (max < min)
    {
        _min = max;
        _max = min;
    }
    else
    {
        _min = min;
        _max = max;
    }
    _inf = 0;
    _sup = 0;
    if (_min == 0)
        _inf = pow10(_max - _min);
    for(int i = _max; i >= _min; --i)
    {
        _sup = _sup*10+i;
        if (_min !=0)
            _inf=_inf*10 + (_max-i+1);
    }
    InitValArray();
}

void PandigitalTool::BeginPandigitalConstruction()
{
  _target ++;
}

list<long long> PandigitalTool::BuildAllPandigitals()
{
  list<int> availableValues;
  list<long long> allValues;
  long long currentValue = 0;
  for(int i = _min;i<=_max;i++)
    availableValues.push_back(i);
  RecursiveBuildPandigitalList(availableValues,&allValues,currentValue);
  return allValues;
}

void PandigitalTool::RecursiveBuildPandigitalList(list<int> availableValues, list<long long> * allValues,long long currentValue)
{   
  long long tempValue;
  for(list<int>::iterator iter = availableValues.begin();iter != availableValues.end();++iter)
  {
    int value = *iter;
    list<int> availableValues2 ;
    for(list<int>::iterator iter2 = availableValues.begin();iter2 != availableValues.end();++iter2)
      if ((*iter2) != (*iter))
	availableValues2.push_back(*iter2);    
    tempValue = currentValue*10 + value;
    if (tempValue != 0)
    {
      if( availableValues2.size() ==0)      
	allValues->push_back(tempValue);      
      else
	RecursiveBuildPandigitalList(availableValues2,allValues,tempValue);    
    }
  }
}

 bool PandigitalTool::AddToPandigitalConstuction(long long value)
 {
   return AddToArray(value);
 }
 
 bool PandigitalTool::IsPandigitalComplete()
 {
   for(int i = _min;i<=_max;++i)
     if (_val[i] != _target)
       return false;
    return true;
 }
 
 int PandigitalTool::IsPandigitalCandidate(long long value)
 {
   BeginPandigitalConstruction();
   if (!AddToPandigitalConstuction(value))
     return -1;
   return IsPandigitalCandidate();
 }
 
int PandigitalTool::IsPandigitalCandidate()
{
    int pos = -1;
    for ( int i = _min; i<=_max; ++i )
        if ( _val[i] != _target)
	{
	  if (pos == -1)
	     pos = i-1;
	}
        else if ( pos >= 0 ) //Deja un trou, pas pandigital
            return -1;
    if ( pos == -1 )
        return _max;
    return pos;
}
 bool PandigitalTool::AddToArray(long long value)
 {
   int val;
    int length = 1;
    while (value !=0)
    {
        val = value % 10;
        if (_val[val] == _target)
            return false;
	_val[val] = _target;
        value /= 10;
	if (val < _min || val > _max)
	  return false;
    }
    return true;
 }

PandigitalTool::~PandigitalTool()
{
}

bool PandigitalTool::IsPandigital(long long value)
{
    if ((value < _inf) || (value > _sup))
        return false;
    InitValArray();
    //long long remaind = value;
    return AddToArray(value);
    /*int val;
    int length = 1;
    while (value !=0)
    {
        val = value % 10;
        if ((++_val[val]) > 1)
            return false;
        value /= 10;
	if (val < _min || val > _max)
	  return false;
    }
    /*bool inRange;
    for(int i = 10; i>0;)
    {
        val = _val[--i];
        inRange = (i >= _min) && (i<= _max);
        if (val != inRange)
            return false;
    }*/
    return true;
}

void PandigitalTool::InitValArray()
{
    for(int i =10; i>0;)
        _val[--i] = 0;
}

void PandigitalTool::Print(bool withEndl)
{
    cout<<"Pandigital from "<<_min<<" to "<<_max;
    if (withEndl)
        cout<<endl;
}

int PandigitalTool::getMin()
{
    return _min;
}
int PandigitalTool::getMax()
{
    return _max;
}

long long PandigitalTool::getSup()
{
    return _sup;
}
long long PandigitalTool::getInf()
{
    return _inf;
}