#include <iostream>
#include <iomanip>
using namespace std;
long long N,boyTime=0,girlTime=0;
class queue{
    private:
        int *elem;
        int size;
        int front;
        int rear;
        void doubleSpace();
    public:
        queue(int sz){
            elem=new int[sz];
            size=sz;
            front=rear=0;
        }
        ~queue(){delete [] elem;}
        bool isEmpty(){return front==rear;}
        void enqueue(const int &x){
            if((rear+1)%size==front)doubleSpace();
            rear=(rear+1)%size;
            elem[rear]=x;
        }
        int dequeue(){
            front=(front+1)%size;
            return elem[front];
        }
        int getHead(){
            return elem[(front+1)%size];
        }
};
void queue::doubleSpace(){
    int *tmp=elem;
    elem=new int[2*size];
    for(int k=0;k<size;++k){
        elem[k]=tmp[k];
    }
    front=0;rear=size;
    size*=2;
    delete [] tmp;
}
int main(){
    int i,num,boy,girl,sum=0,sex,len,countBoy=0,countGirl=0;
    cin>>N;

    queue song(N+2);
    for(i=0;i<N;++i){
        cin>>len;
        song.enqueue(sum);
        sum+=len;
    }
    cin>>num;
    queue q1(num+2),q2(num+2);
    for(i=0;i<num;++i){
        cin>>sex;
        if(sex==1){
            cin>>boy;
            ++countBoy;
            q1.enqueue(boy);
        }
        else{
            cin>>girl;
            ++countGirl;
            q2.enqueue(girl);
        }
    }
    while(!song.isEmpty()){
        if(q1.isEmpty()||q2.isEmpty()) break;
        while(q1.getHead()<=song.getHead()&&q2.getHead()<=song.getHead()){
            boyTime+=song.getHead()-q1.dequeue();
            girlTime+=song.getHead()-q2.dequeue();
        }
        song.dequeue();
    }
    song.enqueue(sum);
    while(!q1.isEmpty())boyTime+=song.getHead()-q1.getHead();
    while(!q2.isEmpty())girlTime+=song.getHead()-q2.getHead();
    cout<<fixed<<setprecision(2)<<double(boyTime)/countBoy<<" "<<double(girlTime)/countGirl;
    return 0;
}
