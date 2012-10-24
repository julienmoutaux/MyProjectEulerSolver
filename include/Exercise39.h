#ifndef EXERCISE39_H
#define EXERCISE39_H

#include <AbstractSolver.h>

#include <map>

using namespace std;

class Exercise39 : public AbstractSolver
{
private :
    
    static map<int,int> BuildSqrableValues(int borneSup);
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

public:
    Exercise39();
    virtual ~Exercise39();
};

#endif // EXERCISE39_H
