#include <iostream>
using namespace std;

int a[100001];
long long counter[3]={0},ctW[3]={0};
long long max(long long x,long long y,long long z);
int minCounter();
int main(){
    int N,t;
    long long W1,W2,T1,T2;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a[i];
    }
    for(int j=0;j<N;j+=3){
        ctW[0]+=counter[0];
        counter[0]+=a[j];
    }
    for(int k=1;k<N;k+=3){
        ctW[1]+=counter[1];
        counter[1]+=a[k];
    }
    for(int h=2;h<N;h+=3){
        ctW[2]+=counter[2];
        counter[2]+=a[h];
    }
    W1=ctW[0]+ctW[1]+ctW[2];
    T1=max(counter[0],counter[1],counter[2]);

    ctW[0]=ctW[1]=ctW[2]=counter[0]=counter[1]=counter[2]=0;
    for(int r=0;r<N;++r){
        t=minCounter();
        ctW[t]+=counter[t];
        counter[t]+=a[r];
    }
    W2=ctW[0]+ctW[1]+ctW[2];
    T2=max(counter[0],counter[1],counter[2]);

    cout<<W1<<" "<<T1<<endl;
    cout<<W2<<" "<<T2;

    return 0;
}
int minCounter(){
    int tmp;

    tmp=(counter[0]>=counter[1]?1:0);
    tmp=(counter[2]>=counter[tmp]?tmp:2);
    return tmp;
}
long long max(long long x,long long y,long long z){
    long long m;
    m=(x>y?x:y);
    m=(z>m?z:m);
    return m;
}
