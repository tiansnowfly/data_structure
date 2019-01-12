#include <iostream>
#define mx 10001
using namespace std;

int  n,m,ans=0;
int elem1[mx],elem2[mx];

int divide(int a[],int low,int high){
    int k=a[low];
    do{
        while(low<high&&k>=a[high])--high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&k<=a[low]) ++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
void quickSort(int a[],int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
int main(){
    int i,j,cur=1;
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>elem1[i];
    for(i=1;i<=m;++i)cin>>elem2[i];
    quickSort(elem1,1,n);
    quickSort(elem2,1,m);
    for(i=1;i<=n;++i){
        for(j=cur;j<=m;++j){
            if(elem1[i]>elem2[j]){
                ++ans;
                cur=j+1;
                break;
            }
        }
    }
    cout<<ans+n;
    return 0;
}
