#ifndef SJF_h
#define SJF_h

using namespace std;

class SJF
{
private:
    
    int nbProc;
    
public:
    void AskProcess();
    void CreatTableProcessSJF();
    void PrintTable(vector<int> tab);
    void Order(vector<int>&);
    vector<int> TimeCalculator(vector<int>tab);
    void PrintTimeTable(vector<int> tab);
    double WaitingTimeCalculator(vector<int> tab);
    double TurnAroundTimeCalculator(vector<int> tab);
};









#endif /* SJF_h */
