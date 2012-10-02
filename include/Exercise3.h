#ifndef EXERCISE3_H
#define EXERCISE3_H

#include "AbstractSolver.h"


class Exercise3 : public AbstractSolver
{
public:
    Exercise3();
    virtual ~Exercise3();
protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();
private:
    long long _number;
};

#endif // EXERCISE3_H
