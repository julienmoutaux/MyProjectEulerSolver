#ifndef EXERCISE41_H
#define EXERCISE41_H

#include <AbstractSolver.h>


class Exercise41 : public AbstractSolver
{
private:
  static int firstPrimes[];
  
  bool IsFastPrime(long long value);
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
};

#endif // EXERCISE41_H
