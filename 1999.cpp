#include <iostream>
#define mx 100
using namespace std;

int n,m,ans=9999,ct=0,num_one=0;
int elem[mx][mx];
bool mark[mx][mx];
void dfs(int x,int y,int sp){
    mark[x][y]=true;
    if(ct==num_one){
        ans=ans<sp?ans:sp;
        return;
    }
    if(!mark[x-1][y]&&elem[x-1][y]!=-1){
        if(elem[x-1][y]==1)++ct;
        mark[x-1][y]=true;
        dfs(x-1,y,sp+1);
        mark[x-1][y]=false;
    }
    if(!mark[x+1][y]&&elem[x+1][y]!=-1){
        if(elem[x+1][y]==1)++ct;
        mark[x+1][y]=true;
        dfs(x+1,y,sp+1);
        mark[x+1][y]=false;
    }
    if(!mark[x][y-1]&&elem[x][y-1]!=-1){
        if(elem[x][y-1]==1)++ct;
        mark[x][y-1]=true;
        dfs(x,y-1,sp+1);
        mark[x][y-1]=false;
    }
    if(!mark[x][y+1]&&elem[x][y+1]!=-1){
        if(elem[x][y+1]==1)++ct;
        mark[x][y+1]=true;
        dfs(x,y+1,sp+1);
        mark[x][y+1]=false;
    }
    mark[x][y]=false;
}
int main(){
    int i,j,start_x,start_y;
    cin>>n>>m;
    for(i=0;i<=m+1;++i){elem[0][i]=-1;elem[n+1][i]=-1;}
    for(i=0;i<=n+1;++i){elem[i][0]=-1;elem[i][m+1]=-1;}
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            cin>>elem[i][j];
            if(elem[i][j]==2){start_x=i;start_y=j;}
            if(elem[i][j]==1)++num_one;
        }
    }
    int steps=0;
    dfs(start_x,start_y,steps);
    cout<<ans;
    return 0;
}
