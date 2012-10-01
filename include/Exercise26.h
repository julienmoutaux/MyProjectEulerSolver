#ifndef EXERCISE26_H
#define EXERCISE26_H

#include "AbstractSolver.h"


class Exercise26 : public AbstractSolver
{
public:
    Exercise26();
    virtual ~Exercise26();

    static string GetName();
     bool HasParams();

protected:
    void AskForParams();
    void Solve();
    void SetDefaultValues();

private:
    int TryDiv(int value);

    int _nbMax;
    int _nbMin;
};

class Exercise26A : public AbstractSolver
{
public:
    Exercise26A(){ }
    virtual ~Exercise26A(){}

    static string GetName(){return "Exo26A";}
     bool HasParams(){return false;}
protected:
    void AskForParams(){}
    void Solve(){}
    void SetDefaultValues(){}
private:

};
#endif // EXERCISE26_H
