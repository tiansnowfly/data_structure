#include <iostream>
using namespace std;

struct tree{
    int left,right,parent,value;
};
tree *reTree;
int N;
class queue{
    private:
        int *elem;
        int maxSize;
        int front,rear;
        void doubleSpace();
    public:
        queue(int initSize=50){
            elem=new int[initSize];
            front=rear=0;
            maxSize=initSize;
        }
        ~queue(){delete [] elem;}
        bool isEmpty()const {return front==rear;}
        int enqueue(const int &x){
            if((rear+1)%maxSize==front) doubleSpace();
            rear=(rear+1)%maxSize;
            elem[rear]=x;
        }
        int dequeue(){
            front=(front+1)%maxSize;
            return elem[front];
        }
        int getHead()const {return elem[(front+1)%maxSize];}
};
void queue::doubleSpace(){
    int *tmp=elem;
    elem=new int[2*maxSize];
    for(int h=0;h<maxSize;++h){
        elem[h]=tmp[h];
    }
    maxSize*=2;
    delete [] tmp;
}
int main(){
    int i;
    cin>>N;
    reTree=new tree[N+2];
    for(i=1;i<=N;++i){
        reTree[i].left=reTree[i].right=reTree[i].parent=reTree[i].value=0;
    }
    for(i=1;i<=N;++i){
        cin>>reTree[i].left>>reTree[i].right>>reTree[i].value;
        if(reTree[i].left!=0)reTree[reTree[i].left].parent=i;
        if(reTree[i].right!=0)reTree[reTree[i].right].parent=i;
    }
    int k=1;
    while(reTree[k].parent!=0)k=reTree[k].parent;
    queue que(N+2);

    que.enqueue(k);
    while(!que.isEmpty()){
        k=que.dequeue();
        cout<<reTree[k].value<<" ";
        if(reTree[k].left!=0)que.enqueue(reTree[k].left);
        if(reTree[k].right!=0)que.enqueue(reTree[k].right);
    }
    delete [] reTree;
    return 0;
}
