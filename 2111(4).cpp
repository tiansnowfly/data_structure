#include <iostream>
using namespace std;
int M,ans;
struct bTree{
    int value;
    bTree *left,*right;
    bTree(const int &x,bTree *lt=NULL,bTree *rg=NULL):value(x),left(lt),right(rg){}
};
bTree *root=NULL;
int absx(int a,int b){return (a-b)>(b-a)?(a-b):(b-a);}
void insert(const int &x){
    bTree *new_node=new bTree(x,NULL,NULL);
    if(root==NULL){root=new_node;return;}
    bTree *tmp=root;
    while(true){
        if(x>tmp->value){
            if(tmp->right==NULL){
                tmp->right=new_node;
                break;
            }
            else tmp=tmp->right;
        }
        else if(tmp->left==NULL){
                tmp->left=new_node;
                break;
        }
        else tmp=tmp->left;
    }
}
void deletex(const int &x){
    bTree *now_node=root;
    bTree *parent_node;
    int flag;

    while(root!=NULL){
        if(x<now_node->value){
            flag=1;
            parent_node=now_node;
            now_node=now_node->left;
        }
        else if(x>now_node->value){
            flag=2;
            parent_node=now_node;
            now_node=now_node->right;
        }
        else break;
    }
    if(now_node==root){
        if(root->left!=NULL)root=root->left;
        else root=root->right;
        delete now_node;
        return;
    }
    if(now_node->left!=NULL&&now_node->right!=NULL){
        bTree *tmp=now_node->right;
        if(tmp->left==NULL){
           now_node->value=tmp->value;
           now_node->right=tmp->right;
           delete tmp;
           return;
        }
        while(tmp->left->left!=NULL)tmp=tmp->left;
        bTree *del_node=tmp->left;
        now_node->value=del_node->value;
        tmp->left=del_node->right;
        delete del_node;
        return;
    }
    if(flag==1)parent_node->left=(now_node->left==NULL?now_node->right:now_node->left);
    else parent_node->right=(now_node->left==NULL?now_node->right:now_node->left);
    delete now_node;
    return;
}
int min_abs(const int &x){
    bTree *findx=root;
    while(findx!=NULL){
        if(findx==NULL)break;
        int tmp=absx(x,findx->value);
        ans=ans>tmp?tmp:ans;
        if(x<findx->value) findx=findx->left;
        else if(x>findx->value)findx=findx->right;
        else {ans=0;break;}
    }
    return ans;
}
int main(){
    int kind,i,num;
    cin>>M;
    for(i=0;i<M;++i){
        cin>>kind>>num;
        switch(kind){
            case 0:ans=99999999;
                   cout<<min_abs(num)<<endl;break;
            case 1:insert(num);break;
            case 2:deletex(num);break;
        }
    }
    return 0;
}
