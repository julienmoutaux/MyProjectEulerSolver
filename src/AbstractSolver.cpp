#include "AbstractSolver.h"

AbstractSolver::AbstractSolver()
{
}

AbstractSolver::~AbstractSolver()
{
    //dtor
}

void AbstractSolver::ResolveProblem()
{
    if (HasParams())
        AskForParams();
    Solve();
}

void AbstractSolver::ResolveProblemWithDefaultValues()
{
    SetDefaultValues();
    Solve();
}
