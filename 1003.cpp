#include <iostream>
#define MAX 102
using namespace std;

int Dt[MAX][MAX];
int main(){
    int count=0,L,i,j;
    cin>>L;


    for(i=1;i<L+1;++i){
        for(j=1;j<L+1;++j){
            cin>>Dt[i][j];
        }
    }
    int ct=0;
    int xj=1;
    while(ct!=L*L){
        ct=0;
        for(i=1;i<=L;++i){
            for(j=1;j<=L;++j){
                if(Dt[i][j]!=0){++ct;}
            }
        }
        if(ct!=L*L) ++count;
        for(i=1;i<L+1;++i){
            for(j=1;j<L+1;++j){
                if(Dt[i][j]==xj){
                    if(Dt[i+1][j]==0){Dt[i+1][j]=xj+2;}
                    if(Dt[i-1][j]==0){Dt[i-1][j]=xj+2;}
                    if(Dt[i][j+1]==0){Dt[i][j+1]=xj+2;}
                    if(Dt[i][j-1]==0){Dt[i][j-1]=xj+2;}
                }
            }
        }
        xj=xj+2;
    }
    cout<<count;
    return 0;
}
