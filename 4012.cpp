#include <iostream>
using namespace std;
class prQueue{
    private:
        int size;
        int currentLen;
        int *elem;
        void doubleSpace();
        void buildHead();
        void preDown(int hl);
    public:
        prQueue(int sz){
            elem=new int[sz];
            currentLen=0;
            size=sz;
        }
        prQueue(const int array[],int sz);
        ~prQueue(){delete [] elem;}
        void enqueue(const int &x){
            if(currentLen==size-1) doubleSpace();

            int hole=++currentLen;
            for(;hole>1&&x<elem[hole/2];hole/=2){
                elem[hole]=elem[hole/2];
            }
            elem[hole]=x;
        }
        int dequeue(){
            int minN;
            minN=elem[1];
            elem[1]=elem[currentLen--];
            preDown(1);
            return minN;
        }
        bool isEmpty() const {return currentLen==0;}
        int getHead()const {return elem[1];}

};
prQueue::prQueue(const int *dt,int len){
    currentLen=len;
    size=len+10;
    elem=new int[size];
    for(int i=0;i<len;++i) elem[i+1]=dt[i];
}
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
    for(int k=currentLen/2;k>0;--k){
        preDown(k);
    }
}
void prQueue::preDown(int hole){
    int child;
    int tmp=elem[hole];
    for(;hole*2<=currentLen;hole=child){
        child=2*hole;
        if(child!=currentLen&&elem[child+1]<elem[child]) ++child;
        if(elem[child]<tmp)elem[hole]=elem[child];
        else break;
    }
    elem[hole]=tmp;
}
int main(){
    int num,kind,i;
    cin>>kind;
    prQueue q(kind);
    for(i=0;i<kind;++i){
        cin>>num;
        q.enqueue(num);
    }
    int tmp,sum=0;
    while (!q.isEmpty()){
        tmp=q.dequeue()+q.dequeue();
        sum+=tmp;
        if(q.isEmpty())break;
        q.enqueue(tmp);
    }
    cout<<sum;
    return 0;
}
