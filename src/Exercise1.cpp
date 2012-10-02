#include "Exercise1.h"

#include "Tools.h"

Exercise1::Exercise1()
    :AbstractSolver(true)
{
    //ctor
}

Exercise1::~Exercise1()
{
    //dtor
}

void Exercise1::AskForParams()
{
    _max = Tools::Cin::GetValue<int>("What is the maximum value to test?",1000);
    _oldSchool = Tools::Cin::GetValue<int>("Do you want to resolve with oldSchool method ?",false);
}

void Exercise1::SetDefaultValues()
{
    _max = 1000;
    _oldSchool =false;
    cout<<"Solving for values below"<<_max<<" with new method"<<endl;
}

void Exercise1::Solve()
{
    int sum;
    if (_oldSchool)
        sum = OldResolve();
    else
        sum = NewResolve();
    cout<<"the sum of elements is "<<sum<<endl<<endl;
}

int Exercise1::OldResolve()
{
    int sum = 0;
    for(int i=1; i< _max; i++)
        if (!(i%3) || !(i%5))
            sum+=i;
    return sum;
}

int Exercise1::NewResolve()
{
    int sum = 0;
    for(int i=0; i< _max; i+=3)
        sum +=i;
    for(int i=0; i< _max; i+=5)
        if (i%3)
            sum +=i;
    return sum;
}
