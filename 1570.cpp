#include <iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int N,T;
    cin>>N>>T;

    long long dataN[N],dataT[T],data3[T];
    for(int i=0;i<N;++i){
        cin>>dataN[i];
    }
    for(int j=0;j<T;++j){
        cin>>dataT[j];
    }
    for(int k=0;k<T;++k){
        data3[k]=0;
        int ct=0;
        for(int h=0;h<N;++h){
            if(dataN[h]<=dataT[k]){continue;}
            else{data3[k]=N-h;break;}
        }
    }
    for(int t=0;t<T;++t){
        cout<<data3[t]<<"\n";
    }
    return 0;
}
