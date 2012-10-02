#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace Tools
{
template<class D,class B>
class IsDerivedFrom
{
private:
    class YES
    {
        char a[1];
    };
    class NO
    {
        char a[2];
    };

    static YES Test(B*);
    static NO Test(...);

public:
    enum {IsDerived = sizeof(Test(static_cast<D*>(0))) == sizeof(YES)};
};

template<class T,class B>
class HeritageChecker
{
private:
    typedef char _assertType[IsDerivedFrom<T,B>::IsDerived?1:-1];
};


class Cin
{
public:

    template<class T>
    static T GetValue(string query,T defaultValue)
    {
        T toReturn;
        istringstream iss;
        do
        {
            cout<<query<<" ["<<defaultValue<<"] : "<<endl;
            string input;
            getline(cin,input);
            if (input.empty())
                return defaultValue;
            //T toReturn;
            iss.str (input);
        }
        while((iss>>toReturn).fail());

        return toReturn;
    }

    template<class T>
    static bool GetValue(string query,string defaultValue,string quitValue, T * returnValue)
    {
        T toReturn;
        istringstream iss;
        do
        {
            cout<<query<<" ["<<defaultValue<<"] : "<<endl;
            string input;
            getline(cin,input);
            if (input.empty())
                input =  defaultValue;
            if (input  == quitValue)
                return false;
            iss.str (input);
        }
        while((iss>>toReturn).fail());
        (*returnValue) = toReturn;
        return true;
    }
};
}

#endif // TOOLS_H
