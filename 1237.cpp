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
int n,m;
struct edge{
    int end;
    edge *next;
    edge(int e,edge *nt=NULL){end=e;next=nt;}
};
struct ver{
    int point;
    edge *head;
    ver(edge *h=NULL){head=h;}
};
ver *elem=new ver[n+1];

int find_less_time(){
    que<int> q1(n+1),q2(n+1);
    edge *p;
    int i,current,semester=1;
    int *inDegree=new int[n+1];
    for(i=1;i<=n;++i) inDegree[i]=0;
    for(i=1;i<=n;++i){
        for(p=elem[i].head;p!=NULL;p=p->next){
            ++inDegree[p->end];
        }
    }
    for(i=1;i<=n;++i)if(inDegree[i]==0) q1.enqueue(i);
    while(true){
        while(!q1.isEmpty()){
            current=q1.dequeue();
            for(p=elem[current].head;p!=NULL;p=p->next){
                if(--inDegree[p->end]==0) q2.enqueue(p->end);
            }
        }
        if(q2.isEmpty()) break;
        ++semester;
        while(!q2.isEmpty()){
            current=q2.dequeue();
            for(p=elem[current].head;p!=NULL;p=p->next){
                if(--inDegree[p->end]==0) q1.enqueue(p->end);
            }
        }
        if(q1.isEmpty()) break;
        ++semester;
    }
    return semester;
}

int main(){
    int i,num1,num2;
    cin>>n>>m;
    for(i=1;i<=m;++i){
        cin>>num1>>num2;
        elem[num1].head=new edge(num2,elem[num1].head);
    }
    int ans;
    ans=find_less_time();
    cout<<ans;
    return 0;
}
