#include <iostream>
using namespace std;

template<class T>
class que{
private:
    T *arr;
    int size;
    int front;
    int rear;
    void doubleSpace();
public:
    que(int sz=102){
        size=sz;
        arr=new T[size];
        rear=front=0;
    }
    ~que(){delete [] arr;}
    T dequeue(){
        front=(front+1)%size;
        return arr[front];
    }
    void enqueue(const T &x){
        if((rear+1)%size==front) doubleSpace();
        rear=(rear+1)%size;
        arr[rear]=x;
    }
    bool isEmpty(){return front==rear;}
    T getHead()const {return arr[(front+1)%size];}
};
template <class T>
void que<T>::doubleSpace(){
    T *tmp=arr;
    arr=new T[size*2];
    for(int k=1;k<=size;++k)arr[k]=tmp[(front+k)%size];
    front=0;
    rear=size;
    size*=2;
    delete [] tmp;
}
struct node{
    int value;
    node *next;
    node(){value=0;next=NULL;}
};
node *out;
void add(int num1,int num2){
    //++out[num2].value;
    node *tmp=&out[num1];
    while(tmp->next!=NULL) tmp=tmp->next;
    tmp->next=new node;
    tmp->next->value=num2;
    tmp->next->next=NULL;
}
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int start,M;
    cin>>n>>m>>start>>M;
    que<int> q1(n),q2(n);
    int num1,num2;
    out=new node[n+1];
    for(int i=1;i<=m;++i){
        cin>>num1>>num2;
        add(num1,num2);
    }
    /*for(int i=1;i<=n;++i){
        if(out[i].value==0){
            q1.enqueue(i);
            q2.enqueue(1);
        }
    }*/
    bool flag[n+1];
    q1.enqueue(start);
    //flag[start]=true;
    q2.enqueue(0);
    int ct=0,j,ans=0;
    node *tmp=out[2].next;
   // while(tmp!=NULL) {cout<<tmp->value<<endl;tmp=tmp->next;}
    while(!q1.isEmpty()){
        j=q1.dequeue();
        ct=q2.dequeue();
        if(ct==M&&j!=start)++ans;
        tmp=out[j].next;
        while(tmp!=NULL){
            q1.enqueue(tmp->value);
            //flag[tmp->value]=true;
            q2.enqueue(ct+1);
            /*--out[tmp->value].value;
            if(out[tmp->value].value==0){
                q1.enqueue(tmp->value);
                q2.enqueue(ct+1);
            }
            tmp=tmp->next;*/
            tmp=tmp->next;
        }
    }
    cout<<ans;
    return 0;
}
