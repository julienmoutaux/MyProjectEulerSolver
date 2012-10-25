#ifndef EXERCISE48_H
#define EXERCISE48_H

#include <AbstractSolver.h>


class Exercise48 : public AbstractSolver
{
public:
    Exercise48();
    virtual ~Exercise48();
    
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

private: 
    long long _maxSerie;
    long long _length;
};

#endif // EXERCISE48_H
