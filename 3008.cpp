#include <iostream>
using namespace std;

struct node{
    int x;
    int y;
    int len;
};
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
char arr[102][102];
bool flag[102][102];
int next_x[4]={1,0,0,-1},next_y[4]={0,1,-1,0};
int n,m,x1,x2,y1,y2,ans=-1;
que<node> q;

void bfs(){
    node now;
    now.len=0;
    now.x=x1;
    now.y=y1;
    flag[now.x][now.y]=true;
    q.enqueue(now);
    while(!q.isEmpty()){
        now=q.dequeue();
        for(int i=0;i<=3;++i){
            if(i==0||i==3){if(arr[now.x][now.y]=='-')continue;}
            if(i==1||i==2){if(arr[now.x][now.y]=='|')continue;}
            node new_node;
            new_node.x=now.x+next_x[i];
            new_node.y=now.y+next_y[i];
            new_node.len=now.len+1;
            if(new_node.x<1||new_node.y<1||new_node.x>n||new_node.y>m)continue;
            if(flag[new_node.x][new_node.y]||arr[new_node.x][new_node.y]=='*') continue;
            if(i==0||i==3){if(arr[new_node.x][new_node.y]=='-')continue;}
            if(i==1||i==2){if(arr[new_node.x][new_node.y]=='|')continue;}
            q.enqueue(new_node);
            flag[new_node.x][new_node.y]=true;
            if(new_node.x==x2&&new_node.y==y2){
                ans=new_node.len;
                return;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            cin>>arr[i][j];
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
/*
4 5
2 2 3 4
.....
..**.
.**..
.....
*/
