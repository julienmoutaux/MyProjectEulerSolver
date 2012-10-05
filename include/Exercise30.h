#ifndef EXERCISE30_H
#define EXERCISE30_H

#include <AbstractSolver.h>


class Exercise30 : public AbstractSolver
{
public:
    Exercise30();
    virtual ~Exercise30();
    
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

private:
    int _size;
    int Evaluate(int value);
};

#endif // EXERCISE30_H
