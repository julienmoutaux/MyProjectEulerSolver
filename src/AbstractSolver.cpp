#include "AbstractSolver.h"

int AbstractSolver::_cpt = 1;

AbstractSolver::AbstractSolver(string name)
{
    Init(name,false);
}

AbstractSolver::AbstractSolver(string name, bool hasParams)
{
    Init(name,hasParams);
}

void AbstractSolver::Init(string name, bool hasParams)
{
    _name = name;
    _idx = _cpt++;
    _hasParams = hasParams;
}

AbstractSolver::~AbstractSolver()
{
    //dtor
}

int AbstractSolver::GetIndex()
{
    return _idx;
}

string AbstractSolver::Getname()
{
    return _name;
}

void AbstractSolver::ResolveProblem()
{
    if (_hasParams)
        AskForParams();
    Solve();
}

void AbstractSolver::ResolveProblemWithDefaultValues()
{
    SetDefaultValues();
    Solve();
}
