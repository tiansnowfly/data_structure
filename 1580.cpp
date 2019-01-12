#include <iostream>
#define max 1000002
using namespace std;

int lis[max];
int len=1;
void check(int x){
    if(x>lis[len-1]){
        lis[len]=x;
        ++len;
        return ;
    }
    int low=0,high=len-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(lis[mid]>x) high=mid-1;
        else if(lis[mid]<x) low=mid+1;
        else break;
    }
    lis[low]=x;
}
int main(){
    int n,elem,i;
    cin>>n;
    lis[0]=0;
    for(i=0;i<n;++i){
        cin>>elem;
        check(elem);
    }
    cout<<len-1;
    return 0;
}
