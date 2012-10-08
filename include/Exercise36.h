#ifndef EXERCISE36_H
#define EXERCISE36_H

#include <AbstractSolver.h>


class Exercise36 : public AbstractSolver
{
private:
  int _max;
  
  static bool IsPalindromic(string value);
  static string ConvertValueToBinString(int value);
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

public:
    Exercise36();
    virtual ~Exercise36();
};

#endif // EXERCISE36_H
