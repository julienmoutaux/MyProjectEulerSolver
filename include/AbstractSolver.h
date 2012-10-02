#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <iostream>

using namespace std;

class AbstractSolver
{
public:

    virtual ~AbstractSolver();

    void ResolveProblem();
    void ResolveProblemWithDefaultValues();

    bool HasParams();
protected:
    AbstractSolver();
    AbstractSolver(bool hasParams);
    virtual void AskForParams(){}

    virtual void SetDefaultValues()=0;
    virtual void Solve() = 0;

private:
    void Init(bool hasParams);
    void LaunchSolver();

    bool _hasParams;
};

#endif // ABSTRACTSOLVER_H
