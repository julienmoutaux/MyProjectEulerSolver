#ifndef EXERCISE42_H
#define EXERCISE42_H

#include <AbstractSolver.h>

#include <iostream>
#include <set>

using namespace std;


class Exercise42 : public AbstractSolver
{
private:
    string _filename;
    set<long long> _triangles;
    
    long long GetSize(string word);    
    void BuildTrianglesTo(long long max);
    //long long 
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

public:
    Exercise42();
    virtual ~Exercise42();
};

#endif // EXERCISE42_H
