#include <Exercise40.h>

#include <sstream>
#include <math.h>

using namespace std;

//int Exercise40::values[7]{1,10,100,1000,10000,100000,1000000};

Exercise40::Exercise40()
{

}

Exercise40::~Exercise40()
{

}


void Exercise40::Solve()
{
    stringstream iss;
    //istringstream isstemp;
    bool cont = true;
    long long cpt = 1;
    int size = 0;
    while(size<= 1000000)
    {
	iss<<cpt++;
	size += log10(cpt);	
    }
    string str = iss.str();
    cout<<"d1 = "<<str[0]<<endl;
    cout<<"d10 = "<<str[9]<<endl;
    cout<<"d100 = "<<str[99]<<endl;
    cout<<"d1000 = "<<str[999]<<endl;
    cout<<"d10000 = "<<str[9999]<<endl;
    cout<<"d100000 = "<<str[99999]<<endl;
    cout<<"d1000000 = "<<str[999999]<<endl;
}

void Exercise40::SetDefaultValues()
{

}