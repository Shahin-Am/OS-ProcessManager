#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include "SJF.h"

void SJF::AskProcess(){
    int x;
    cout<<"How many processes ?"<<endl;
    cin>>x;
    nbProc=x;
}
void SJF::CreatTableProcessSJF(){
    int i=0;
    vector<int> tab(nbProc,0);
    for(i;i<nbProc;i++)
    {
        cout<<"Process Time"<< i+1<<endl;
        cin>>tab[i];
    }
    cout<<"Your table is :"<<endl;
    PrintTable(tab);
    cout<<"In the right order :"<<endl;
    Order(tab);
    PrintTable(tab);
    cout<<"Process Time"<<endl;
    
    PrintTimeTable(TimeCalculator(tab));
    cout<< "Waiting time = "<<WaitingTimeCalculator(TimeCalculator(tab))<<"s"<<endl;
    cout<< "Turn around time = "<<TurnAroundTimeCalculator(TimeCalculator(tab))<<"s"<<endl;
    
   
}
void SJF::PrintTable(vector<int> tab)
{
    int i=0;
    for(i;i<nbProc;i++)
    {
        cout<<"|"<<tab[i]<<"|";
    }
    cout<<endl;
}
void SJF::Order(vector<int>&tab)
{
    int i=0,j=0;
    for(i;i<nbProc;i++){
        j=i+1;
        for(j;j<nbProc;j++){
            if(tab[i]>tab[j]){
                swap(tab[i], tab[j]);
            }
        }
    }
    
}
vector<int> SJF::TimeCalculator(vector<int>tab){
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
void SJF::PrintTimeTable(vector<int> tab)
{
    int i=0;
    for(i;i<nbProc+1;i++)
    {
        cout<<"|"<<tab[i]<<"|";
    }
    cout<<endl;
}
double SJF::WaitingTimeCalculator(vector<int>timetab){
    int i=0;
    double x=0;
    for(i;i<nbProc;i++){
        x=x+timetab[i];
    }
    x=x/nbProc;
    return x;
}
double SJF::TurnAroundTimeCalculator(vector<int>timetab){
    int i=1;
    double x=0;
    for(i;i<=nbProc;i++){
        x=x+timetab[i];
    }
    x=x/nbProc;
    return x;
}
