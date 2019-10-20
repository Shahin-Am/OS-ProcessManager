#ifndef Table_h
#define Table_h
#include <vector>
using namespace std;

class FIFO
{
private:
    int nbProc;
   
    
    
public:
    
    void AskProcess();
    void CreatTableProcess();
    void PrintTable(vector<int> tab);
    vector<int> TimeCalculator(vector<int>tab);
    void PrintTimeTable(vector<int> tab);
    double WaitingTimeCalculator(vector<int> tab);
    double TurnAroundTimeCalculator(vector<int> tab);

};

#endif /* Table_h */
