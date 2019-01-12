#include <iostream>
using namespace std;

struct tree{
    int son,brother,parent,value;
    int timePop;
};
tree *sbTree;
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
void preOrder(int rt){
     cout<<sbTree[rt].value<<" ";
     if(sbTree[rt].son!=0)preOrder(sbTree[rt].son);
     if(sbTree[rt].brother!=0)preOrder(sbTree[rt].brother);
}
void postOrder(int rt){
     if(sbTree[rt].son!=0)postOrder(sbTree[rt].son);
     cout<<sbTree[rt].value<<" ";
     if(sbTree[rt].brother!=0)postOrder(sbTree[rt].brother);
}
void levelOrder(int root){
    queue que(N+2);
    int rt=root;
    que.enqueue(root);
    while(sbTree[rt].brother!=0){
        rt=sbTree[rt].brother;
        que.enqueue(rt);
    }
    while(!que.isEmpty()){
        rt=que.dequeue();
        cout<<sbTree[rt].value<<" ";
        if(sbTree[rt].son!=0){
            que.enqueue(sbTree[rt].son);
            rt=sbTree[rt].son;
            while(sbTree[rt].brother!=0){
                rt=sbTree[rt].brother;
                que.enqueue(rt);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin>>N;
    sbTree=new tree[N+1];
    for(i=1;i<=N;++i){
        sbTree[i].brother=sbTree[i].parent=sbTree[i].son=sbTree[i].value=0;
    }
    for(i=1;i<=N;++i){
        cin>>sbTree[i].son>>sbTree[i].brother>>sbTree[i].value;
        if(sbTree[i].son!=0)sbTree[sbTree[i].son].parent=i;
        if(sbTree[i].brother!=0)sbTree[sbTree[i].brother].parent=i;
    }
    int k=1;
    while(sbTree[k].parent!=0)k=sbTree[k].parent;
    preOrder(k);
    cout<<endl;
    postOrder(k);
    cout<<endl;
    levelOrder(k);
    delete [] sbTree;
    return 0;
}
