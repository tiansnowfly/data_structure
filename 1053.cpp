#include <iostream>
#define mx 100001
using namespace std;
struct array{
    int x,y,z;
};
array *pos,*tmp;
int n,m;
void exchange(int &x,int &y){
    int tmp0;
    tmp0=x;
    x=y;
    y=tmp0;
}
int find(int x,int y){
    for(int k=0;k<n;++k){
        if(pos[k].x==x&&pos[k].y==y)
        return pos[k].z;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pos=new array[mx];
    tmp=new array[mx];
    int i,flag;
    cin>>n;
    for(i=0;i<n;++i)tmp[i].x=tmp[i].y=i;
    for(i=0;i<n;++i)cin>>pos[i].x>>pos[i].y>>pos[i].z;
    cin>>m;
    int tmpx,tmpy;
    for(i=0;i<m;++i){
        cin>>flag>>tmpx>>tmpy;
        if(flag==0)exchange(tmp[tmpx].x,tmp[tmpy].x);
        else if(flag==1)exchange(tmp[tmpx].y,tmp[tmpy].y);
        else{cout<<find(tmp[tmpx].x,tmp[tmpy].y)<<'\n';}
    }
    return 0;
}
