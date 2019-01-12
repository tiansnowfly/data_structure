#include <cstdio>
using namespace std;

int n,m,s,l,ans=0;
bool go[11];
bool bian[11][11];
int step=0;
void dfs(int now){
    if(step==l){ans++;return;}
    for(int i=1;i<=n;++i){
        if(bian[now][i]&&!go[i]){
            go[i]=true;
            step++;
            dfs(i);
            step--;
            go[i]=false;
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&l);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        bian[a][b]=true;
    }
    go[s]=true;
    dfs(s);
    printf("%d",ans);
    return 0;
}
