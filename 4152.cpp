#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n,i;
    cin>>n;
    for(i=1;i<n;++i) n-=i;
    if(i%2==0)cout<<n<<"/"<<i+1-n;
    else cout<<i+1-n<<"/"<<n;
    return 0;
}
