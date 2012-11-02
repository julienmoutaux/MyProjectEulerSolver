#ifndef EXERCISE102_H
#define EXERCISE102_H

#include <AbstractSolver.h>

#include <iostream>
#include <vector>

using namespace std;

class Exercise102 : public AbstractSolver
{
private : 
  string _filename;
  
  std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
  std::vector<std::string> split(const std::string &s, char delim) ;
protected:
    virtual void Solve();
    virtual void SetDefaultValues();
    virtual void AskForParams();

public:
    Exercise102();
    virtual ~Exercise102();
};

#endif // EXERCISE102_H
