#include <iostream>
#include <fstream>
using namespace std;

class Heap{
private:
    int *elem;
    int size;
    int len;
public:
    Heap(int sz){
        size=sz;
        elem=new int[size];
        len=0;
    }
    ~Heap(){delete [] elem;}
    void buildHeap(){
        for(int k=len/2;k>0;--k) preDown(k);
    }
    void preDown(int hole){
        int child;
        int tmp=elem[hole];
        for(;hole*2<=len&&elem[hole]>elem[hole*2];hole=child){
            child=2*hole;
            if(child!=len&&elem[child+1]<elem[child])++child;
            if(tmp>elem[child])elem[hole]=elem[child];
            else break;
        }
        elem[hole]=tmp;
    }
    void insert(const int &x){
        int hole=++len;
        for(;hole>1&&x<elem[hole/2];hole/=2) elem[hole]=elem[hole/2];
        elem[hole]=x;
    }
    int pop(){
        int minX=elem[1];
        elem[1]=elem[len--];
        preDown(1);
        return minX;
    }
    int getHead(){return elem[1];}
};
int main(){
    freopen("poi.in","r",stdin);
    freopen("poi.out","w",stdout);
    int N,i,mid,num1,num2,ct=1,seq1,seq2,seq3;
    cin>>N;
    int elem0[N];
    Heap p1(N),p2(N);
    cin>>mid;
    elem0[1]=mid;
    for(i=2;i<N;i=i+2){
        cin>>num1>>num2;
        if(mid>=num1&&mid>=num2&&num1>=num2){
            seq1=num2;seq2=num1;seq3=mid;
        }
        else if(num1>=num2&&num1>=mid&&num2>=mid){
            seq1=mid;seq2=num2;seq3=num1;
        }
        else{
            seq1=num1;seq2=mid;seq3=num2;
        }
        p1.insert(-seq1);
        p2.insert(seq3);
        if(seq2<=p2.getHead()&&seq2>=-p1.getHead())mid=seq2;
        else if(p2.getHead()<seq2){
            mid=p2.pop();
            p2.insert(seq2);
        }
        else{
            mid=-p1.pop();
            p1.insert(seq2);
        }
        elem0[++ct]=mid;
    }
    cin.get();
    for(i=1;i<=ct;++i)cout<<elem0[i]<<endl;
    return 0;
}
