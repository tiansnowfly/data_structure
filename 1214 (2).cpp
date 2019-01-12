#include <iostream>
using namespace std;

struct tree{
    int son,brother,parent,value;
    int timePop;
};
tree *sbTree;
int N;
class stack{
    private:
        char *elem;
        int top_p;
        int maxSize;
        void doubleSpace();
    public:
        stack(int initSize){
            elem=new char[initSize];
            maxSize=initSize;
            top_p=-1;
        }
        ~stack(){delete [] elem;}
        bool isEmpty() const{return top_p==-1;}
        void push(const char &x){
            if(top_p==maxSize-1) doubleSpace();
            elem[++top_p]=x;
        }
        char pop(){return elem[top_p--];}
        char top()const {return elem[top_p];}
};
void stack::doubleSpace(){
    char *tmp=elem;

    elem=new char[2*maxSize];

    for(int i=0;i<maxSize;++i){
        elem[i]=tmp[i];
        maxSize*=2;
        delete [] tmp;
    }
}
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
    stack st0(N+2);
    st0.push(rt);
    while(!st0.isEmpty()){
        rt=st0.pop();
        cout<<sbTree[rt].value<<" ";
        if(sbTree[rt].brother!=0)st0.push(sbTree[rt].brother);
        if(sbTree[rt].son!=0)st0.push(sbTree[rt].son);
    }

}
void postOrder(int rt){
    stack st1(N+2);
    st1.push(rt);
    while(!st1.isEmpty()){
        rt=st1.pop();
        if(++sbTree[rt].timePop==2){
            cout<<sbTree[rt].value<<" ";
            if(sbTree[rt].brother!=0)st1.push(sbTree[rt].brother);
        }
        else{
            st1.push(rt);
            if(sbTree[rt].son!=0)st1.push(sbTree[rt].son);
        }
    }
}
void levelOrder(int rt){
    queue que(N+2);
    que.enqueue(rt);
    while(sbTree[rt].brother!=0){
        que.enqueue(sbTree[rt].brother);
        rt=sbTree[rt].brother;
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
        sbTree[i].brother=sbTree[i].parent=sbTree[i].son=sbTree[i].value=sbTree[i].timePop=0;
    }
    for(i=1;i<=N;++i){
        cin>>sbTree[i].son>>sbTree[i].brother>>sbTree[i].value;
        if(sbTree[i].son!=0)sbTree[sbTree[i].son].parent=i;
        if(sbTree[i].brother!=0)sbTree[sbTree[i].brother].parent=sbTree[i].parent;
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
