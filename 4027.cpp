#include <iostream>
#define mx 100001
using namespace std;

int a[mx],b[mx],len=1;
int check(int b[],int len,int x){
    int low=0,high=len-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(b[mid]>x) high=mid-1;
        else if(b[mid]<x) low=mid+1;
        else return mid;
    }
    return low;
}
int main(){
    int n,i,num,loc;
    cin>>n;
    for(i=1;i<=n;++i){cin>>num;a[num]=i;}
    for(i=1;i<=n;++i){cin>>num;b[i]=a[num];}
    for(i=2;i<=n;++i){
        num=b[i];
        if(num>b[len])b[++len]=num;
        else{
            loc=check(b,len,num);
            b[loc]=num;
        }
    }
    cout<<len;
    return 0;
}
