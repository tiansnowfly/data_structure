#include <iostream>
#define mx 1000001
using namespace std;

int elem[mx],sum[mx<<2];
int n,m,sumOne,mxLen;
void pushUp(int loc){sum[loc]=sum[loc*2]+sum[loc*2+1];}
void build(int lt,int rg,int loc){
    if(lt==rg){
        sum[loc]+=elem[lt];
        return;
    }
    build(lt,(lt+rg)/2,loc*2);
    build((lt+rg)/2+1,rg,loc*2+1);
    pushUp(loc);
}
void checkOne(int lt,int rg,int left,int right,int loc){
    if(left<=lt&&right>=rg){
        sumOne+=sum[loc];
        return;
    }
    if(lt==rg)return;
    checkOne(lt,(lt+rg)/2,left,right,loc*2);
    checkOne((lt+rg)/2+1,rg,left,right,loc*2+1);
}
void upDate(int left,int right,int value){
    for(int k=left;k<=right;++k)elem[k]=value;
    build(1,n,1);
}
void len(int left,int right){
    int len=0;
    while(left<=right){
        if(elem[left]==1)++len;
        else len=0;
        mxLen=mxLen>len?mxLen:len;
        ++left;
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
            checkOne(1,n,beg,ed,1);
            cout<<sumOne<<endl;
        }
        else{
            cin>>beg>>ed;
            len(beg,ed);
            cout<<mxLen<<endl;
        }
    }
    return 0;
}
/*
8 1
0 0 1 1 1 0 0 0
2
*/
