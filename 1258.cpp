#include <iostream>
#define MAX 1000002
using namespace std;
long long a[MAX],tmp[MAX];
long long count=0;
void merge(int low,int mid,int high){
    int i=low,j=mid,k=0;
    while(i<mid&&j<=high){
        if(a[i]<=a[j])tmp[k++]=a[i++];
        else {tmp[k++]=a[j++];count+=mid-i;}
    }
    while(i<mid)tmp[k++]=a[i++];
    while(j<=high)tmp[k++]=a[j++];
    for(i=0,k=low;k<=high;) a[k++]=tmp[i++];
}
void mergeSort(int low,int high){
    int mid=(low+high)/2;
    if(low==high)return;
    mergeSort(low,mid);
    mergeSort(mid+1,high);
    merge(low,mid+1,high);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){cin>>a[i];}
    mergeSort(0,n-1);
    cout<<count;
    return 0;
}
