#include <iostream>
#include <cstring>
#define N 500
using namespace std;

int len1,len2,a1[N]={0},a2[N]={0};
int judge(int a1[],int a2[],int len1,int len2){
    int t,flag,k;
    if(len1<len2){flag=0;}
    else if(len1>len2){flag=1;}
    else{
        k=len1;
        t=0;
        while(t==0&&k>0){
            if(a1[k]>a2[k]){t=1;flag=1;}
            else if(a1[k]==a2[k]){k--;}
            else{t=1;flag=0;}
        }
        if(k==0&&t==0){flag=2;}
    }
    return flag;
}
int sub(int a1[],int a2[],int len1,int len2){
    int k,t,b2[N];

    for(k=0;k<len2;k++){
        b2[k]=a2[k];
    }
    for(k=len2;k<N;k++){
        b2[k]=0;
    }
    t=len1-len2-1;
    if(t<0){t=0;}
    if(t>0){
        for(k=len2-1;k>=0;k--){b2[k+t]=b2[k];}
        for(k=0;k<t;k++){b2[k]=0;}
    }
    for(k=0;k<len1;k++){
        if(a1[k]>=b2[k]){a1[k]=a1[k]-b2[k];}
        else{
            a1[k+1]=a1[k+1]-1;
            a1[k]=a1[k]+10-b2[k];
        }
    }
    return t;
}
int main(){
    string str1,str2;
    int c[N]={0},b[N]={0};
    int savelen1,savelen2;
    cin>>str1>>str2;
    len1=str1.length();
    len2=str2.length();

    savelen1=len1;
    savelen2=len2;
    for(int i=0;i<len1;i++){
        a1[i]=str1[len1-i-1]-'0';
    }
    for(int j=0;j<len2;j++){
        a2[j]=str2[len2-j-1]-'0';
    }
    int m=0,t,k,t1,x,p,t2;
    t2=judge(a1,a2,len1,len2);
    do{
        while(a1[len1-1]==0)len1--;
            t=judge(a1,a2,len1,len2);
            if(t>=1){
               k=sub(a1,a2,len1,len2);
               c[k]=c[k]+1;
               if(k>m)m=k;
               t1=0;
               for(p=k;p<=m;p++){
                   x=c[p]+t1;
                   c[p]=x%10;
                   t1=x/10;
               }
               if(t1>0){m++;c[m]=t1;}
            }

    }while(t!=0);
    if(t2==0){cout<<"0";}
    if(t2==2){cout<<"1";}
    if(t2==1){
        while(!c[savelen1-1])savelen1--;
        for(int h=savelen1-1;h>=0;h--){cout<<c[h];}
        }
    return 0;
}

