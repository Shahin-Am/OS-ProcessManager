#include "Priority.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void priority::AskProcess(){
    
    cout<<"How many processes ?"<<endl;
    cin>>nbProc;
  
}
void priority::CreatTableProcess(){
    int i=0, j=0,x=0;
    vector<vector<int>> tab2D;
    tab2D.push_back(vector<int>(nbProc));
    tab2D.push_back(vector<int>(nbProc));
    tab2D.push_back(vector<int>(nbProc));
    for(i;i<nbProc;i++)
    {
        for(j;j<nbProc;j++)
        {
            cout<<"Process Time"<< j+1<<endl;
            cin>>tab2D[0][j];
            cout<<" Priority P"<< j+1<<"?"<<endl;
            cin>>tab2D[1][j];
            x++;
            tab2D[2][j]=x;
        }
    }
    PrintTable2D(tab2D);
    Order(tab2D);
    cout<<"In the right order"<<endl;
    PrintTable2D(tab2D);
    cout<<"Times"<<endl;
    PrintTimeTable(TimeCalculator(tab2D));
    cout<<"Waiting time ="<<WaitingTimeCalculator(TimeCalculator(tab2D))<<endl;
    cout<<"Turn Around Time ="<<TurnAroundTimeCalculator(TimeCalculator(tab2D))<<endl;
}
void priority::PrintTable2D(vector<vector<int>> tab)
{
    int i=0,j=0;
    
    for (i; i<3; i++) {
        if(i==0){cout<<"Burst Time";}
        if(i==1){cout<<"Priority  ";}
        if(i==2){cout<<"Process   ";}
         for (j; j<nbProc; j++)
         {
            cout<<"  "<<tab[i][j];
         }
        cout<<endl;
        j=0;
    }
    
}

void priority::Order(vector<vector<int>>& tab){
    int x=0,j=0;
    for(j;j<nbProc;j++){
        x=j+1;
        for(x;x<nbProc;x++){
            if(tab[1][j]>tab[1][x]){
                swap(tab[0][j], tab[0][x]);
                swap(tab[1][j], tab[1][x]);
                swap(tab[2][j], tab[2][x]);
                
            }
        }
    }
}
vector<int> priority::TimeCalculator(vector<vector<int>>tab){
    int i=0,x=0;
    vector<int> timetab(nbProc+1,0);
    timetab[0]=0;
    for(i;i<nbProc;i++)
    {
        x=x+tab[0][i];
        timetab[i+1]=x;
    }
    return timetab;
}
void priority::PrintTimeTable(vector<int> tab)
{
    int i=0;
    for(i;i<nbProc+1;i++)
    {
        cout<<"|"<<tab[i]<<"|";
    }
    cout<<endl;
}
double priority::WaitingTimeCalculator(vector<int>timetab){
    int i=0;
    double x=0;
    for(i;i<nbProc;i++){
        x=x+timetab[i];
    }
    x=x/nbProc;
    return x;
}
double priority::TurnAroundTimeCalculator(vector<int>timetab){
    int i=1;
    double x=0;
    for(i;i<=nbProc;i++){
        x=x+timetab[i];
    }
    x=x/nbProc;
    return x;
}
