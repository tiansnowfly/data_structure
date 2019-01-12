#include <iostream>
#include <cstring>
#define mx 26
using namespace std;

int N;
int *parent,*son;
void initialize(){
    parent=new int[mx];
    son=new int[mx];
    for(int k=0;k<mx;++k){
        parent[k]=-1;
        son[k]=-1;
    }
}
int find_ancestor(int x){
    if(parent[x]<0) return x;
    return find_ancestor(parent[x]);
}
int find_last_son(int x){
    if(son[x]<0) return x;
    return find_last_son(son[x]);
}
void move_merge(int x1,int x2,const char &str){
    if(str=='v'){
        if(son[x1]>=0){
            parent[son[x1]]=parent[x1];
            son[parent[x1]]=son[x1];
        }
        else {son[parent[x1]]=-1;}
        parent[x1]=find_last_son(x2);
        son[find_last_son(x2)]=x1;
    }
    else{
        int tmp=son[x1],tmp0;
        while(tmp>=0){
            tmp0=son[tmp];
            parent[tmp]=-1;
            son[tmp]=-1;
            tmp=tmp0;
        }
        son[x1]=-1;
        int tmp1=son[x2],tmp2;
        while(tmp1>=0){
            tmp2=son[tmp1];
            parent[tmp1]=-1;
            son[tmp1]=-1;
            tmp1=tmp2;
        }
        son[x2]=-1;

        son[parent[x1]]=-1;
        parent[x1]=x2;
        son[x2]=x1;
        son[x1]=-1;
    }
}
void pile_merge(int x1,int x2,const char &str){
    if(str=='v'){
        son[parent[x1]]=-1;
        parent[x1]=find_last_son(x2);
        son[find_last_son(x2)]=x1;
    }
    else{
        int tmp=son[x2],tmp0;
        while(tmp>=0){
            tmp0=son[tmp];
            parent[tmp]=-1;
            son[tmp]=-1;
            tmp=tmp0;
        }
        son[x2]=-1;

        son[parent[x1]]=-1;
        parent[x1]=x2;
        son[x2]=x1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    char ch[6],ch1[6];
    int num1,num2;
    cin>>N;
    while(true){
        cin>>ch;
        if(!strcmp(ch,"quit")) break;
        cin>>num1>>ch1>>num2;
        if(ch[0]=='m'){
            if(num1==num2||find_ancestor(num1)==find_ancestor(num2)) continue;
            move_merge(num1,num2,ch1[1]);
        }
        if(ch[0]=='p'){
            if(num1==num2||find_ancestor(num1)==find_ancestor(num2)) continue;
            pile_merge(num1,num2,ch1[1]);
        }
    }
    for(int i=0;i<N;++i){
        if(parent[i]!=-1)cout<<i<<":"<<endl;
        if(parent[i]==-1){
            cout<<i<<":";
            while(son[i]>=0){
                cout<<i<<" ";
                i=son[i];
            }
            cout<<i<<endl;
        }
    }
    return 0;
}
