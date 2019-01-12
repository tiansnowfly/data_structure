#include <iostream>
using namespace std;

int judge(int x,int y,int n){
    int tmp1,tmp2;
    tmp1=x<=y?x:y;
    tmp2=(n+1-x)<=(n+1-y)?(n+1-x):(n+1-y);
    tmp1=tmp1<=tmp2?tmp1:tmp2;
    return tmp1-1;
}
int main(){
    int n,x,y,tmp,S=0;
    cin>>n>>x>>y;

    int nx=n+1-x,ny=n+1-y;
    tmp=judge(x,y,n);
    if(x<nx&&x<=y&&x<ny){
        S=4*(x-1)*(n-x+1)+y-x+1;
    }
    if(ny<=x&&ny<y&&ny<nx){
        S=4*(ny-1)*(n-ny+1)+n-2*tmp-1+x-ny+1;
    }
    if(nx<y&&nx<=ny&&nx<x){
        S=4*(nx-1)*(n-nx+1)+2*(n-2*tmp-1)+nx-y+1;
    }
    if(y<=nx&&y<x&&y<ny){
        S=4*(y-1)*(n-y+1)+3*(n-2*tmp-1)+ny-x+1;
    }
    if(y==nx&&y==x&&y==ny){S=n*n;}
    cout<<S-1;
    return 0;
}
