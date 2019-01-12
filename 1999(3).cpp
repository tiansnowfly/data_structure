#include <iostream>
#include <queue>
#include <cstring>
#define mx 102
using namespace std;

int n,m,ct=1,mmin=99999;
int elem[mx][mx];
bool mark[mx][mx];
int xx[4]={0,-1,0,1};
int yy[4]={-1,0,1,0};
int box_box[6][6];
bool flag[6];
struct point{
    int x;
    int y;
    int step;
};
point box[6];
bool in(int x,int y){ return x>=0&&x<n&&y>=0&&y<m;}
int bfs(point a,point b){
    memset(mark,false,sizeof(mark));
    queue<point> q;
    q.push(a);
    mark[a.x][a.y]=true;
    point cur;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        point next;
        for(int i=0;i<4;++i){
            next.x=cur.x+xx[i];
            next.y=cur.y+yy[i];
            next.step=cur.step+1;
            if(!mark[next.x][next.y]&&elem[next.x][next.y]!=-1&&in(next.x,next.y)){
                if(next.x==b.x&&next.y==b.y) return next.step;
                q.push(next);
                mark[next.x][next.y]=true;
            }
        }
    }
    return -1;
}
void dfs(int start,int count_point,int sum_step){
    flag[start]=true;
    if(count_point==ct&&mmin>sum_step){
        mmin=sum_step;
    }
    for(int i=0;i<ct;++i){
        if(flag[i]||box_box[start][i]==-2) continue;
        flag[i]=true;
        dfs(i,count_point+1,sum_step+box_box[start][i]);
        flag[i]=false;
    }
}
int main(){
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            cin>>elem[i][j];
            if(elem[i][j]==2){
                box[0].x=i;
                box[0].y=j;
                box[0].step=0;
            }
            if(elem[i][j]==1){
                box[ct].x=i;
                box[ct].y=j;
                box[ct].step=0;
                ++ct;
            }
        }
    }
    int ans=0;
    for(i=0;i<ct;++i){
        for(j=0;j<ct;++j){
            if(i!=j)box_box[i][j]=bfs(box[i],box[j]);
            else box_box[i][j]=-2;
            if(box_box[i][j]==-1) ans=-1;
        }
    }
    if(ans==-1) cout<<"-1";
    else {dfs(0,1,0);cout<<mmin;}
    return 0;
}
