#ifndef EXERCISE43_H
#define EXERCISE43_H

#include <AbstractSolver.h>


class Exercise43 : public AbstractSolver
{
private:
    static int PrimeArray[];
    static long long Coef[];
    
    static void BuildCoefArray();
    static bool HasDivisibilityProperty(long long value);
    static int GetPart(long long value, int i);
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
};

#endif // EXERCISE43_H
