#include <iostream>
using namespace std;

int main(){
    int n,m,x,k;
    cin>>n>>m>>k>>x;

    for(int i=0;i<k/2;++i){
        m=(m*100)%n;
    }
    if(k%2==1) m=(m*10)%n;
    cout<<(m+x)%n;
    return 0;
}
