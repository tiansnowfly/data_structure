#include <iostream>
using namespace std;

class DJS{
private:
    int volunm;
    int *father;
public:
    DJS(int sz=20){
        volunm=sz;
        father=new int[volunm];
        for(int k=1;k<=volunm;++k)father[k]=-1;
    }
    int search(int x){
        if(father[x]<0) return x;
        return father[x]=search(father[x]);
    }
    void merge(int root1,int root2){
        if(root1==root2)return;
        if(father[root1]<father[root2]){
            father[root1]+=father[root2];
            father[root2]=root1;
        }
        else{
            father[root2]+=father[root1];
            father[root1]=root2;
        }
    }
    void sea(int num){father[num]=0;}
    int ans(int num){
        int ct=0;
        for(int i=1;i<=num;++i){
            if(father[i]<0)++ct;
        }
        return ct;
    }
};
int elem[501][501];
int flag[501][501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    DJS p(502*502);
    int n,m,i,j,ct=1;
    cin>>n>>m;
    for(i=0;i<=n;++i){flag[i][0]=-1;flag[i][m+1]=-1;}
    for(i=0;i<=m;++i){flag[0][i]=-1;flag[n+1][i]=-1;}
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            cin>>flag[i][j];
            elem[i][j]=ct++;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(flag[i][j]==-1){
                p.sea(elem[i][j]);
                continue;
            }
            if(flag[i-1][j]==0&&p.search(elem[i][j])!=p.search(elem[i-1][j])){
                p.merge(elem[i][j],elem[i-1][j]);
                cout<<i<<" "<<j<<endl;
            }
            if(flag[i+1][j]==0&&p.search(elem[i][j])!=p.search(elem[i+1][j]))
            {
                p.merge(elem[i][j],elem[i+1][j]);
                cout<<i<<" "<<j<<endl;
            }
                p.merge(elem[i][j],elem[i+1][j]);
            if(flag[i][j-1]==0&&p.search(elem[i][j])!=p.search(elem[i][j-1])){
                p.merge(elem[i][j],elem[i][j-1]);
                cout<<i<<" "<<j<<endl;
            }
            if(flag[i][j+1]==0&&p.search(elem[i][j])!=p.search(elem[i][j+1])){
                p.merge(elem[i][j],elem[i][j+1]);
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<p.ans(n*m);
    return 0;
}
/*
4 4
0 -1 0 -1
0 -1 -1 0
-1 0 -1 0
-1 0 -1 -1
*/
