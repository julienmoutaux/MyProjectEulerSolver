#include "AbstractSolver.h"

#include <sys/time.h>

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
    struct timeval start, end;
    gettimeofday(&start, NULL);
    Solve();
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec  - start.tv_sec;
    long useconds = end.tv_usec  - start.tv_usec;
    cout<<"Compute duration :"<<seconds<<","<<useconds<<" seconds"<<endl;
}
