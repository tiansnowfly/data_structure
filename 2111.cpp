#include <iostream>
using namespace std;
int M,ans;
struct bTree{
    int value;
    bTree *left,*right;
    bTree(int x,bTree *lt=NULL,bTree *rg=NULL):value(x),left(lt),right(rg){}
    bTree():left(NULL),right(NULL){}
};
bTree *root=NULL;
int absx(int a,int b){
    return (a-b)>(b-a)?(a-b):(b-a);
}
void insert(int x,bTree *&t){
    if(t==NULL){
        t=new bTree(x,NULL,NULL);
        return;
    }
    else if(x<t->value)insert(x,t->left);
    else if(x>t->value)insert(x,t->right);
}
void deletex(const int &x,bTree *&t){
    if(t==NULL)return;
    if(x<t->value)deletex(x,t->left);
    else if(x>t->value) deletex(x,t->right);
    else if(t->left!=NULL&&t->right!=NULL){
        bTree *tmp=t->right;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->value=tmp->value;
        deletex(t->value,t->right);
    }
    else{
        bTree *oldTmp=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldTmp;
    }
}
int min_abs(const int &x,bTree *t){
    if(t==NULL) return ans;
    int tmp=absx(x,t->value);
    ans=ans>tmp?tmp:ans;
    if(x<t->value)min_abs(x,t->left);
    else if(x>t->value)min_abs(x,t->right);
    else {ans=0;return ans;}
}
int main(){
    int kind,i,num;
    cin>>M;
    for(i=0;i<M;++i){
        cin>>kind>>num;
        switch(kind){
            case 0:ans=99999999;
                   cout<<min_abs(num,root)<<endl;break;
            case 1:insert(num,root);break;
            case 2:deletex(num,root);break;
        }
    }
    return 0;
}
