#include <iostream>
using namespace std;
bool **original;
int **home, **cere;
int home_pos, cere_pos, stores=0, n, m;
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

bool in(int x,int y){
    return (x>=0&&x<m&&y>=0&&y<n);
}
void search(int **map,int start){
    int search_count=0;
    queue q;
    q.enqueue(start);
    int x,y;
    map[start/n][start%n]=1;
    while (!q.isEmpty()){
        x=q.getHead()/n;
        y=q.getHead()%n;
        if(original[x][y])++search_count;
        if(search_count>=stores)return;
        q.dequeue();
        if(in(x-1,y)&&map[x-1][y]==0){
            q.enqueue((x-1)*n+y);
            map[x-1][y]=map[x][y] + 1;
        }
        if(in(x,y-1)&&map[x][y-1]==0){
            q.enqueue(x*n+y-1);
            map[x][y-1]=map[x][y] + 1;
        }
        if(in(x+1,y)&&map[x+1][y]==0){
            q.enqueue((x+1)*n+y);
            map[x+1][y]=map[x][y]+1;
        }
        if(in(x, y+1)&&map[x][y+1]==0){
            q.enqueue(x*n+y+1);
            map[x][y+1]=map[x][y]+1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,t,x,y,min=2000000;
    cin>>n>>m;;
    queue ps;
    original=new bool*[m];
    home=new int*[m];
    cere=new int*[m];
    for (i=0;i<m;++i){
        original[i] = new bool[n];
        home[i]=new int[n];
        cere[i]=new int[n];
        for (j=0;j<n;++j){
            cin>>t;
            original[i][j]=(t==4);
            cere[i][j]=home[i][j]=(t==1)?-1:0;
            if (t==2)cere_pos =i*n+j;
            else if (t==3) home_pos=i*n+j;
            else if (t==4){
                ps.enqueue(i*n+j);
                ++stores;
            }
        }
    }
    search(cere,cere_pos);
    search(home,home_pos);
    while (!ps.isEmpty()){
        x=(ps.getHead())/n;
        y=(ps.getHead())%n;
        ps.dequeue();
        if (cere[x][y]!=0){
            t=cere[x][y]+home[x][y]-2;
            if (t<min)min=t;
        }
    }
    for (i=0;i<m;++i){
        delete [] original[i];
        delete [] home[i];
        delete [] cere[i];
    }
    delete [] original;
    delete [] home;
    delete [] cere;
    cout<<"\n"<<min;
}
