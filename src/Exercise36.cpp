#include "Exercise36.h"

#include "Tools.h"
#include <math.h>
#include <sstream>
#include <bitset>
#include <climits>

using namespace std;

void Exercise36::Solve()
{
    long long value = 0;
    for(int i = 1; i<_max; i++)
    {
        stringstream iss;
        iss<<i;
        if (IsPalindromic(iss.str()) && IsPalindromic(ConvertValueToBinString(i)))
            value += i;
    }
    cout<<"The sum of all palindroms below "<<_max<<" is "<<value<<endl;
}

bool Exercise36::IsPalindromic(string value)
{
    int i = 0, j= value.size()-1;
    while(i<j)
    {
        if (value[i] != value[j])
            return false;
        i++;
        j--;
    }
    return true;
}

string Exercise36::ConvertValueToBinString(int value)
{
    std::bitset<CHAR_BIT * sizeof(int)> binary;
    binary |= value;
    string str = binary.to_string<char,char_traits<char>,allocator<char> >();
    string::size_type pos = 0;
    while (pos < str.size() && str[pos] == '0') pos++;
    return str.erase(0, pos);
}

void Exercise36::SetDefaultValues()
{
    _max = pow10(6);
    cout<<"using max value "<<_max<<endl;
}

void Exercise36::AskForParams()
{
    _max = Tools::Cin::GetValue<int>("What is the max value ?",pow10(6));
}

Exercise36::Exercise36()
{

}

Exercise36::~Exercise36()
{

}

