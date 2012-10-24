#ifndef EXERCISE37_H
#define EXERCISE37_H

#include <AbstractSolver.h>


class Exercise37 : public AbstractSolver
{

protected:
    virtual void Solve();
    virtual void SetDefaultValues();

public:
    Exercise37();
    virtual ~Exercise37();
};

#endif // EXERCISE37_H
