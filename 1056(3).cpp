#include <iostream>
using namespace std;

int N,M;
class djs{
    int size;
    int *parent;
public:
    djs(int sz){
        size=sz;
        parent=new int[size];
        for(int k=1;k<=size;++k) parent[k]=-1;
    }
    ~djs(){delete [] parent;}
    void unionx(int root1,int root2){
        root1=find(root1);
        root2=find(root2);
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
    int find(const int &x){
        if(parent[x]<0) return x;
        return parent[x]=find(parent[x]);
    }
    void makeEmpty(const int &x){
        int tmp=find(x);
        parent[tmp]=0;
    }
    bool isEmpty(const int &x){
        int tmp=find(x);
        return parent[tmp]==0;
    }
    void sort_p(const int &p){
        int i,j,tmp,loc;
        int *tmp_parent=new int[size+1];
        for(i=1;i<=size;++i) tmp_parent[i]=parent[i];
        for(i=1;i<=p;++i){
            tmp=parent[i];
            loc=i;
            for(j=i+1;j<=size;++j){
                if(tmp>parent[j]){
                    tmp=parent[j];
                    loc=j;
                }
            }
            parent[loc]=parent[i];
            parent[i]=tmp;
        }
        cout<<-parent[p]<<endl;
        for(i=1;i<=size;++i)parent[i]=tmp_parent[i];
        delete [] tmp_parent;
    }
    int more_than_p(){
        int ct=0;
        for(int k=1;k<=size;++k){
            int tmp=find(k);
            if(parent[tmp]==0)++ct;
        }
        return ct;
    }
};
int main(){
    int i,x,y;
    char ch;
    cin>>N>>M;
    djs p(N+10);
    for(i=1;i<=M;++i){
        cin>>ch;
        if(ch=='C'){
            cin>>x>>y;
            if(p.find(x)!=p.find(y)) p.unionx(x,y);
        }
        else if(ch=='D'){
            cin>>x;
            if(!p.isEmpty(x))p.makeEmpty(x);
        }
        else{
            cin>>y;
            if((N-p.more_than_p())>=y) p.sort_p(y);
            else cout<<'0'<<endl;
        }
    }
    return 0;
}
