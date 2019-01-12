#include <iostream>
#define mx 30002
using namespace std;

int a[mx],b[mx];
int N,M,ans=-1;
int main(){
    int i,j;
    cin>>N>>M;
    for(i=0;i<N;++i) cin>>a[i];
    for(i=0;i<M;++i) cin>>b[i];
    for(i=0;i<N;++i){
        for(j=0;j<M;++j){
            int t=a[i]^b[j];
            if(ans<t)ans=t;
        }
    }
    cout<<ans;
    return 0;
}
