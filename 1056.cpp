#include <iostream>
using namespace std;

int N,M;
class djs{
    int volunm;
    int *parent;
public:
    djs(int sz){
        volunm=sz;
        parent=new int[volunm];
        for(int k=1;k<volunm;++k) parent[k]=-1;
    }
    ~djs(){delete [] parent;}
    void unionx(int root1,int root2){
        root1=findx(root1);
        root2=findx(root2);
        if(root1==root2) return;
        if(parent[root1]<parent[root2]){
            parent[root1]+=parent[root2];
            parent[root2]=root1;
        }
        else{
            parent[root2]+=parent[root1];
            parent[root1]=root2;
        }
    }
    int findx(const int &x){
        if(parent[x]<0) return x;
        return parent[x]=findx(parent[x]);
    }
    void makeEmpty(int x){
        int tmp=findx(x);
        parent[tmp]=0;
    }
    bool isEmpty(const int &x){
        int tmp=findx(x);
        return parent[tmp]==0;
    }
    void p_number(const int &p){
        int i,j,tmp,loc;
        int *tmp_parent=new int[volunm];
        for(i=1;i<volunm;++i) tmp_parent[i]=parent[i];
        for(i=1;i<=p;++i){
            tmp=parent[i];
            loc=i;
            for(j=i+1;j<volunm;++j){
                if(tmp>parent[j]){
                    tmp=parent[j];
                    loc=j;
                }
            }
            parent[loc]=parent[i];
            parent[i]=tmp;
        }
        cout<<-parent[p]<<endl;
        for(i=1;i<volunm;++i)parent[i]=tmp_parent[i];
        delete [] tmp_parent;
    }
};
int main(){
    int i,x,y;
    char ch0;
    cin>>N>>M;
    djs p(N);
    for(i=0;i<M;++i){
        cin>>ch0;
        if(ch0=='C'){
            cin>>x>>y;
            if(p.findx(x)!=p.findx(y)) p.unionx(x,y);
        }
        else if(ch0=='D'){
            cin>>x;
            if(!p.isEmpty(x))p.makeEmpty(x);
        }
        else {
            cin>>y;
            p.p_number(y);
        }
    }
    return 0;
}
