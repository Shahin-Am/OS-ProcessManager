#include <stdio.h>
#include "RR.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void RR::AskProcess(){
    cout<<"How many processes ?"<<endl;
    cin>>nbProc;
    cout<<"What is the time slice ?"<<endl;
    cin>>slice;
}
void RR::CreatTableProcess(){
    int i=0, j=0,x=0;
    vector<vector<int>> tab2D;
    tab2D.push_back(vector<int>(nbProc));
    tab2D.push_back(vector<int>(nbProc));
    tab2D.push_back(vector<int>(nbProc,0));
    
    
    for(i;i<nbProc;i++)
    {
        for(j;j<nbProc;j++)
        {
            cout<<"Process Time"<< j+1<<endl;
            cin>>tab2D[0][j];
            x++;
            tab2D[1][j]=x;
           
        }
    }
    PrintTable2D(tab2D);
    LoopCalculator(tab2D);
    PrintTable2D(tab2D);
    PrintTimeTable(TimeCalculator(tab2D,tab2D));
    PrintTable2D(tab2D);
    
    }

void RR::PrintTable2D(vector<vector<int>> tab){
    int i=0,j=0;
    for(i;i<3;i++){
        if(i==0){cout<<"Burst Time  ";}
        if(i==1){cout<<"Process     ";}
        if(i==2){cout<<"Loop        ";}
       
        for (j; j<nbProc; j++) {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
        
        j=0;
    }
    cout<<endl;
    loop2=loop;
}
void RR::PrintTimeTable(vector<vector<int>> tab)
{
    int i=0,j=0;
    cout<<"Time"<<endl;
    for(i;i<2;i++)
    {
        for(j;j<loop+1;j++){
           cout<<"|"<<tab[i][j]<<"|";
        }
        cout<<endl;
        j=0;
    }
    cout<<endl;
}
vector<vector<int>> RR::TimeCalculator(vector<vector<int>>&tab,vector<vector<int>>tabref){
    int j=0,x=0,nbloop=0,order=1, b=0;
    for(j;j<nbProc;j++)
    {
        nbloop=nbloop+tab[2][j];
    }
        j=0;
    loop=nbloop;
    
    vector<vector<int>> timetab;    ////////////////////////
    timetab.push_back(vector<int>(nbloop+1));
    timetab.push_back(vector<int>(nbloop+1,0));
    for(j;j<nbProc;j++)
    {
        if(tab[0][j]>=slice)
        {
            x=x+slice;
            timetab[0][j+1]=x;
            tab[2][j]=tab[2][j]-1;   //enlève boucle
            timetab[1][j]=tab[1][j];  //ordre timetab
            tab[0][j]=tab[0][j]-slice;
        }
        else{
            x=x+tab[0][j];
            timetab[0][j+1]=x;
            tab[2][j]=tab[2][j]-1;  //enlève boucle
            timetab[1][j]=tab[1][j]; //ordre timetab
            tab[0][j]=0;
        }
        
    }
    
    j=0;
    int i=nbProc;
    for(i;i<loop;i=i)
    {
        b=0;
        if(tab[2][j]>=2)
        {
            x=x+slice;
            timetab[0][i+1]=x;
            tab[2][j]=tab[2][j]-1;
            timetab[1][i]=tab[1][j];
            tab[0][j]=tab[0][j]-slice;
            i++;
            b=1;
        }
        if(tab[2][j]==1 && b==0) {
           
            x=x+tab[0][j];
            timetab[0][i+1]=x;
            tab[2][j]=tab[2][j]-1;
            timetab[1][i]=tab[1][j];
            tab[0][j]=0;
            i++;
        }
        j++;
        if(j==5){
            j=0;
        }
    }
    
    ///////////////////////////////////////////////////
    
    j=0;i=0;
    int a=0;
     b=0;
    int c=0;
    x=0;
    int d=0;
    int z=0;
    float sommes=0,sommes2;
    
        while(a<loop && d<nbProc){
            b=a;
            j=a+1;
        
                for(j;j<loop;j++ && d<nbProc){
                    if(c==0){
                        x=x+timetab[0][a];
                        
                        c++;
                    }
                    if(timetab[1][a]==timetab[1][j]){
                        x=x+(timetab[0][j]-timetab[0][a+1]);
                        a=j;
                    }
                    
                    if(j==loop-1){
                        cout<<"Waiting Time "<<timetab[1][a]<<" = "<<x<<endl;
                        cout<<"Turn Around Time "<<timetab[1][a]<<" = "<<x+tabref[0][d]<<endl;
                        sommes=sommes+x;
                        sommes2=sommes2+x+tabref[0][d];
                        d++;
                    }
                }
        
        x=0;
        a=b+1;
        c=0;
    }
    sommes=sommes/nbProc;
    sommes2=sommes2/nbProc;
    cout<<"Average Waiting Time = "<<sommes<<endl;
    cout<<"Average Turn Around Time = "<<sommes2<<endl;
    return timetab;
}

void RR::LoopCalculator(vector<vector<int>>&tab){
    int x=0,j=0,a,c=0;
    for(j;j<nbProc;j++){
        a=tab[0][j];
        if(a<slice){
            tab[2][j]=1;
        }
        else if(a%slice==0){
            tab[2][j]=a/slice;
           
        }
        else{
             while(x==0){
                 a=a-slice;
                 c++;
                 if(a<slice){
                     c++;
                     x=1;
                     tab[2][j]=c;
                 }
             }
        }
        c=0;
        x=0;
    }}


