#include <iostream>
using namespace std;

void quicksort(int data[],int low,int high);
int divide(int data[],int low,int high);
int main(){
    int N,minSum,low=0,high;

    cin>>N;
    int data[N];
    high=N-1;
    for(int i=0;i<N;++i){
        cin>>data[i];
    }
    quicksort(data,low,high);
    for(int i=0;i<N;++i){
        cout<<data[i];
    }
    return 0;
}
void quicksort(int data[],int low,int high){
    int mid;
    if(low>=high)return;
    mid=divide(data,low,high);
    quicksort(data,low,mid-1);
    quicksort(data,mid+1,high);
}
int divide(int data[],int low,int high){
    int k=data[low];
    do{
        while(low<high&&data[high]>=k){
            --high;
            if(low<high){data[low]=data[high];++low;}
        }
        while(low<high&&data[low]<=k){
            ++low;
            if(low<high){data[high]=data[low];--high;}
        }
    }while (low!=high);
    data[low]=k;
    return low;
}
