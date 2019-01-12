#include <iostream>
using namespace std;

struct mount{
    long long x,h;
}elem[100001];
int divide(int low,int high){
    long long  k1=elem[low].x,k2=elem[low].h;
    do{
        while(low<high&&elem[high].x>=k1)--high;
        if(low<high){
            elem[low].h=elem[high].h;
            elem[low].x=elem[high].x;
            ++low;
        }
        while(low<high&&elem[low].x<=k1)++low;
        if(low<high){
            elem[high].h=elem[low].h;
            elem[high].x=elem[low].x;
            --high;
        }
    }while(low!=high);
    elem[low].x=k1;
    elem[low].h=k2;
    return low;
}
void sort(int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(low,high);
    sort(low,mid-1);
    sort(mid+1,high);
}
int main(){
    int i,n,count=0;
    cin>>n;
    for(i=0;i<n;++i)cin>>elem[i].x;
    for(i=0;i<n;++i)cin>>elem[i].h;
    if(n==1||n==2)cout<<n<<endl;
    else{
        sort(0,n-1);
        for(i=1;i<n-1;++i){
            if(elem[i].x-elem[i].h>elem[i-1].x) ++count;
            else if(elem[i].x+elem[i].h<elem[i+1].x){
                ++count;
                elem[i].x+=elem[i].h;
            }
        }
    cout<<count+2<<endl;
    }
    return 0;
}
