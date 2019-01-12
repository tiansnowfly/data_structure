#include <cstdio>
#define mx 200002

struct node{
    int number;
    int power;
    int scores;
};
node arr[mx];
node tmp_node[mx];
class proque{
    int size;
    node *elem;
    int len;
    void preDown(int hole);
    void buildHeap();
    void doubleSpace();
public:
    proque(int sz=100){
        size=sz;
        len=0;
        elem=new node[sz];
    }
    ~proque(){delete [] elem;}
    void push(const node &nd){
        if(len==size-1) doubleSpace();
        int hole=++len;
        for(;hole>1&&elem[hole/2].scores<nd.scores;hole/=2)elem[hole]=elem[hole/2];
        elem[hole]=nd;
    }
    node pop(){
        node min_x=elem[1];
        elem[1]=elem[len--];
        preDown(1);
        return min_x;
    }
    bool empty()const{return len==0;}
    node getHead()const {return elem[1];}
};
void proque::preDown(int hole){
    int child;
    node tmp=elem[hole];
    for(;hole*2<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1].scores>elem[child].scores)++child;
        if(tmp.scores<elem[child].scores)elem[hole]=elem[child];
        else break;
    }
    elem[hole]=tmp;
}
void proque::buildHeap(){for(int k=len/2;k>0;--k)preDown(k);}
void proque::doubleSpace(){
    node *tmp=elem;
    size*=2;
    elem=new node[size];
    for(int k=1;k<=size;++k)elem[k]=tmp[k];
    delete tmp;
}
/*int divide(node a[],int low,int high){
    node k=a[low];
    do{
        while(low<high&&k.number>a[high].number)--high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&k.number<a[low].number) ++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
void quickSort(node a[],int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}*/
void sort(node a[],int len){
    node tmp;
    for(int i=1;i<len;++i){
        if(a[i].scores==a[i+1].scores){
            if(a[i].number>a[i+1].number){
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
            }
        }
    }
}
int N,R;
int main(){
    int i;
    proque q(mx);
    node ans;
    //cin>>N>>R;
    scanf("%d%d",&N,&R);
    for(i=1;i<=2*N;++i){
        //cin>>arr[i].scores;
        scanf("%d",&arr[i].scores);
        arr[i].number=i;
    }
    for(i=1;i<=2*N;++i){
        //cin>>arr[i].power;
        scanf("%d",&arr[i].power);
        q.push(arr[i]);
    }
    node mice1,mice2;
    while(R--){
        int ct=1;
        while(!q.empty()){
            mice1=q.pop();
            mice2=q.pop();
            if(mice1.power>mice2.power)mice1.scores+=2;
            else if(mice1.power<mice2.power)mice2.scores+=2;
            else {++mice1.scores;++mice2.scores;}
            tmp_node[ct]=mice1;
            ++ct;
            tmp_node[ct]=mice2;
            ++ct;
        }
        sort(tmp_node,2*N);
        //quickSort(tmp_node,1,2*N);
        for(i=1;i<=2*N;++i) q.push(tmp_node[i]);
    }
    while(!q.empty()){
        ans=q.pop();
        printf("%d",ans.number);
        printf(" ");
        //cout<<ans.number<<" ";
    }
    return 0;
}
