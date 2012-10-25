#include "PrimeTool.h"

#include <fstream>
#include <sstream>

#include <math.h>

PrimeTool::PrimeTool()
{
    _useFile = false;
    if (_primes.size() == 0)
        AddPrime(2);
}

PrimeTool::PrimeTool(string filename)
{
    _useFile = true;
    _filename = filename;
    LoadFromFile();
    if (_primes.size() == 0)
        AddPrime(2);
}

PrimeTool::~PrimeTool()
{
    if (_useFile)
        SaveToFile();
}

bool PrimeTool::IsPrime(long long number)
{
    if (number> _lastPrime)
        BuildPrimesUntil(number);
    return Find(number);
}

bool PrimeTool::IsPseudoPrime(long long value, int depth)
{
    if (!value%2)
        return false;
    int length = 0;
    for(list<long long>::iterator iter = _primes.begin(); iter !=  _primes.end(),length<depth; length++, iter++)
    {
        if (!value%(*iter))
            return false;
    }
    return true;
}

bool PrimeTool::Find(long long value)
{
    //TODO Si j'etais propre je ferais au moins une recherche dichotomique ...
    for(list<long long>::iterator iter = _primes.begin(); iter !=  _primes.end(); iter++)
    {
        if ((*iter) == value)
            return true;
        if ((*iter) > value)
            return false;
    }
    return false;
}

list<long long> PrimeTool::ConvertToPrimeFactor(long long value,long long exposant)
{
    list<long long> listOfPrimes = GetListOfPrimesTo(value);
    listOfPrimes.reverse();
    long long remaind = value;
    list<long long>::iterator iter = listOfPrimes.begin();
    bool first = false;
    list<long long> toReturn;
    while (iter != listOfPrimes.end())
    {
        int cpt = 0;
        while(!(remaind%(*iter)))
        {
            first = true;
            cpt++;
            remaind /= (*iter);
        }
        iter++;
        if (first)
            toReturn.push_back(cpt * exposant);
    }
    toReturn.reverse();
    return toReturn;
}

string PrimeTool::ConvertPrimeFactorToString(list<long long> primeFactor)
{
    ostringstream os;
    for(list<long long>::iterator iter = primeFactor.begin(); iter !=  primeFactor.end(); iter++)
    {
        os<<(*iter)<<"|";
    }

    return os.str();
}

string PrimeTool::WriteToPrimeFactor(long long value)
{
    return ConvertPrimeFactorToString(ConvertToPrimeFactor(value));
}
string PrimeTool::WriteToPrimeFactor(long long value,long long exposant)
{
    return ConvertPrimeFactorToString(ConvertToPrimeFactor(value,exposant));
}

list<long long> PrimeTool::ConvertToPrimeFactor(long long value)
{
    return ConvertToPrimeFactor(value,1);
}

list<long long> PrimeTool::GetListOfPrimesTo(long long value)
{
    if (value> _lastPrime)
        BuildPrimesUntil(value);
    list<long long> toReturn;
    for(list<long long>::iterator iter = _primes.begin(); iter !=  _primes.end(); iter++)
    {
        if ((*iter) > value)
            return toReturn;
        toReturn.push_back(*iter);
    }
    return toReturn;
}

void PrimeTool::BuildPrimesUntil(long long value)
{
    list<long long>::iterator iter;
    bool found;
    long long start = _lastPrime +1;
    if (!(start % 2))
        start++;
    for(long long i = start; i<= value; i+=2)
    {
        found = false;
        for( iter = _primes.begin(); iter !=  _primes.end(); iter++)
            if (!(i%(*iter)))
            {
                found = true;
                break;
            }
        if (!found)
            AddPrime(i);
    }
}

void PrimeTool::AddPrime(long long prime)
{
    _primes.push_back(prime);
    _lastPrime = prime;
}

long long PrimeTool::GetIemeElement(long long ieme)
{
    long long i= 0;
    for(list<long long>::iterator iter = _primes.begin(); iter !=  _primes.end(); iter++,i++)
        if (i == ieme)
            return *iter;
    return 0;
}

void PrimeTool::LoadFromFile()
{
    //TODO A reecrire et à optimiser !! (creation de istringstream à chaque iteration / utilisation de 2 flux pour lire puis extraire les valeurs
    ifstream infile;
    infile.open (_filename.c_str(), ifstream::in);
    istringstream iss;
    string input;
    while ( getline(infile,input,';'))
    {
        istringstream iss(input);
        if (!(iss>>_lastPrime).fail())
            _primes.push_back(_lastPrime);
    }
    infile.close();
}

void PrimeTool::SaveToFile()
{
    ofstream out;
    out.open(_filename.c_str());
    for(list<long long>::iterator iter = _primes.begin(); iter !=  _primes.end(); iter++)
        out<<(*iter)<<";";
    out<<endl;
    out.close();
}
