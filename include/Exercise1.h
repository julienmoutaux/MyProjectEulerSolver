#ifndef EXERCISE1_H
#define EXERCISE1_H

#include "AbstractSolver.h"


class Exercise1 : public AbstractSolver
{
public:
    Exercise1();
    virtual ~Exercise1();
protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();
private:
    int OldResolve();
    int NewResolve();

    int _max;
    bool _oldSchool;
};

#endif // EXERCISE1_H
