#include <iostream>
#include <cstring>
using namespace std;

class prQueue{
    private:
        int *elem;
        int size;
        int len;
        void doubleSpace();
        void preDown(int i);
        void buildHead();
    public:
        prQueue(int sz){
            elem=new int[sz];
            size=sz;
            len=0;
        }
        ~prQueue(){delete [] elem;}
        bool isEmpty(){return len==0;}
        void insertx(const int &x){
            if(len==size-1)doubleSpace();
            int hole=++len;
            for(;hole>1&&x<elem[hole/2];hole/=2){
                elem[hole]=elem[hole/2];
            }
            elem[hole]=x;
        }
        int find(int x){
            int minIndex=2147483646,k,i,mn=0;
            for(i=1;i<=len;++i){
                if(elem[i]>x&&elem[i]<minIndex){
                    minIndex=elem[i];
                    mn=i;
                }
            }
            return mn;
        }
        void decreasex(int i, int vl){
            elem[i]-=vl;
            int tmp=elem[i];
            for(;i>1&&tmp<elem[i/2];i/=2){
                elem[i]=elem[i/2];
            }
            elem[i]=tmp;
        }
};
void prQueue::doubleSpace(){
    int *tmp=elem;
    elem=new int[2*size];
    for(int k=0;k<size;++k){
        elem[k]=tmp[k];
    }
    size*=2;
    delete [] tmp;
}
void prQueue::buildHead(){
    for(int k=len/2;k>0;--k){
        preDown(k);
    }
}
void prQueue::preDown(int hole){
    int child;
    int tmp=elem[hole];
    for(;hole*2<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1]<elem[child]) ++child;
        if(elem[child]<tmp)elem[hole]=elem[child];
        else break;
    }
    elem[hole]=tmp;
}
int main(){
    int m,i,num,value;
    string str;
    cin>>m;
    prQueue q(m+2);
    for(i=0;i<m;++i){
        cin>>str;
        if(str[0]=='i'){
            cin>>num;
            q.insertx(num);
        }
        if(str[0]=='f'){
            cin>>num;
            cout<<q.find(num)<<endl;
        }
        if(str[0]=='d'){
            cin>>num>>value;
            q.decreasex(num,value);
        }
    }
    return 0;
}
