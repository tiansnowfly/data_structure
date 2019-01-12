#include <iostream>
using namespace std;

int sum[31][31]={0};
int root[31][31]={0};
void print(int lt,int rg){
     if (lt>rg) return;
     cout<<root[lt][rg]<<" ";
     print(lt,root[lt][rg]-1);
     print(root[lt][rg]+1,rg);
}
int main(){
    int value[31];
    int n,i,j,k;
    cin>>n;
    for (i=1;i<=n;++i){
        cin>>value[i];
        for (j=0;j<i;++j) sum[i][j]=1;
        sum[i][i]=value[i];
        root[i][i]=i;
    }
    for(i=1;i<n;++i) for(j=1;j<=n-i;++j) for(k=j;k<=i+j;++k){
        if(sum[j][i+j]<sum[j][k-1]*sum[k+1][i+j]+value[k]){
            sum[j][i+j]=sum[j][k-1]*sum[k+1][i+j]+value[k];
            root[j][i+j]=k;
        }
    }
    cout<<sum[1][n]<<endl;;
    print(1,n);
    return 0;
}
