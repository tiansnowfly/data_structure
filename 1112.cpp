#include <iostream>
#define mx 1001
using namespace std;

struct node{
    int level;
    int number;
};
node *arr=new node[mx];
class proque{
    int size;
    node *elem;
    int len;
    void preDown(int hole);
    void buildHeap();
public:
    proque(int sz=10){
        size=sz;
        len=0;
        elem=new node[sz];
    }
    ~proque(){delete [] elem;}
    void push(const node &nd){
        int hole=++len;
        for(;hole>1&&elem[hole/2].level<nd.level;hole/=2)
            elem[hole]=elem[hole/2];
        elem[hole]=nd;
    }
    node pop(){
        node max_x=elem[1];
        elem[1]=elem[len--];
        preDown(1);
        return max_x;
    }
    bool isEmpty() const {return len==0;}
};
void proque::buildHeap(){for(int k=len/2;k>0;--k) preDown(k);}
void proque::preDown(int hole){
    int child;
    node tmp=elem[hole];
    for(;hole*2<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1].level>elem[child].level)++child;
        if(tmp.level<elem[child].level)elem[hole]=elem[child];
        else break;
    }
    elem[hole]=tmp;
}
int n,k;
int matrix[mx][mx];
bool flag[mx];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,student;
    proque p(mx);
    cin>>n>>k;
    for(i=1;i<=n;++i){
        cin>>arr[i].level;
        arr[i].number=i;
    }
    for(i=1;i<=k;++i){
        cin>>student;
        p.push(arr[student]);
        flag[student]=true;
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            cin>>matrix[i][j];
        }
    }
    while(!p.isEmpty()){
        node now=p.pop();
        cout<<now.number<<'\n';
        for(j=1;j<=n;++j){
            if(matrix[now.number][j]==1&&flag[j]==false){
                p.push(arr[j]);
                flag[j]=true;
            }
        }
    }
    return 0;
}
