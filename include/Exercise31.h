#ifndef EXERCISE31_H
#define EXERCISE31_H

#include <AbstractSolver.h>


class Exercise31 : public AbstractSolver
{
  private:
    int Recurse(int pos,int remain);
    
    static int _nbCoins;
    static int _coins[];//{200,100,50,20,10,5,2,1};
    int _value;
protected:
    virtual void Solve();
    virtual void SetDefaultValues();   
    void AskForParams();
public:
    Exercise31();
    virtual ~Exercise31();
    
    
};

#endif // EXERCISE31_H
