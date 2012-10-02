#ifndef EXERCISE26_H
#define EXERCISE26_H

#include "AbstractSolver.h"


class Exercise26 : public AbstractSolver
{
public:
    Exercise26();
    virtual ~Exercise26();

protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();

private:
    int TryDiv(int value);

    int _nbMax;
    int _nbMin;
};

#endif // EXERCISE26_H
