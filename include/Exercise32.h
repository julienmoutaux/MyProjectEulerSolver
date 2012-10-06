#ifndef EXERCISE32_H
#define EXERCISE32_H

#include <AbstractSolver.h>


class Exercise32 : public AbstractSolver
{

protected:
    virtual void Solve();
    virtual void SetDefaultValues();

public:
    Exercise32();
    virtual ~Exercise32();
private :
  static bool IsPandigital(long long multiplicand,long long multiplier,long long product);
  static bool HasChar(string str, char value);
};

#endif // EXERCISE32_H
