#ifndef EXERCISE40_H
#define EXERCISE40_H

#include <AbstractSolver.h>


class Exercise40 : public AbstractSolver
{
private: 
 // static int values[];
protected:
    virtual void Solve();
    virtual void SetDefaultValues();    

public:
    Exercise40();
    virtual ~Exercise40();
};

#endif // EXERCISE40_H
