#include <iostream>
using namespace std;

class tree{
    private:
        struct Node{
            Node *left,*right;
            char data;
            Node():left(NULL),right(NULL){}
            Node(char dt,Node *lt=NULL,Node *rh=NULL){
                data=dt;
                left=lt;
                right=rh;
            }
            ~Node(){};
        };
    Node *root;
    public:
        tree():root(NULL){}
        tree(char x){root=new Node[x];}
        ~tree();
        void clear(){}
        bool isEmpty()const{return root==NULL;}
        char Root(char flag)const{
            if(root==NULL)return flag;
            else return root->data;
        }
        char lchild(char x,char flag)const;
        char rciild(char x,char flag)const;
        char parent(char x,char flag)const{return flag;}
        void delLeft(char x);
        void delRight(char x);
        void preOrder()const;
        void midOrder()const;
        void postOrder()const;
        void levelOrder()const;
        void create(char flag);
    private:
        Node *find(char x,char flag)const;
        void clear (Node *&t);
        void preOrder(Node *t)const;
        void midOrder(Node *t)const ;
        void postOrder(Node *t)const;
};
int main(){

    return 0;
}

