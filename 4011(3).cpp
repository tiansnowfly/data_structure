#include <iostream>
using namespace std;

class bigNum{
    private:
        int contain[100];
        int size;
    public:
        bigNum(int n=0){
            size=0;
            int tmp;
            while((tmp=n%10)!=0){
                contain[size++]=tmp;
                n/=10;
            }
        }
        ~bigNum(){delete [] contain;}
        bigNum &operator=(int n){
            size=0;
            int tmp;
            while((tmp=n%10)!=0){
                contain[size++]=tmp;
                n/=10;
            }
            return *this;
        }
        bigNum &operator=(const bigNum &t){
            size=t.size;
            for(int i=0;i<size;++i){
                contain[i]=t.contain[i];
            }
            return *this;
        }
        bigNum operator+(const bigNum &t){
            int len1=size;
            int len2=t.size;
            int first_part=(len1>len2)?len2:len1;
            bool up=0;
            int tmp;
            bigNum res(0);
            res.size=0;
            int i;
            for(i=0;i<first_part;++i){
                tmp=contain[i]+t.contain[i]+up;
                res.contain[res.size++]=tmp%10;
                up=tmp/10;
            }
            if(len1>len2) for(;i<len1;++i){
                tmp=contain[i]+up;
                res.contain[res.size++]=tmp%10;
                up=tmp/10;
            }
            else{
                for(;i<len2;++i){
                tmp=t.contain[i]+up;
                res.contain[res.size++]=tmp%10;
                up=tmp/10;
                }
           }
           if(up) res.contain[res.size++]=1;
           return res;
       }
       bigNum operator+(const int &n){
           return *this+bigNum(n);
       }
       bigNum operator+=(const int &n){
           return *this=*this+n;
       }
       bigNum operator+=(const bigNum &t){
           return *this=*this+t;
       }
       friend ostream &operator<<(ostream &os,bigNum &t);
};
ostream &operator<<(ostream &os,bigNum &t){
    for(int i=t.size-1;i>=0;--i) {os<<t.contain[i];}
    return os;
}
int main(){
    int k,h;
    cin>>k>>h;
    bigNum *elem=new bigNum[k+1];
    bigNum *elem0=new bigNum[k+1];
    bigNum *tmp;
    for(int i=1;i<=k;++i){
        if(i==k) elem[i]=1;
        else elem[i]=0;
    }
    for(int i=1;i<h;++i){
        for(int j=1;j<=k;++j){
            elem0[j]=0;
            for(int l=k;l>k-j;--l){
                elem0[j]+=elem[l];
            }
        }
        tmp=elem0;
        elem0=elem;
        elem=tmp;
    }
    bigNum res=0;
    for(int i=1;i<=k;++i) res+=elem[i];
    cout<<res;
    return 0;
}
