#include "AbstractSolver.h"

#include <time.h>

AbstractSolver::AbstractSolver()
{
    Init(false);
}

AbstractSolver::AbstractSolver(bool hasParams)
{
    Init(hasParams);
}

bool AbstractSolver::HasParams()
{
    return _hasParams;
}

void AbstractSolver::Init(bool hasParams)
{
    _hasParams = hasParams;
}

AbstractSolver::~AbstractSolver()
{
    //dtor
}

void AbstractSolver::ResolveProblem()
{
    if (HasParams())
        AskForParams();
    LaunchSolver();
}

void AbstractSolver::ResolveProblemWithDefaultValues()
{
    SetDefaultValues();
    LaunchSolver();
}

void AbstractSolver::LaunchSolver()
{  
  
  time_t start,end;    
    time (&start);
    Solve();
    time (&end); 
    cout<<"Compute duration :"<<difftime (end,start)<<" seconds"<<endl;
}
