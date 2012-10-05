#ifndef EXERCISE27_H
#define EXERCISE27_H
#include "AbstractSolver.h"

class Exercise27
:public AbstractSolver
{
  public:
    Exercise27();
    virtual ~Exercise27();

protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();

private:
    int _aMax;
    int _bMax;
    
    long Evaluate(int n,int a,int b);    
};

#endif // EXERCISE27_H
