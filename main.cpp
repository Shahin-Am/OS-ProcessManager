#include <iostream>
#include "FIFO.h"
#include "SJF.h"
#include "Priority.h"
#include "RR.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int m;
    cout<<"1. FIFO"<<endl;
    cout<<"2. SJF"<<endl;
    cout<<"3. Priority"<<endl;
    cout<<"4. RR"<<endl;


    cin>>m;
    if(m==1){
        FIFO A;
        A.AskProcess();
        A.CreatTableProcess();
    }
    if(m==2){
        SJF A;
        A.AskProcess();
        A.CreatTableProcessSJF();
    }
    if(m==3)
    {
        priority A;
        A.AskProcess();
        A.CreatTableProcess();
    }
    if(m==4)
    {
        RR A;
        A.AskProcess();
        A.CreatTableProcess();
    }
    return 0;
}
