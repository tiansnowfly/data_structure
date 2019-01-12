#include <iostream>
using namespace std;

template<class T>
class que{
private:
    T *elem;
    int size;
    int front;
    int rear;
    void doubleSpace();
public:
    que(int sz=102){
        size=sz;
        elem=new T[size];
        rear=front=0;
    }
    ~que(){delete [] elem;}
    T dequeue(){
        front=(front+1)%size;
        return elem[front];
    }
    void enqueue(const T &x){
        if((rear+1)%size==front) doubleSpace();
        rear=(rear+1)%size;
        elem[rear]=x;
    }
    bool isEmpty(){return front==rear;}
    T getHead()const {return elem[(front+1)%size];}
};
template <class T>
void que<T>::doubleSpace(){
    T *tmp=elem;
    elem=new T[size*2];
    for(int k=1;k<=size;++k)elem[k]=tmp[(front+k)%size];
    front=0;
    rear=size;
    size*=2;
    delete [] tmp;
}

int n,m;
bool *visited;
struct node{
    int value;
    node *next;
    node(){value=0;next=NULL;}
};
node *elem;
void insert(int num1,int num2){
    node *tmp=&elem[num1];
    while(tmp->next!=NULL) tmp=tmp->next;
    tmp->next=new node;
    tmp->next->value=num2;
    tmp->next->next=NULL;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,num1,num2;
    cin>>n>>m;
    que<int> q(n+1);
    elem=new node[n+1];
    visited=new bool[n+1];
    int inDegree[n+1]={0};
    for(i=1;i<=m;++i){
        cin>>num1>>num2;
        insert(num1,num2);
        insert(num2,num1);
        ++inDegree[num1];
        ++inDegree[num2];
    }
    int tmp,ans=0;
    for(i=0;i<=n;++i){
        int sum=0,ct=0;
        if(visited[i]) continue;
        q.enqueue(i);
        visited[i]=true;
        while(!q.isEmpty()){
            tmp=q.dequeue();
            ++ct;
            sum+=inDegree[tmp];
            node *cur=elem[tmp].next;
            while(cur!=NULL){
                if(!visited[cur->value]){
                    q.enqueue(cur->value);
                    visited[cur->value]=true;
                }
                cur=cur->next;
            }
        }
        ans+=(ct*(ct-1)-sum)/2;
    }
    cout<<ans;
    return 0;
}
