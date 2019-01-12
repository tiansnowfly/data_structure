#include <iostream>
#define mx 1000
using namespace std;

int quick_ex_times=0,merge_ex_times=0,heap_times=0;
int elem[mx];
int N,k0,len=0;

void enque(const int &x){
    int hole=++len;
    for(;hole>1;hole/=2){
        ++heap_times;
        if(x<elem[hole/2]) elem[hole]=elem[hole/2];
        else break;
    }
    elem[hole]=x;
}

void merge(int a[],int low,int mid,int high){
    int *tmp=new int[high-low+1];
    int i=low,j=mid,k=0;
    while(i<mid&&j<=high){
        if(a[i]<a[j])tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
        ++merge_ex_times;
    }
    while(i<mid)tmp[k++]=a[i++];
    while(j<=high) tmp[k++]=a[j++];
    for(i=0,k=low;k<high;)a[k++]=tmp[i++];
    delete tmp;
}
void mergeSort(int a[],int low,int high){
    int mid=(low+high-1)/2;
    if(low==high)return;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid+1,high);
}
int divide(int a[],int low,int high){
    int k=a[low];
    do{
        while(low<high&&k<=a[high]){--high;++quick_ex_times;}
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&k>=a[low]){++low;++quick_ex_times;}
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
    int i;
    cin>>N>>k0;
    for(i=1;i<=N;++i)cin>>elem[i];
    if(k0==1){
        for(i=1;i<=N;++i)enque(elem[i]);
        cout<<heap_times+1;
    }
    else if(k0==2){
        mergeSort(elem,1,N);
        cout<<merge_ex_times;
    }
    else{
        quickSort(elem,1,N);
        cout<<quick_ex_times+1;
    }
    return 0;
}
