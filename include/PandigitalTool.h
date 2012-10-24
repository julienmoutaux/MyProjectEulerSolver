#ifndef PANDIGITALTOOL_H
#define PANDIGITALTOOL_H

class PandigitalTool
{
public:
  PandigitalTool(int max = 9,int min = 1);
  
  bool IsPandigital(long long value);
  void Print(bool withEndl = false);
  
  void BeginPandigitalConstruction();
  bool AddToPandigitalConstuction(long long value);
  bool IsPandigitalComplete();
  
  int getMin();
  int getMax();
  
  ~PandigitalTool();
private:
  void InitValArray();
  bool AddToArray(long long value);
  
  int _min;
  int _max;
  
  long long _sup;
  long long _inf;
  
  int _val[10];
};

#endif // PANDIGITALTOOL_H
