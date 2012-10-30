#ifndef PRIMETOOL_H
#define PRIMETOOL_H

#include <iostream>
#include <list>

using namespace std;

class PrimeTool
{
    public:
        PrimeTool();
        PrimeTool(string filename);
        virtual ~PrimeTool();

        bool IsPrime(long long number);

       list<long long> GetListOfPrimesTo(long long value);

       list<long long> ConvertToPrimeFactor(long long value);
       list<long long> ConvertToPrimeFactor(long long value,long long exposant);

      string WriteToPrimeFactor(long long value);
       string WriteToPrimeFactor(long long value,long long exposant);

       string ConvertPrimeFactorToString(list<long long> primeFactor);

       long long GetIemeElement(long long ieme);
       
       bool IsPseudoPrime(long long value, int depth);
    protected:
    private:
        void LoadFromFile();
        void SaveToFile();

        bool Find(long long value);
        void BuildPrimesUntil(long long value);
	void BuildPrimesUntilSize(int size);
        void AddPrime(long long prime);

        list<long long> _primes;
        long long _lastPrime;

        bool _useFile;
        string _filename;
};

#endif // PRIMETOOL_H
