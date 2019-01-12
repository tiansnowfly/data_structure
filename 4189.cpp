//#include <iostream>
//#include <fstream>
//using namespace std;
#include <cstdio>

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
        for(;hole*2<=len;hole=child){
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
    //freopen("poi.in","r",stdin);
    //freopen("poi.out","w",stdout);
    int N,i,mid,num1,num2,ct=1,min_x,max_x;
    scanf("%d",&N);
    int elem0[N];
    Heap p1(N),p2(N);
    scanf("%d",&mid);
    elem0[1]=mid;
    for(i=2;i<N;i=i+2){
        scanf("%d%d",&num1,&num2);
        if(num1>mid&&num2>mid){
            min_x=num1<num2?num1:num2;
            max_x=num1>num2?num1:num2;
            p1.insert(-mid);
            p2.insert(max_x);
            if(-p1.getHead()<=min_x&&p2.getHead()>=min_x){
                mid=min_x;
            }
            else if(-p1.getHead()>min_x){
                mid=-p1.pop();
                p1.insert(-min_x);
            }
            else {
                mid=p2.pop();
                p2.insert(min_x);
            }

        }
        else if(num1<mid&&num2<mid){
            min_x=num1<num2?num1:num2;
            max_x=num1>num2?num1:num2;
            p1.insert(-min_x);
            p2.insert(mid);
            if(-p1.getHead()<=max_x&&p2.getHead()>=max_x){
                mid=max_x;
            }
            else if(-p1.getHead()>max_x){
                mid=-p1.pop();
                p1.insert(-max_x);
            }
            else {
                mid=p2.pop();
                p2.insert(max_x);
            }
        }
        else{
            min_x=num1<num2?num1:num2;
            max_x=num1>num2?num1:num2;
            p1.insert(-min_x);
            p2.insert(max_x);
        }
        elem0[++ct]=mid;
    }
    for(i=1;i<=ct;++i)printf("%d\n",elem0[i]);
    return 0;
}
