#include "PandigitalTool.h"

#include <iostream>
#include <cmath>

using namespace std;

PandigitalTool::PandigitalTool(int max,int min)
{
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
}

void PandigitalTool::BeginPandigitalConstruction()
{
  InitValArray();
}

 bool PandigitalTool::AddToPandigitalConstuction(long long value)
 {
   return AddToArray(value);
 }
 
 bool PandigitalTool::IsPandigitalComplete()
 {
   for(int i = _min;i<=_max;++i)
     if (!_val[i])
       return false;
    return true;
 }
 
 bool PandigitalTool::AddToArray(long long value)
 {
   int val;
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