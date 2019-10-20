#ifndef RR_h
#define RR_h
#include <vector>
using namespace std;

class RR{
    private:
    int nbProc;
    int slice;
    int loop;
    int loop2;
    
    public:
        void AskProcess();
        void CreatTableProcess();
        void PrintTable2D(vector<vector<int>> tab);
        void PrintTimeTable(vector<vector<int>> tab);
        vector<vector<int>>TimeCalculator(vector<vector<int>>&tab,vector<vector<int>>tabref);
        void LoopCalculator(vector<vector<int>>&tab);

};

#endif /* RR_h */  
