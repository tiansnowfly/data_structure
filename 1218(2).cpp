#include <iostream>
#define mx 10002
using namespace std;
int array[mx];
int ct=0;
class settest{
      private:
          int *elem;
          int len;
          int size;
          void doubleSpace();
          void preDown(int t);
          void buildHead();
      public:
          settest(int sz){
              elem=new int[sz];
              size=sz;
              len=0;
          }
          ~settest(){delete [] elem;}
          void insertx(const int &x){
              if(len==size-1)doubleSpace();

              int hole=++len;
              for(;hole>1&&x<elem[hole/2];hole/=2){
                  elem[hole]=elem[hole/2];
              }
              elem[hole]=x;
          }
          void decreasex(int x){
              for(int i=1;i<=len;++i){
                  if(elem[i]==x) {
                      elem[i]=elem[len--];
                      preDown(i);
                  }
              }
          }
          void printA(){
              int *tp=new int[len+1];
              int len0=len,i;
              for(i=1;i<=len;++i)tp[i]=elem[i];
              for(i=1;i<=len0;++i){
                  cout<<elem[1]<<" ";
                  elem[1]=elem[len--];
                  preDown(1);
              }
              len=len0;
              for(i=1;i<=len0;++i)elem[i]=tp[i];
          }
          void bin(int x){
              int low=1,high=len,mid;
              while(low<=high){
                  mid=(high+low)/2;
                  if(elem[mid]<x) low=mid+1;
                  else if(elem[mid]>x) high=mid-1;
                  else {array[ct]=x;++ct;break;}
              }
          }
          void reset(int n){
              len=ct;
              for(int i=0;i<n;++i){
                  elem[i+1]=array[i];
              }
              buildHead();
          }
};
void settest::buildHead(){
    for(int k=len/2;k>0;--k) preDown(k);
}
void settest::preDown(int hole){
    int child;
    int tmp=elem[hole];
    for(;hole*2<=len;hole=child){
        child=2*hole;
        if(child!=len&&elem[child+1]<elem[child])++child;
        if(elem[child]<tmp) elem[hole]=elem[child];
        else break;
    }
    elem[hole]=tmp;
}
void settest::doubleSpace(){
    int *tmp=elem;
    elem=new int[2*size];
    for(int k=0;k<size;++k){
        elem[k]=tmp[k];
    }
    size*=2;
    delete [] tmp;
}
int main(){
    int n,num,i,k,dt;
    char ch;
    cin>>n;
    settest q(mx);
    for(i=0;i<n;++i){
        cin>>ch;
        switch(ch){
        case '+':cin>>num;
                 for(k=0;k<num;++k) {
                    cin>>dt;
                    q.insertx(dt);
                 }
                 q.printA();
                 cout<<endl;
                 break;
        case '-':cin>>num;
                 for(k=0;k<num;++k){
                    cin>>dt;
                    q.decreasex(dt);
                }
                q.printA();
                cout<<endl;
                break;
        case '*':cin>>num;
                 for(k=0;k<num;++k){
                     cin>>dt;
                     q.bin(dt);
                 }
                 for(int k=0;k<ct;++k){
                     cout<<array[k]<<" ";
                 }
                 cout<<endl;
                 q.reset(ct);
                 ct=0;break;
        }
    }
    return 0;
}

