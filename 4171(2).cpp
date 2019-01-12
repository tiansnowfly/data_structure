#include <iostream>
#define mx 1000001
using namespace std;

int len=0,n,count=0;
int a[mx],b[mx];
struct node{
    int value,row,col;
};
struct prQueue{
    node arr;
}elem[mx];
void preDown(int hole){
    int child;
    node tmp=elem[hole].arr;
    for(;2*hole<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1].arr.value<elem[child].arr.value)++child;
        if(elem[child].arr.value<tmp.value)elem[hole].arr=elem[child].arr;
        else break;
    }
    elem[hole].arr=tmp;
}
void buildHeap(){for(int k=len/2;k>0;k--)preDown(k);}
void enqueue(const int &r,const int &c){
    int hole=++len;
    for(;hole>1&&a[r]+b[c]<elem[hole/2].arr.value;hole/=2)elem[hole].arr=elem[hole/2].arr;
    elem[hole].arr.value=a[r]+b[c];
    elem[hole].arr.row=r;
    elem[hole].arr.col=c;
}
int dequeue(){
    int minx=elem[1].arr.value;
    elem[1].arr=elem[len--].arr;
    preDown(1);
    return minx;
}
int getRow(){return elem[1].arr.row;}
int getCol(){return elem[1].arr.col;}
int divide(int low,int high,int arr[]){
    int k=arr[low];
    do{
        while(low<high&&arr[high]>=k)--high;
        if(low<high){arr[low]=arr[high];++low;}
        while(low<high&&arr[low]<=k)++low;
        if(low<high){arr[high]=arr[low];--high;}
    }while(low!=high);
    arr[low]=k;
    return low;
}
void sort(int low,int high,int arr[]){
    int mid;
    if(low>=high) return;
    mid=divide(low,high,arr);
    sort(low,mid-1,arr);
    sort(mid+1,high,arr);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin>>n;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i)cin>>b[i];
    sort(1,n,a);
    sort(1,n,b);
    int r,c=1;
    for(i=1;i<=n;++i){enqueue(i,c);}
    while(count<n){
        r=getRow();
        c=getCol();
        cout<<dequeue()<<" ";
        ++count;
        enqueue(r,c+1);
    }
    return 0;
}
