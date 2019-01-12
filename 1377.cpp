#include<iostream>
using namespace std;
int n,m,num;
int elem[100001];
int tmp[200001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int location,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>num;
        if(num>m)elem[i]=1;
        if(num<m)elem[i]=-1;
        if(num==m){elem[i]=0;location=i;}
    }
    for(int i=location-1;i>0;--i)elem[i]+=elem[i+1];
    for(int i=location+1;i<=n;++i)elem[i]+=elem[i-1];
    for(int i=1;i<=n;++i) elem[i]+=n;
    for(int i=location;i>0;--i)tmp[elem[i]]++;
    for(int i=location;i<=n;++i)ans+=tmp[2*n-elem[i]];
    cout<<ans;
    return 0;
}

