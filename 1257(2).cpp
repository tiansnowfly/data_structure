#include <iostream>
using namespace std;

struct tree{
     int left,right,parent,value;
};
tree *chTree;
int m;

bool addnode(int rt0,int lt,int rg){
    if(chTree[rt0].value==-1&&chTree[lt].value!=-1&&chTree[rg].value!=-1){
        if(chTree[rt0].left==0&&chTree[rt0].right==0){
            chTree[rt0].left=lt;
            chTree[rt0].right=rg;
            chTree[chTree[rt0].left].value=-1;
            chTree[chTree[rt0].right].value=-1;
            chTree[lt].parent=chTree[rg].parent=rt0;
            return true;
        }
        else return false;
    }
    else return false;
}
void preOrder(int i){
        cout<<i<<" ";
        if(chTree[i].left!=0)preOrder(chTree[i].left);
        if(chTree[i].right!=0)preOrder(chTree[i].right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,kind,lt,rg,check,change,rt0;
    cin>>m;
    chTree=new tree[3*m+1];
    for(i=1;i<=3*m;++i){
        chTree[i].left=0;
        chTree[i].right=0;
        chTree[i].parent=0;
        chTree[i].value=0;
    }
    for(i=0;i<m;++i){
        cin>>kind;
        if(kind==1){
            cin>>rt0>>lt>>rg;
            chTree[1].value=-1;
            if(addnode(rt0,lt,rg))cout<<"Ok!"<<endl;
            else cout<<"Error!"<<endl;
        }
        else if(kind==2){
            cin>>check;
            if(chTree[check].value==-1){
                cout<<chTree[check].parent<<" "<<chTree[check].left<<" "<<chTree[check].right<<endl;
            }
            else cout<<"Error!"<<endl;
        }
        else{
            cin>>change;
            if(change!=1&&chTree[change].value==-1){
                if(chTree[chTree[change].parent].left==change){
                    chTree[chTree[change].parent].left=chTree[chTree[change].parent].right;
                    chTree[chTree[change].parent].right=change;
                    cout<<chTree[chTree[change].parent].left<<endl;
                }
                else{
                    chTree[chTree[change].parent].right=chTree[chTree[change].parent].left;
                    chTree[chTree[change].parent].left=change;
                    cout<<chTree[chTree[change].parent].right<<endl;
                }
            }
            else cout<<"Error!"<<endl;
        }
    }
    preOrder(1);
    delete [] chTree;
    return 0;
}

