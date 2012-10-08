#ifndef EXERCISE34_H
#define EXERCISE34_H

#include <list>

#include <AbstractSolver.h>

using namespace std;

class Exercise34 : public AbstractSolver
{
private:
  static long long * _factorials;
  static int _maxFacto ;
 static void BuildListOfFactorials();
 static long long GetSumOfFactorials(long long value);
  
protected:
    virtual void Solve();
    virtual void SetDefaultValues();

public:
    Exercise34();
    virtual ~Exercise34();
};

#endif // EXERCISE34_H
