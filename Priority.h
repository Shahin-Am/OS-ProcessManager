#ifndef Priority_h
#define Priority_h
#include <vector>
using namespace std;

class priority
{
private:
    int nbProc;
    
    
    public :
        void AskProcess();
        void CreatTableProcess();
        void PrintTable2D(vector<vector<int>> tab);
        void Order(vector<vector<int>>& tab);
        vector<int> TimeCalculator(vector<vector<int>>tab);
        void PrintTimeTable(vector<int> tab);
        double WaitingTimeCalculator(vector<int> tab);
        double TurnAroundTimeCalculator(vector<int> tab);
};


#endif /* Priority_h */
