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
int n, m, x1, y1, x2, y2,re;
char arr[105][105];
bool pass[105][105] = {false};
int xx[4]={1,0,0,-1};
int yy[4]={0,1,-1,0};
que<node> q;
void bfs(){
    node s;
    s.x = x1;
    s.y = y1;
    s.len = 0;
    q.enqueue(s);
    pass[x1][y1] = true;
    while(!q.isEmpty()){
        node now=q.dequeue();
        for(int i=0;i<4;++i){
            if (i==0 || i==3){if (arr[now.x][now.y] == '-') continue;}
            if (i==1 || i==2){if (arr[now.x][now.y] == '|') continue;}
            node New;
            New.x = now.x+xx[i];
            New.y = now.y+yy[i];
            New.len = now.len+1;
            if(New.x<1||New.y<1||New.x>n||New.y>m||pass[New.x][New.y]||arr[New.x][New.y]=='*')continue;
            if (i==0 || i==3){if (arr[New.x][New.y]=='-') continue;}
            if (i==1 || i==2){if (arr[New.x][New.y]=='|') continue;}
            q.enqueue(New);
            pass[New.x][New.y] = true;
            if(New.x==x2 && New.y==y2){re = New.len;return;}
        }
    }
    return;
}
int main(){
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    bfs();
    cout << re;
    return 0;
}
