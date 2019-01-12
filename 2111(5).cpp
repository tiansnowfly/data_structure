#include <iostream>
#include <cmath>
#define Mx 100002
using namespace std;

int len=1,M;
int elem[Mx];
int findx(int x){
    if(len==1)return 1;
    int low=1,high=len-1,mid;
    while(low<high){
        mid=(low+high)/2;
        if(x<elem[mid])high=mid;
        else if (elem[mid]<=x)high=mid+1;
    }
    if (elem[low]>x) return low;
    if (elem[high]<=x) return high+1;
}
void insertx(int x){
    int tmp=findx(x);
    for(int i=len;i>tmp;--i)elem[i]=elem[i-1];
    elem[tmp]=x;
    ++len;
}
int find2(int x){
    int low=1,high=len-1,mid;
    while (low<=high){
        mid=(low+high)/2;
        if (elem[mid]==x) return mid;
        else if (elem[mid]>x) high=mid-1;
        else if (elem[mid]<x) low=mid+1;
    }
    return -1;
}
void deletex(int x){
    int tmp=find2(x);
    for(int i=tmp;i<len-1;++i)elem[i]=elem[i+1];
    --len;
}
int min_abs(int x){
    int tmp=findx(x);
    if (tmp==len) return fabs(elem[tmp-1]-x);
    if (tmp==1) return fabs(elem[tmp]-x);
    return fabs(elem[tmp]-x)<fabs(elem[tmp-1]-x)?fabs(elem[tmp]-x):fabs(elem[tmp-1]-x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kind,i,num;
    cin>>M;
    for(i=0;i<M;++i){
        cin>>kind>>num;
        switch(kind){
            case 0:cout<<min_abs(num)<<'\n';break;
            case 1:insertx(num);break;
            case 2:deletex(num);break;
        }
    }
    return 0;
}
