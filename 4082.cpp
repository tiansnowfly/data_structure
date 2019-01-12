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
int elem[1000][1000];
bool mark[1000];
int degree[1000];
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    que<int> q(1000);
    int i,j,k;
    cin>>n>>m;
    for(k=1;k<=m;++k){
        cin>>i>>j;
        elem[i][j]=1;
        ++degree[i];
        ++degree[j];
    }
    int tmp;
    for(k=0;k<=n;++k){
        int ct=0,sum=0;
        if(mark[k]) continue;
        q.enqueue(k);
        mark[k]=true;
        while(!q.isEmpty()){
            tmp=q.dequeue();
            sum+=degree[tmp];
            ++ct;
            for(i=0;i<=n;++i){
                if((elem[i][tmp]==1||elem[tmp][i]==1)&&!mark[i]) {
                    q.enqueue(i);
                    mark[tmp]=true;
                }
            }
        }
        ans+=(ct*(ct-1)-sum)/2;
    }
    cout<<ans;
    return 0;
}
