#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N,K,N1,N2;
    int j=0;

    cin>>N;

    for(int i=2;i<int(sqrt(N));++i){
        if(N%i==0){++j;}
    }
    if(j==0){cout<<0;}
    else{
        for(int i=N;i>=N;++i){
            int h=0;
            for(int k=2;k<=int(sqrt(i));++k){
            if(i%k==0){++h;}
            }
            if(h==0){N2=i;break;}
        }
        for(int i=N;i<=N;--i){
            int h=0;
            for(int k=2;k<=int(sqrt(i));++k){
            if(i%k==0){++h;}
            }
            if(h==0){N1=i;break;}
        }
        cout<<N2-N1;
    }
    return 0;
}
