#include <iostream>
#define m_x 1000001
using namespace std;

int elem[m_x],sum[m_x*4+1];
int m,n,sumOne,mxLen;
void build(int lt,int rg,int loc){
    if(lt==rg){sum[loc]=elem[lt];return;}
    build(lt,(lt+rg)/2,loc*2);
    build((lt+rg)/2+1,rg,loc*2+1);
    sum[loc]=sum[loc*2]+sum[loc*2+1];
}
void check(int lt,int rg,int left,int right,int loc){
    if(lt>=left&&rg<=right){sumOne+=sum[loc];return;}
    if(lt==rg)return;
    check(lt,(lt+rg)/2,left,right,loc*2);
    check((lt+rg)/2+1,rg,left,right,loc*2+1);
}
void upDate(int left,int right,int value){
    for(int k=left;k<=right;++k)elem[k]=value;
    build(1,n,1);
}
void mx_len(int left,int right){
    int tmp=0;
    for(int k=left;k<=right;++k){
        if(elem[k]==1){++tmp;mxLen=mxLen>tmp?mxLen:tmp;}
        else tmp=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,nm,beg,ed,value;
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>elem[i];
    build(1,n,1);
    for(i=0;i<m;++i){
        cin>>nm;
        if(nm==1){
            cin>>beg>>ed>>value;
            upDate(beg,ed,value);
        }
        else if(nm==2){
            cin>>beg>>ed;
            sumOne=0;
            check(1,n,beg,ed,1);
            cout<<sumOne<<'\n';
        }
        else{
            cin>>beg>>ed;
            mxLen=0;
            mx_len(beg,ed);
            cout<<mxLen<<'\n';
        }
    }
    return 0;
}




