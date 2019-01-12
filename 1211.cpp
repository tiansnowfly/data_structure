#include <iostream>
#define MAX 1000002
using namespace std;
int elemLeft[MAX],elemRight[MAX];
int main(){
    int N,i,countL=0,countR=0;
    cin>>N;
    for(i=0;i<N;++i){
        cin>>elemLeft[N-i-1]>>elemRight[N-i-1];
        if(elemLeft[N-i-1]!=0){++countL;}
        if(elemRight[N-i-1]!=0){++countR;}
    }
    bool flag=true;
    if(countL<countR)flag=false;
    else{for(i=0;i<N;++i){

        }
    }
    if(countL>=countR)cout<<"Y";
    else cout<<"N";
    return 0;
}
