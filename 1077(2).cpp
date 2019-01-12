#include <cstdio>

const int maxn=30+10;
int n,x;
int root[maxn][maxn],a[maxn];
long long f[maxn][maxn];

void find(int i,int j)
{
     if (i<=j)
     {
         printf("%d ",root[i][j]);
         find(i,root[i][j]-1);
         find(root[i][j]+1,j);
     }
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            f[i][j]=1;
        }
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][i]=a[i];
        root[i][i]=i;
    }

    for (int p=1;p<=n-1;p++){
        for (int i=1;i<=n-p;i++){
            int j=i+p;
            f[i][j]=0;
            for (int k=i;k<=j;k++){
                if (f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k]){
                    f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
                    root[i][j]=k;
                }
            }
        }
    }
    return 0;
}

