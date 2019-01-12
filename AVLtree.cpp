#inlcude <iostream>
using namespace std;

template <class KEY,class OTHER>
struct SET{
    KEY key;
    OTHER other;
};
template <class KEY,class OTHER>
class dynamicSearchTable{
public:
    virtual SET<KEY,OTHER> *find(const KEY &x)const=0;
    virtual void insert(const SET<KEY,OTHER> &x)=0;
    virtual void remove(const KEY &x);
    virtual ~dynamicSearchTable(){};
};
template <class KEY,class OTHER>
class AvlTree:public dynamicSearchTable<KEY,OTHER>{
    struct AvlNode{
        SET<KEY,OTHER> data;
        AvlNode *left;
        AvlNode *right;
        int height;
        AvlTree(const SET<KEY,OTHER> &x,AvlNode *lt,AvlNode *right,int h=1)
        :data(x),left(lt),right(rg),height(h){}
    };
    AvlNode *root;
public:
    AvlTree(){root=NULL;}
    ~AvlTree(){makeEmpty(root);}
    SET<KEY,OTHER> *find(const KEY &x)const;
    void insert(const SET<KEY,OTHER> &x);
    void remove(const KEY &x);
private:
    void insert(const SET<KEY,OTHER> &x,AvlNode *&t);
    bool remove(const KEY &x,AvlNode *&t);
    void makeEmpty(AvlNode *t);
    int height(AvlNode *t)const {return t==NULL?0:t->height;}
    void LL(AvlNode *&t);
    void LR(AvlNode *&t);
    void RL(AvlNode *&t);
    void RR(AvlNode *&t);
    int max(int a,int b){return a>b?a:b;}
    bool adjust(AvlNode *&t,int subTree);
};
template <class KEY,class OTHER>
SET<KEY,OTHER> *AvlTree<KEY,OTHER>::find(const KEY &x)const{
    AvlTree *t=root;
    while(t!=NULL&&t->data.key!=x){
        if(t->data.key>x)t=t->left;
        else t=t->right;
    }
    if(t==NULL)return NULL;
    else return (SET<KEY,OTHER>*) t;
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::LL(AvlNode *&t){
    AvlNode *t1=t->left;
    t->left=t1->right;
    t1->right=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t->left),height(t))+1;
    t=t1;
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::RR(AvlNode *&t){
    AvlNode *t1=t->right;
    t->right=t1->left;
    t1->left=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t->right),height(t))+1;
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::LR(AvlNode *&t){
    RR(t->left);
    LL(t);
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::RL(AvlNode *&t){
    LL(t->right);
    RR(t);
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::insert(const SET<KEY,OTHER> &x){
    insert(x,root);
}
template <class KEY,class OTHER>
void AvlTree<KEY,OTHER>::insert(const SET<KEY,OTHER> &x,AvlNode *&t){
    if(t==NULL){t=new AvlNode(x,NULL,NULL);}
    else if(x.key<t->data.key){
        insert(x,t->left);
        if(height(t->left)-height(t->right)==2){
            if(x.key<t->left->data.key)LL(t);
            else LR(t);
        }
    }
    else if(x.key>t->data.key){
        insert(x,t->right);
        if(height(t->right)-height(t->left)==2){
            if(x.key>t->left->data.key)RR(t);
            else RL(t);
        }
    }
    t->height=max(height(t->left),height(t->right))+1;
}

int main(){
    return 0;
}
