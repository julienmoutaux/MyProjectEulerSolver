#include "Exercise26.h"

#include <list>
#include <set>

Exercise26::Exercise26()
{
}

Exercise26::~Exercise26()
{
    //dtor
}

     string Exercise26::GetName()
     {
         return "Exercise 26";
     }
     bool Exercise26::HasParams()
     {
         return true;
     }

void Exercise26::AskForParams()
{
    _nbMax = 1000;
    _nbMin = 2;
}

void Exercise26::SetDefaultValues()
{
    _nbMax = 1000;
    _nbMin = 2;
}

void Exercise26::Solve()
{
    int result = 0;
    int valMax = 0;
    int resultMax = 0;
    for(int i = _nbMin;i<=_nbMax;i++)
    {
        result = TryDiv(i);
        if(result > resultMax)
        {
            resultMax = result;
            valMax = i;
        }
    }
    cout<<"i max: "<<valMax<<" cycle size "<<resultMax<<endl;
}


int Exercise26::TryDiv(int value)
{
    int remaind = 1;
    while (remaind < value)
        remaind*=10;
    //int res =0;
    list<int> myList;
    set<int> mySet;
    while(true)
    {
       // res = remaind/value;
        remaind = remaind%value;
        if (remaind == 0)
            return remaind;
        if (!mySet.insert(remaind).second)
        {
            int size = myList.size();
            for(list<int>::iterator iter= myList.begin();;iter++ )
                if (*iter != remaind)
                    --size;
                else
                    return size;
        }
        myList.push_back(remaind);
        remaind*=10;
    }
    return -1;
}
