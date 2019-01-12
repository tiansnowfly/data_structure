#include <iostream>
#include <cstring>
#define mx 1001
using namespace std;

int water[mx],high=0,w0=0,w=0,ans=0,mxLoc,mxHigh;
int main(){
    char ch0;
    int n,i,num,ct=0;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>ch0;
        num=0;
        while(ch0>='0'&&ch0<='9'){
            num=10*num+(ch0-'0');
            cin>>ch0;
        }
        water[++ct]=num;
        w0+=water[ct];
        if(water[ct]>=mxHigh){
            mxHigh=water[ct];
            mxLoc=ct;
        }
    }
    cin>>ch0;
    for(i=1;i<mxLoc;++i){
        if(high>=water[i])water[i]=high;
        else high=water[i];
        w+=water[i];
    }
    high=0;
    for(i=n;i>mxLoc;--i){
        if(high>=water[i])water[i]=high;
        else high=water[i];
        w+=water[i];
    }
    cout<<w+water[mxLoc]-w0;
    return 0;
}
/*
12
[0,1,0,2,1,0,1,3,2,1,2,1]
3
[2,1,2]
*/
