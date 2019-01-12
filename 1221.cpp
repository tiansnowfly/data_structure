#include <iostream>
#include <cstring>
using namespace std;

class bst{
    private:
        struct node{
            int dt;
            node *left,*right;
            node(const int &x,node *lt=NULL,node *rg=NULL):dt(x),left(lt),right(rg){}
            node():left(NULL),right(NULL){}
            ~node(){}
        };
        node *root;
        int *elem;
        int ct;
    public:
        bst(int sz=5001){root=NULL;ct=0;elem=new int[sz];}
        ~bst(){makeEmpty(root);}
        void insert(const int &x){insert(x,root);}
        void deletex(const int &x){deletex(x,root);}
        void delete_less_than(const int &x){delete_less_than(x,root);}
        void delete_greater_than(const int &x){delete_greater_than(x,root);}
        void delete_interval(const int &a,const int &b){delete_interval(a,b,root);}
        bool find(const int &x)const{find(x,root);}
        void find_ith(const int &i){
            find_ith(root);
            if(i>=1&&i<=ct)cout<<elem[i]<<endl;
            else cout<<"N"<<endl;
            ct=0;
        }
    private:
        void makeEmpty(node *&t);
        void insert(const int &x,node *&t);
        void deletex(const int &x,node *&t);
        void delete_less_than(const int &x,node *&t);
        void delete_greater_than(const int &x,node *&t);
        void delete_interval(const int &a,const int &b,node *&t);
        bool find(const int &x,node *t)const;
        void find_ith(node *t);
};
void bst::makeEmpty(node *&t){
    if(t==NULL) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}
bool bst::find(const int &x,node *t)const{
    if(t==NULL) return false;
    else if(x<t->dt) return find(x,t->left);
    else if(x>t->dt) return find(x,t->right);
    else return true;
}
void bst::find_ith(node *t){
    if(t==NULL) return;
    find_ith(t->left);
    elem[++ct]=t->dt;
    find_ith(t->right);
}
void bst::insert(const int &x,node *&t){
    if(t==NULL) t=new node(x,NULL,NULL);
    else if(x<=t->dt) insert(x,t->left);
    else if(x>t->dt) insert(x,t->right);
}
void bst::deletex(const int &x,node *&t){
    if(t==NULL) return;
    if(x<t->dt) deletex(x,t->left);
    else if(x>t->dt) deletex(x,t->right);
    else if(t->left!=NULL&&t->right!=NULL){
        node *tmp=t->left;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->dt=tmp->dt;
        deletex(t->dt,t->left);
    }
    else{
        node *oldtmp=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldtmp;
    }
}
void bst::delete_less_than(const int &x,node *&t){
    if(t==NULL)return;
    if(x>t->dt){
        node *tmp=t;
        t=t->right;
        makeEmpty(tmp->left);
        delete tmp;
        delete_less_than(x,t);
    }
    else delete_less_than(x,t->left);
}
void bst::delete_greater_than(const int &x,node *&t){
    if(t==NULL) return;
    if(x<t->dt){
        node *tmp=t;
        t=t->left;
        makeEmpty(tmp->right);
        delete tmp;
        delete_greater_than(x,t);
    }
    else delete_greater_than(x,t->right);
}
void bst::delete_interval(const int &a,const int &b,node *&t){
    if(t==NULL) return;
    if(t->dt<=a) delete_interval(a,b,t->right);
    else if(t->dt>=b) delete_interval(a,b,t->left);
    else{
        deletex(t->dt,t);
        delete_interval(a,b,t);
    }
}
int main(){
    int n,i,x,y;
    char ch[22];
    bst b;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>ch>>x;
        if(!strcmp(ch,"insert")) b.insert(x);
        else if(!strcmp(ch,"delete"))b.deletex(x);
        else if(!strcmp(ch,"delete_less_than"))b.delete_less_than(x);
        else if(!strcmp(ch,"delete_greater_than"))b.delete_greater_than(x);
        else if(!strcmp(ch,"delete_interval")){cin>>y;b.delete_interval(x,y);}
        else if(!strcmp(ch,"find")){
            if(b.find(x))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        else b.find_ith(x);
    }
    return 0;
}
/*
22
insert 42
insert 42
insert 43
find 42
find 44
find_ith 2
find_ith 4
delete 42
delete_greater_than 42
find_ith 1
insert 1
insert 2
insert 3
insert 4
insert 5
delete_less_than 2
delete_interval 3 5
find 1
find 2
find 3
find 4
find 5
*/
