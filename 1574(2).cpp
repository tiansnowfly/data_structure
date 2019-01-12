#include <iostream>
using namespace std;

int main(){
    int n,m,x;
    long long k;
    cin>>n>>k>>m>>x;
    for(int i=0;i<k/3;++i){
        m=(m*1000)%n;
    }
    if(k%3==1) m=(m*10)%n;
    if(k%3==2) m=(m*100)%n;
    cout<<(m+x)%n;
    return 0;
}
