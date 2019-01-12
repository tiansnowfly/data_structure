#include <cstdio>
#define mx 100002

struct node{
    int parent;
    int *son;
    int len;
    int size;
    int volunm;
    node(){
        volunm=20;
        size=parent=len=0;
        son=new int[volunm];
    }
    void doubleSpace(){
        int *tmp=son;
        volunm*=2;
        son=new int[volunm];
        for(int k=0;k<len;++k) son[k]=tmp[k];
        delete [] tmp;
    }
};
node town[mx];
int main(){
    int n,num1,num2,i,j,tmp_parent,max_son=0;
    scanf("%d",&n);
    for(i=0;i<n-1;++i){
        scanf("%d%d",&num1,&num2);
        if(town[num1].len==town[num1].volunm-1)town[num1].doubleSpace();
        town[num1].son[town[num1].len++]=num2;
        ++town[num1].size;
        town[num2].parent=num1;
        tmp_parent=town[num1].parent;
        while(tmp_parent!=0){
            ++town[tmp_parent].size;
            tmp_parent=town[tmp_parent].parent;
        }
    }
    for(i=1;i<=n;++i){
        if(town[i].size+1<n/2)continue;
        max_son=0;
        for(j=0;j<town[i].len;++j){
            int son_size=town[town[i].son[j]].size+1;
            max_son=max_son>son_size?max_son:son_size;
        }
        if(max_son>n/2)continue;
        else printf("%d\n",i);
    }
    return 0;
}
