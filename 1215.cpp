#include <iostream>
#include <cstring>
using namespace std;

class berlli{
      private:
          int *elem;
          int len;
          int size;
          void doubleSpace();
          void preDown(int t);
          void buildHead();
      public:
          berlli(int sz){
              elem=new int[sz];
              size=sz;
              len=0;
          }
          ~berlli(){delete [] elem;}
          void insertx(const int &x){
              if(len==size-1)doubleSpace();

              int hole=++len;
              for(;hole>1&&x<elem[hole/2];hole/=2){
                  elem[hole]=elem[hole/2];
              }
              elem[hole]=x;
          }
          int minx(){
              return elem[1];
          }
          void deletex(){
              elem[1]=elem[len--];
              preDown(1);
          }
};
void berlli::buildHead(){
    for(int k=len/2;k>0;--k) preDown(k);
}
void berlli::preDown(int hole){
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
void berlli::doubleSpace(){
    int *tmp=elem;
    elem=new int[2*size];
    for(int k=0;k<size;++k){
        elem[k]=tmp[k];
    }
    size*=2;
    delete [] tmp;
}
int main(){
    int n,num;
    string str;
    cin>>n;
    berlli ber(n+2);
    for(int i=0;i<n;++i){
        cin>>str;
        if(str[0]=='i') {cin>>num;ber.insertx(num);}
        if(str[0]=='d') ber.deletex();
        if(str[0]=='m') cout<<ber.minx()<<endl;
    }
    return 0;
}
