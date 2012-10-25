#ifndef EXERCISE33_H
#define EXERCISE33_H

#include <AbstractSolver.h>


class Exercise33 : public AbstractSolver
{
private:
    static void Simplify(int nominator,int denominator,int * resNum,int * resDenom);

protected:
    virtual void Solve();
    virtual void SetDefaultValues();

public:
    Exercise33();
    virtual ~Exercise33();
};

#endif // EXERCISE33_H
