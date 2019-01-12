#include <iostream>
using namespace std;
long int mx=-2147483647;
class queue{
    private:
        long int *elem;
        long int size;
        long int front;
        long int rear;
        void doubleSpace();
    public:
        queue(long int sz){
            elem=new long int[sz];
            size=sz;
            front=rear=0;
        }
        ~queue(){delete [] elem;}
        bool isEmpty(){return front==rear;}
        void enqueue(const long int &x){
            if((rear+1)%size==front)doubleSpace();
            rear=(rear+1)%size;
            elem[rear]=x;
        }
        long int dequeue(){
            front=(front+1)%size;
            return elem[front];
        }
        long int getHead(){
            return elem[(front+1)%size];
        }
        long int findMx(){
            long int ft=front,r=rear;
            ft=(ft+1)%size;
            long int tp=elem[ft];
            for(;ft!=r;ft=(ft+1)%size){
                if(elem[ft]>tp)tp=elem[ft];
            }
            return tp;
        }
};
void queue::doubleSpace(){
    long int *tmp=elem;
    elem=new long int[2*size];
    for(long int k=0;k<size;++k){
        elem[k]=tmp[k];
    }
    front=0;rear=size;
    size*=2;
    delete [] tmp;
}
int main(){
    long int n,k,i,j,num,ct=1;
    cin>>k>>n;
    queue q(n);
    long int elem0[n];
    for(i=0;i<n;++i){
        cin>>num;
        if(i<k){
            q.enqueue(num);
            if(num>mx) mx=num;
            elem0[0]=mx;
        }
        else{
            if(mx==q.getHead()) {
                q.dequeue();
                q.enqueue(num);
                mx=q.findMx();
            }
            else {
                q.dequeue();
                q.enqueue(num);
            }

            if(num>mx){elem0[ct]=num;mx=num;}
            else elem0[ct]=mx;
            ++ct;
        }
    }
    for(i=0;i<ct;++i)cout<<elem0[i]<<" ";
    return 0;
}

