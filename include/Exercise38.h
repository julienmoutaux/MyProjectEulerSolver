#ifndef EXERCISE38_H
#define EXERCISE38_H

#include <AbstractSolver.h>

#include <list>

using namespace std;

class Exercise38 : public AbstractSolver
{
private:

protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    static long long GetValue(long long candidate, int n);

public:
    Exercise38();
    virtual ~Exercise38();
};

#endif // EXERCISE38_H
