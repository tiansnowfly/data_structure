#include <iostream>
using namespace std;
long long num[100001];
long long sum=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,i;
    char ch;
    cin>>N>>M;
    for(i=1;i<=N;++i) cin>>num[i];
    int begin_x,end_x,add_x,k;
    for(i=1;i<=M;++i){
        cin>>ch;
        if(ch=='Q'){
            sum=0;
            cin>>begin_x>>end_x;
            for(k=begin_x;k<=end_x;++k) sum+=num[k];
            cout<<sum<<'\n';
        }
        else{
            cin>>begin_x>>end_x>>add_x;
            for(k=begin_x;k<=end_x;++k) num[k]+=add_x;
        }
    }
    return 0;
}
