#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <iostream>

using namespace std;

class AbstractSolver
{
public:
    AbstractSolver(string name);
    AbstractSolver(string name, bool hasParams);
    virtual ~AbstractSolver();

    int GetIndex();
    string Getname();

    void ResolveProblem();
    void ResolveProblemWithDefaultValues();
protected:
    virtual void AskForParams(){}

    virtual void SetDefaultValues()=0;
    virtual void Solve() = 0;
private:
    void Init(string name, bool hasParams);

    static int _cpt;

    bool _hasParams;
    int _idx;
    string _name;
};

#endif // ABSTRACTSOLVER_H
