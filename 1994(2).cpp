#include<iostream>
using namespace std;

int n,m,num;
bool land[501][501];
bool flag[501][501];

void make_sea(int x, int y){
    if(x-1>0&&land[x-1][y]&&!flag[x-1][y]){flag[x-1][y]=true;make_sea(x-1,y);}
    if(x+1<=n&&land[x+1][y]&&!flag[x+1][y]){flag[x+1][y]=true;make_sea(x+1,y);}
    if(y-1>0&&land[x][y-1]&&!flag[x][y-1]){flag[x][y-1]=true;make_sea(x,y-1);}
    if(y+1<=n&&land[x][y+1]&&!flag[x][y+1]){flag[x][y+1]=true;make_sea(x,y+1);}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            cin>>num;
            if(num==0) land[i][j]=true;
        }
    num=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(land[i][j]&&!flag[i][j]){
                num++;
                make_sea(i,j);
            }
    cout<<num;
}
