#include <iostream>
using namespace std;

int elem[10001];
int main(){
    int i,n,m,num,sum=0,j;
    cin>>n;
    for(i=0;i<n;++i) cin>>elem[i];
    cin>>m;
    for(i=0;i<m;++i){
        cin>>num;
        elem[n]=num;
        j=0;
        int tmp;
        while(num!=elem[j]) ++j;
        if(j==n)sum=sum+j;
        else {
            sum=sum+j+1;
            tmp=elem[j];
            for(int k=0;k<j;++k) elem[k+1]=elem[k];
            elem[0]=tmp;
        }
    }
    cout<<sum;
    return 0;
}
