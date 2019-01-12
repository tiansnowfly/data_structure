#include <iostream>
#define mx 1000001
using namespace std;

int elem[mx],sum[mx<<2],lazy[mx<<2];
int n,m,sumOne,mxLen=0,tmp=0,ct=0;
void pushUp(int loc){sum[loc]=sum[loc*2]+sum[loc*2+1];}
void build(int lt,int rg,int loc){
    if(lt==rg){
        sum[loc]=elem[lt];
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
void pushDown(int lt,int rg,int loc){
    int mid=(lt+rg)/2;
    sum[loc*2]=lazy[loc]*(mid-lt+1);
    sum[loc*2+1]=lazy[loc]*(rg-mid);
    lazy[loc*2]=lazy[loc];
    lazy[loc*2+1]=lazy[loc];
    lazy[loc]=0;
}
void upDate(int lt,int rg,int left,int right,int loc,int value){
    if(left<=lt&&right>=rg){
        sum[loc]=(rg-lt+1)*value;
        lazy[loc]=value;
    }
    if(lt==rg)return;
    if(lazy[loc])pushDown(lt,rg,loc);
    int mid=(lt+rg)/2;
    if(left<=mid)upDate(lt,mid,left,right,loc*2,value);
    if(right>mid)upDate(mid+1,rg,left,right,loc*2+1,value);
    sum[loc]=sum[loc*2]+sum[loc*2+1];
}
void len(int lt,int rg,int left,int right,int loc){
    if(ct==n)return;
    if(lt==rg){
        ++ct;
        if(left<=lt&&rg<=right&&sum[loc]==1){++tmp;mxLen=mxLen>tmp?mxLen:tmp;}
        else if(left<=lt&&rg<=right&&sum[loc]==0){tmp=0;}
        return;
    }
    len(lt,(lt+rg)/2,left,right,loc*2);
    len((lt+rg)/2+1,rg,left,right,loc*2+1);
}
int main(){
    int i,nm,beg,ed,value;
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>elem[i];
    build(1,n,1);
    for(i=0;i<m;++i){
        cin>>nm;
        if(nm==1){
            cin>>beg>>ed>>value;
            upDate(1,n,beg,ed,value,1);
        }
        else if(nm==2){
            cin>>beg>>ed;
            sumOne=0;
            checkOne(1,n,beg,ed,1);
            cout<<sumOne<<endl;
        }
        else{
            cin>>beg>>ed;
            len(1,n,beg,ed,1);
            cout<<mxLen<<endl;
        }
    }
    return 0;
}
/*
8 3
1 1 0 0 1 0 1 0
2 1 7
1 3 5 1
3 7 7
*/
