#ifndef PANDIGITALTOOL_H
#define PANDIGITALTOOL_H

#include <list>

using namespace std;

class PandigitalTool
{
public:
  PandigitalTool(int max = 9,int min = 1);
  
  bool IsPandigital(long long value);
  void Print(bool withEndl = false);
  
  void BeginPandigitalConstruction();
  bool AddToPandigitalConstuction(long long value);
  bool IsPandigitalComplete();
  int IsPandigitalCandidate();
  int IsPandigitalCandidate(long long value);
  list<long long> BuildAllPandigitals();
  
  int getMin();
  int getMax();
  
    long long getSup();
  long long getInf();
  
  ~PandigitalTool();
private:
  void InitValArray();
  bool AddToArray(long long value);
  
  void RecursiveBuildPandigitalList(list<int> availableValues, list<long long> * allValues,long long currentValue);
  
  int _min;
  int _max;
  
  long long _sup;
  long long _inf;
  
  int _val[10];
  int _target;
};

#endif // PANDIGITALTOOL_H
