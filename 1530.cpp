#include <iostream>
#include <cstring>
using namespace std;
int t;
string str1,str2,str3;
int sm=0;
char array[1000001];

void encodeInOrder(int num,int n){
    if(num>=n)return;
    encodeInOrder(2*num+1,n);
    cout<<str3[num];
    encodeInOrder(2*num+2,n);
}
void encodePreOrder(int num,int n){
    if(num>=n)return;
    cout<<str3[num];
    encodePreOrder(2*num+1,n);
    encodePreOrder(2*num+2,n);
}
void encodePostOrder(int num,int n){
    if(num>=n)return;
    encodePostOrder(2*num+1,n);
    encodePostOrder(2*num+2,n);
    cout<<str3[num];
}
void in(int num,int n){
    if(num>n)return;
    in(2*num,n);
    array[num]=str3[sm];
    sm++;
    in(2*num+1,n);
}
void inlevelOrder(int n){
    sm=0;
    in(1,n);
    for(int k=1;k<=n;++k) cout<<array[k];
}
void pre(int num,int n){
    if(num>n)return;
    array[num]=str3[sm];
    sm++;
    pre(2*num,n);
    pre(2*num+1,n);
}
void prelevelOrder(int n){
    sm=0;
    pre(1,n);
    for(int k=1;k<=n;++k) cout<<array[k];
}
void post(int num,int n){
    if(num>n)return;
    post(2*num,n);
    post(2*num+1,n);
    array[num]=str3[sm];
    sm++;
}
void postlevelOrder(int n){
    sm=0;
    post(1,n);
    for(int k=1;k<=n;++k) cout<<array[k];
}
int main(){
    int i,n;
    cin>>t;
    for(i=1;i<=t;++i){
        cin>>n>>str1>>str2>>str3;
        if(str2[0]=='E'){
            if(str1[0]=='I') {encodeInOrder(0,n);cout<<endl;}
            else if(str1[1]=='R') {encodePreOrder(0,n);cout<<endl;}
            else {encodePostOrder(0,n);cout<<endl;}
        }
        if(str2[0]=='D'){
            if(str1[0]=='I') {inlevelOrder(n);cout<<endl;}
            else if(str1[1]=='R') {prelevelOrder(n);cout<<endl;}
            else {postlevelOrder(n);cout<<endl;}
        }
    }
    return 0;
}
