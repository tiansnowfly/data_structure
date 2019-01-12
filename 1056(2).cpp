#include <cstdio>

class djs{
private:
    int size;
    int *parent;
public:
    djs(int s):size(s){
        parent=new int[size+1];
        for (int i=0;i<=size;++i) parent[i]=-1;
    }
    ~djs(){delete [] parent;}
    void unionx(int root1,int root2){
        root1=findx(root1);
        root2=findx(root2);
        if (root1==root2) return;
        if (parent[root1]>parent[root2]){
            parent[root2]+=parent[root1];
            parent[root1]=root2;
        }
        else{
            parent[root1]+=parent[root2];
            parent[root2]=root1;
        }
    }
    int findx(int x){
        int t=x;
        while (parent[t]>0) t=parent[t];
        if (parent[t]!=0) return t;
        else{
            while (parent[x]>0){
                t=x;
                x=parent[x];
                parent[t]=0;
            }
            return 0;
        }
    }
    void remove(int x){
        int t;
        while (parent[x]>0){
            t=x;
            x=parent[x];
            parent[t]=0;
        }
        parent[x]=0;
    }
    bool isEmpty(int a,int b){
        int r1=findx(a),r2=findx(b);
        return (r1!=0&&r2!=0&&r1!=r2);
    }
    int size_x(int x){return -parent[findx(x)];}
};
class array{
private:
    int *elem;
    int max;
public:
    array(int n){
        max=1;
        elem=new int[n+1];
        for (int i=2;i<=n;++i) elem[i]=0;
        elem[0]=elem[1]=n;
    }
    ~array(){delete [] elem;}
    void remove(int x){
        --elem[x];
        while (elem[max]==0) --max;
    }
    void insert(int x){
        ++elem[x];
        if (x>max) max=x;
    }
    void join(int a,int b){
        remove(a);
        remove(b);
        insert(a+b);
    }
    int query(int x){
        int n=max;
        while (n>0 && elem[n]<x){
            x-=elem[n];
            --n;
        }
        return n;
    }
};
int main(){
    int n,m,i,x,y;
    char ch;
    scanf("%d%d",&n,&m);
    getchar();
    djs p(n);
    array arr(n);
    for (i=0;i<m;++i){
        scanf("%c",&ch);
        if (ch=='C'){
            scanf("%d%d",&x,&y);
            if (p.isEmpty(x,y)){
                arr.join(p.size_x(x),p.size_x(y));
                p.unionx(x,y);
            }
        }
         else if (ch=='Q'){
            scanf("%d",&x);
            printf("%d\n",arr.query(x));
        }
        else{
            scanf("%d",&x);
            if (p.findx(x)!=0){
                arr.remove(p.size_x(x));
                p.remove(x);
            }
        }
        if(i!=m-1) getchar();
    }
}
