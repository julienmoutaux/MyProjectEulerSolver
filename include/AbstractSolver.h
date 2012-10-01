#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <iostream>

using namespace std;

class AbstractSolver
{
public:
    AbstractSolver();
    virtual ~AbstractSolver();

    static string GetName(){return "";}
    virtual bool HasParams() = 0;

    void ResolveProblem();
    void ResolveProblemWithDefaultValues();
protected:
    virtual void AskForParams(){}

    virtual void SetDefaultValues()=0;
    virtual void Solve() = 0;

private:

};

#endif // ABSTRACTSOLVER_H
