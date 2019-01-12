#include <iostream>
#define mx 400002
using namespace std;

class proque{
    int size;
    int *elem;
    int len;
    void preDown(int hole);
    void buildHeap();
public:
    proque(int sz=10){
        size=sz;
        len=0;
        elem=new int[sz];
    }
    ~proque(){delete [] elem;}
    void push(const int &nd){
        int hole=++len;
        for(;hole>1&&elem[hole/2]>nd;hole/=2)
            elem[hole]=elem[hole/2];
        elem[hole]=nd;
    }
    int pop(){
        int max_x=elem[1];
        elem[1]=elem[len--];
        preDown(1);
        return max_x;
    }
    bool isEmpty() const {return len==0;}
};
void proque::buildHeap(){for(int k=len/2;k>0;--k) preDown(k);}
void proque::preDown(int hole){
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
int N,M;
long long MPL=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,zero,num;
    proque q(mx);
    cin>>N>>M;
    int n_tmp=N;
    while((N-1)%(M-1))++N;
    for(i=1;i<=N-n_tmp;++i)q.push(0);
    for(i=1;i<=n_tmp;++i){cin>>num;q.push(num);}
    int sum=0;
    while(!q.isEmpty()){
        sum=0;
        for(i=1;i<=M&&!q.isEmpty();++i){
            int tmp=q.pop();
            sum+=tmp;
        }
        MPL+=sum;
        if(q.isEmpty()) break;
        q.push(sum);
    }
    cout<<MPL;
    return 0;
}
