#include <iostream>
using namespace std;

int N,X,Y,ans;
struct tree{
    int left,right,parent;
};
tree *elem;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>N>>X>>Y;
    elem=new tree[N+2];
    int elem0[N+2],elem1[N+1];
    for(i=0;i<N;++i){
        elem[i].parent=elem[i].left=elem[i].right=0;
    }
    for(i=1;i<=N;++i){
        cin>>elem[i].left>>elem[i].right;
        elem[elem[i].left].parent=i;
        elem[elem[i].right].parent=i;
    }
    int ct1=1,ct2=1;
    elem0[0]=X;
    elem1[0]=Y;
    while(elem[X].parent!=0){
        X=elem[X].parent;
        elem0[ct1++]=X;
    }
    while(elem[Y].parent!=0){
        Y=elem[Y].parent;
        elem1[ct2++]=Y;
    }
    bool flag=false;
    for(i=0;i<ct1;++i){
        for(j=0;j<ct2;++j){
            if(elem0[i]==elem1[j]){
                ans=elem0[i];
                flag=true;
                break;
            }
        }
        if(flag)break;
    }
    cout<<ans<<endl;
    return 0;
}
/*
9 7 6
6 7
1 3
4 5
8 0
0 9
0 0
0 0
0 0
0 0
*/

