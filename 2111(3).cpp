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
void insert(const int &x){
    bTree *nTmp=new bTree(x,NULL,NULL);
    if(root==NULL){root=nTmp;return;}
    bTree *tmp=root;
    while(true){
        if(x>tmp->value){
            if(tmp->right==NULL){
                tmp->right=nTmp;
                break;
            }
            tmp=tmp->right;
        }
        else if(tmp->left==NULL){
            tmp->left=nTmp;
            break;
        }
        else tmp=tmp->left;
    }
}
void deletex(const int &x){
    bTree *nNode=root;
    bTree *father;
    int ltOrRg;
    while(root!=NULL){
        if(x>nNode->value){
            ltOrRg=2;
            father=nNode;
            nNode=nNode->right;
        }
        else if(x<nNode->value){
            ltOrRg=1;
            father=nNode;
            nNode=nNode->left;
        }
        else break;
    }
    if(nNode->left!=NULL&&nNode->right!=NULL){
        bTree *tmp=nNode->right;
        if(nNode->left==NULL){
            nNode->value=tmp->value;
            nNode->right=tmp->right;
            delete tmp;
            return;
        }
        while(tmp->left->left!=NULL)tmp=tmp->left;
        bTree *dNode=tmp->left;
        nNode->value=dNode->value;
        nNode->left=dNode->right;
        delete dNode;
        return;
    }
    if(nNode==root){
        if(root->left==NULL)root=root->right;
        else root=root->left;
        delete nNode;
        return;
    }
    if(ltOrRg==1)father->left=(nNode->left==NULL?nNode->right:nNode->left);
    else father->right=(nNode->left==NULL?nNode->right:nNode->left);
    delete nNode;
    delete father;
    return;
}
int min_abs(const int &x){
    bTree *findx=root;
    while(true){
        if(findx==NULL)break;
        int tmp=absx(x,findx->value);
        ans=ans>tmp?tmp:ans;
        if(x<findx->value) findx=findx->left;
        else if(x>findx->value)findx=findx->right;
        else {ans=0;break;}
    }
    delete findx;
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

