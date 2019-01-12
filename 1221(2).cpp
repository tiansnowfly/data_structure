#include <iostream>
#include <string>
using namespace std;

template <class T>
class BST{
    struct Node{
        T data;
        Node *left, *right;
        Node(Node *lt=NULL,Node *rt=NULL):left(lt),right(rt){}
        Node(const T &k,Node *lt=NULL,Node *rt=NULL):data(k),left(lt),right(rt){}
    };
    Node *root;
    void clearHelp(Node *&sub){
        if (sub==NULL) return;
        else{
            if (sub->left!=NULL)clearHelp(sub->left);
            if (sub->right!=NULL)clearHelp(sub->right);
            delete sub;
            sub=NULL;
        }
    }
    bool searchHelp(const T &k,Node *sub)const{
        if (sub==NULL) return false;
        else{
            if (k<sub->data){
                sub=sub->left;
                return searchHelp(k,sub);
            }
            else if (k > sub->data){
                sub=sub->right;
                return searchHelp(k,sub);
            }
            else return true;
        }
    }
    void insertHelp(const T &k,Node* &sub){
        if (sub==NULL)sub=new Node(k);
        else{
            if (k<sub->data)insertHelp(k,sub->left);
            else insertHelp(k,sub->right);
        }
    }
    void delNode(Node* &sub){
        Node *tmp=sub;
        if (sub->left==NULL){
            sub=sub->right;
            delete tmp;
        }
        else if(sub->right==NULL){
            sub=sub->left;
            delete tmp;
        }
        else{
            tmp=tmp->right;
            while(tmp->left!=NULL)
                tmp=tmp->left;
            sub->data=tmp->data;
            removeHelp(sub->data,sub->right);
        }
    }
    bool removeHelp(const T &k,Node* &sub){
        if(sub==NULL) return false;
        else{
            if(k>sub->data)return removeHelp(k,sub->right);
            else if(k<sub->data)return removeHelp(k,sub->left);
            else {delNode(sub); return true;}
        }
    }
    void delGreatHelp(const T &k,Node* &sub){
        if(sub==NULL) return;
        else if(sub->data<=k)delGreatHelp(k,sub->right);
        else{
            clearHelp(sub->right);
            delNode(sub);
            delGreatHelp(k,sub);
        }
    }
    void delSmallHelp(const T &k,Node* &sub){
        if (sub==NULL) return;
        else if (sub->data>=k)delSmallHelp(k,sub->left);
        else{
            clearHelp(sub->left);
            delNode(sub);
            delSmallHelp(k,sub);
        }
    }
    void delRangeHelp(const T &a,const T &b,Node* &sub){
        if (sub==NULL) return;
        else if(sub->data<=a)delRangeHelp(a,b,sub->right);
        else if (sub->data>=b)delRangeHelp(a,b,sub->left);
        else {
            delNode(sub);
            delRangeHelp(a,b,sub);
        }
    }
    void findElemHelp(int &i,T &it,Node* sub){
        if(sub==NULL) return;
        else{
            findElemHelp(i,it,sub->left);
            if (i==0) return;
            else if(--i==0) {
                it=sub->data;
                return;
            }
            findElemHelp(i,it,sub->right);
        }
    }
public:
    BST():root(NULL){}
    ~BST(){clearHelp(root);}
    bool search(const T &k) const {return searchHelp(k,root);}
    void insert(const T &k) {insertHelp(k,root);}
    bool remove(const T &k) {return removeHelp(k,root);}
    void delGreat(const T &k) {delGreatHelp(k,root);}
    void delSmall(const T &k) {delSmallHelp(k,root);}
    void delRange(const T &a,const T &b) {delRangeHelp(a,b,root);}
    bool findElem(int &i,T &it) {findElemHelp(i,it,root);return (i==0);}
};

int main(){
    int n;
    cin>>n;
    BST<int> tr;
    string op;
    int a,b;
    for (int i=0;i<n;i++){
        cin>>op;
        if (op=="insert"){cin>>a;tr.insert(a);}
        else if (op=="delete"){cin>>a;tr.remove(a);}
        else if (op=="delete_less_than"){cin>>a;tr.delSmall(a);}
        else if (op=="delete_greater_than"){cin>>a;tr.delGreat(a);}
        else if (op=="delete_interval"){cin>>a>>b;tr.delRange(a,b);}
        else if (op=="find"){
            cin>>a;
            if (tr.search(a))cout <<'Y'<<endl;
            else cout <<'N'<<endl;
        }
        else if (op=="find_ith"){
            cin>>a;
            if (!tr.findElem(a,b))cout <<'N'<<endl;
            else cout<<b<<endl;
        }
    }
}
