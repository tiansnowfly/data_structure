#include <iostream>
using namespace std;
int elem[300002];

struct tree{
     int left,right,parent;
};
tree *chTree;
int m,count=0;
bool finda(int rt,int check){
    if(rt==check) return true;
    if(rt==0) return false;
    finda(chTree[rt].left,check);
    finda(chTree[rt].right,check);
}
bool addnode(int rt0,int lt,int rg){
    if(finda(1,rt0)&&!finda(1,lt)&&!finda(1,rg)){
        if(chTree[rt0].left==0&&chTree[rt0].right==0){
            chTree[rt0].left=lt;
            chTree[rt0].right=rg;
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
        chTree[i].left=chTree[i].right=chTree[i].parent=0;
    }
    for(i=0;i<m;++i){
        cin>>kind;
        if(kind==1){
            cin>>rt0>>lt>>rg;
            if(addnode(rt0,lt,rg)){
                elem[3*count]=-1;
                elem[3*count+1]=-1;
                elem[3*count+2]=-1;
                ++count;
            }
            else{
                elem[3*count]=-2;
                elem[3*count+1]=-2;
                elem[3*count+2]=-2;
                ++count;
            }
        }
        else if(kind==2){
            cin>>check;
            if(finda(1,check)){
                elem[3*count]=check;
                elem[3*count+1]=chTree[check].left;
                elem[3*count+2]=chTree[check].right;
                ++count;
            }
            else{
                elem[3*count]=-4;
                elem[3*count+1]=-4;
                elem[3*count+2]=-4;
                ++count;
            }

        }
        else{
            cin>>change;
            if(change!=1&&finda(1,change)){
                if(chTree[chTree[change].parent].left==change){
                    chTree[chTree[change].parent].left=chTree[chTree[change].parent].right;
                    chTree[chTree[change].parent].right=change;
                    elem[3*count+1]=chTree[chTree[change].parent].left;
                }
                else{
                    chTree[chTree[change].parent].right=chTree[chTree[change].parent].left;
                    chTree[chTree[change].parent].left=change;
                    elem[3*count+1]=chTree[chTree[change].parent].right;
                }
                elem[3*count]=-5;
                elem[3*count+2]=-5;
                ++count;
            }
            else{
                elem[3*count]=-6;
                elem[3*count+1]=-6;
                elem[3*count+2]=-6;
                ++count;
            }
        }
    }
    for(i=0;i<count;++i){
        switch(elem[3*i]){
            case -1:cout<<"OK!"<<endl;break;
            case -2:cout<<"Error!"<<endl;break;
            case -4:cout<<"Error!"<<endl;break;
            case -5:cout<<elem[3*i+1]<<endl;break;
            case -6:cout<<"Error!"<<endl;break;
            default:cout<<elem[3*i]<<elem[3*i+1]<<elem[3*i+2]<<endl;break;
        }
    }
    preOrder(1);
    delete [] chTree;
    return 0;
}

