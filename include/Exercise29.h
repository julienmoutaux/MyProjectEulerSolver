#ifndef EXERCISE29_H
#define EXERCISE29_H

#include "AbstractSolver.h"


class Exercise29 : public AbstractSolver
{
public:
    Exercise29();
    virtual ~Exercise29();
protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();
private:
int _maxA;
int _maxB;
};

#endif // EXERCISE29_H
