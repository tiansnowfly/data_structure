#include <iostream>
#define mx 1000001
using namespace std;
int n,count=0;
int a[mx],b[mx];

class prqueue{
    private:
        struct node{
            int row,col,value;
        };
        node *elem;
        int size;
        int len;
        void doubleSpace();
        void buildHeap();
        void preDown(int i);
    public:
        prqueue(int sz=5000){
            size=sz;
            len=0;
            elem=new node[sz];
        }
        ~prqueue(){delete [] elem;}
        void enqueue(const int &r,const int &c){
            if(len==size-1) doubleSpace();
            int hole=++len;
            for(;hole>1&&a[r]+b[c]<elem[hole/2].value;hole/=2){
                elem[hole].value=elem[hole/2].value;
                elem[hole].row=elem[hole/2].row;
                elem[hole].col=elem[hole/2].col;
            }
            elem[hole].value=a[r]+b[c];
            elem[hole].row=r;
            elem[hole].col=c;
        }
        int dequeue(){
            int minx=elem[1].value;
            elem[1].value=elem[len].value;
            elem[1].row=elem[len].row;
            elem[1].col=elem[len].col;
            len--;
            preDown(1);
            return minx;
        }
        int getRow(){return elem[1].row;}
        int getCol(){return elem[1].col;}
};
void prqueue::doubleSpace(){
    node *tmp=elem;
    size*=2;
    elem=new node[size];
    for(int k=1;k<=len;++k){
        elem[k].value=tmp[k].value;
        elem[k].row=tmp[k].row;
        elem[k].col=tmp[k].col;
    }
    delete tmp;
}
void prqueue::preDown(int hole){
    int child;
    int tmp=elem[hole].value;
    int tmpr=elem[hole].row;
    int tmpc=elem[hole].col;
    for(;2*hole<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1].value<elem[child].value)++child;
        if(elem[child].value<tmp){
            elem[hole].value=elem[child].value;
            elem[hole].row=elem[child].row;
            elem[hole].col=elem[child].col;
        }
        else break;
    }
    elem[hole].value=tmp;
    elem[hole].row=tmpr;
    elem[hole].col=tmpc;
}
void prqueue::buildHeap(){
    for(int k=len/2;k>0;k--) preDown(k);
}
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
    prqueue q;
    cin>>n;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i)cin>>b[i];
    sort(1,n,a);
    sort(1,n,b);
    int r,c=1;
    for(i=1;i<=n;++i){q.enqueue(i,c);}
    while(count<n){
        r=q.getRow();
        c=q.getCol();
        cout<<q.dequeue()<<" ";
        ++count;
        q.enqueue(r,c+1);
    }
    return 0;
}
