#include <iostream>
#define mx 100002
using namespace std;

int elem[mx];
long long segTree[(mx<<2)+1],sum;
int begin_x,end_x,add_x;
void build(int begin,int end,int node){
    if(begin==end){
        segTree[node]=elem[begin];
        return;
    }
    else {
        build(begin,(begin+end)>>1,node<<1);
        build(((begin+end)>>1)+1,end,(node<<1)+1);
        segTree[node]=segTree[node<<1]+segTree[(node<<1)+1];
    }
}
void segSum(int begin,int end,int node){
    if((begin>=begin_x&&end<=end_x)){
        sum+=segTree[node];
        return;
    }
    if(end==begin)return;
    segSum(begin,(begin+end)>>1,node<<1);
    segSum(((begin+end)>>1)+1,end,(node<<1)+1);
}
void add(int begin,int end,int node){
    if(begin<=begin_x&&end>=end_x){
        segTree[node]+=add_x*(end_x-begin_x+1);
    }
    else if(end>=begin_x&&end<end_x&&begin_x>begin){
        segTree[node]+=add_x*(end-begin_x+1);
    }
    else if(end>=begin_x&&end<end_x&&begin_x<=begin){
        segTree[node]+=add_x*(end-begin+1);
    }
    else if(begin>begin_x&&end_x>=begin&&end>end_x){
        segTree[node]+=add_x*(end_x-begin+1);
    }
    else if(begin>begin_x&&end_x>=begin&&end<=end_x){
        segTree[node]+=add_x*(end-begin+1);
    }
    if(end==begin)return;
    add(begin,(begin+end)>>1,node<<1);
    add(((begin+end)>>1)+1,end,(node<<1)+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,i;
    char ch;
    cin>>N>>M;
    for(i=1;i<=N;++i) cin>>elem[i];
    build(1,N,1);
    for(i=1;i<=M;++i){
        cin>>ch;
        if(ch=='Q'){
            cin>>begin_x>>end_x;
            sum=0;
            segSum(1,N,1);
            cout<<sum<<'\n';
        }
        else{
           cin>>begin_x>>end_x>>add_x;
           add(1,N,1);
        }
    }
    return 0;
}

