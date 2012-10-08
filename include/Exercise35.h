#ifndef EXERCISE35_H
#define EXERCISE35_H

#include <AbstractSolver.h>


class Exercise35 : public AbstractSolver
{
private:
  static int Rotate(int value);
  int _max;
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    void AskForParams();
public:
    Exercise35();
    virtual ~Exercise35();
};

#endif // EXERCISE35_H
