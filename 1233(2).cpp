#include <iostream>
using namespace std;

int n,m,start,M,ans=0;
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
void dfs(int st,int i){
    if(i==0&&st!=start){
        ++ans;
        return;
    }
    node *tmp=elem[st].next;
    while(tmp!=NULL){
        if(!visited[tmp->value]){
            visited[st]=true;
            dfs(tmp->value,i-1);
            visited[st]=false;
        }
        tmp=tmp->next;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num1,num2;
    cin>>n>>m>>start>>M;
    elem=new node[n+1];
    visited=new bool[n+1];
    for (int i=0;i<=n;++i){
        elem[i].next=NULL;
        visited[i]=false;
    }
    for(int i=1;i<=m;++i){
        cin>>num1>>num2;
        insert(num1,num2);
    }
    visited[start]=true;
    dfs(start,M);
    cout<<ans;
    delete [] elem;
    delete [] visited;
    return 0;
}
