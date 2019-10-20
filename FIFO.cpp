#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "FIFO.h"
using namespace std;

void FIFO::AskProcess(){
    int x;
    cout<<"How many processes ?"<<endl;
    cin>>x;
    nbProc=x;
}
void FIFO::CreatTableProcess(){
    int i=0;
     vector<int> tab(nbProc,0);
    
    for(i;i<nbProc;i++)
    {
        cout<<"Process Time"<< i+1<<endl;
        cin>>tab[i];
    }
    PrintTable(tab);
    cout<<"Process Time"<<endl;
    PrintTimeTable(TimeCalculator(tab));
    cout<< "Waiting time  "<<WaitingTimeCalculator(TimeCalculator(tab))<<"s"<<endl;
    cout<< "Turn around time = "<<TurnAroundTimeCalculator(TimeCalculator(tab))<<"s"<<endl;
  
    ;
}
 void FIFO::PrintTable(vector<int> tab)
{
    int i=0;
    for(i;i<nbProc;i++)
    {
        cout<<"|"<<tab[i]<<"|";
    }
    cout<<endl;
}
vector<int> FIFO::TimeCalculator(vector<int>tab){
    int i=0,x=0;
    vector<int> timetab(nbProc+1,0);
    timetab[0]=0;
    
    for(i;i<nbProc;i++)
    {
        x=x+tab[i];
        timetab[i+1]=x;
    }
    return timetab;
}
void FIFO::PrintTimeTable(vector<int> tab)
{
    int i=0;
    for(i;i<nbProc+1;i++)
    {
        cout<<"|"<<tab[i]<<"|";
    }
    cout<<endl;
}
double FIFO::WaitingTimeCalculator(vector<int>timetab){
    int i=0;
    double x=0;
    for(i;i<nbProc;i++){
        x=x+timetab[i];
       
    }
    x=x/nbProc;
    return x;
}
double FIFO::TurnAroundTimeCalculator(vector<int>timetab){
    int i=1;
    double x=0;
    for(i;i<=nbProc;i++){
        x=x+timetab[i];
    }
    x=x/nbProc;
    return x;
}
