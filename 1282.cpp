#include <iostream>
using namespace std;

int elem[2002],elem0[2002];
int minCost1=0,minCost2=0;
int main(){
    int i,n,j;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>elem[i];
        elem0[i]=elem[i];
        elem[0]=elem[1];
        elem0[0]=elem0[1];
        if(elem[i]<elem[i-1]){
            minCost1+=elem[i-1]-elem[i];
            elem[i]=elem[i-1];
        }
        if(elem0[i]>elem0[i-1]){
            minCost2+=elem0[i]-elem0[i-1];
            elem0[i]=elem0[i-1];
        }
    }
    minCost1=minCost1<minCost2?minCost1:minCost2;
    cout<<minCost1;

    return 0;
}
