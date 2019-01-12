#include <iostream>
#include <iomanip>
using namespace std;

void qsort(long long* t,int l,int r){
    if (l>=r) return;
    int i=l,j=r;
    long long v=t[i];
    while (i<j){
        while((i<j)&&(t[j]>=v))--j;
        t[i]=t[j];
        while((i<j)&&(t[i]<=v))++i;
        t[j]=t[i];
    }
    t[i]=v;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main(){
    int n,i;
    cin>>n;
    long long *songs=new long long[n+1];
    long long sum=0,t;
    for (i=0;i<n;++i){
        cin>>t;
        songs[i]=sum;
        sum+=t;
    }
    songs[n]=sum;
    int m,j;
    cin>>m;
    long long* dancers[2];
    dancers[0]=new long long[m];
    dancers[1]=new long long[m];
    int num[2]={0,0};
    for (j=0;j<m;++j){
        int ss;
        long long tt;
        cin>>ss>>tt;
        dancers[ss-1][num[ss-1]++]=tt;
    }
    qsort(dancers[0],0,num[0]-1);
    qsort(dancers[1],0,num[1]-1);
    long long wait[2]={0,0};
    i=0;j=0;
    while(i<n){
        while(j<num[0]&&j<num[1]&&dancers[0][j]<=songs[i]&&dancers[1][j]<=songs[i]){
            wait[0]+=(songs[i]-dancers[0][j]);
            wait[1]+=(songs[i]-dancers[1][j]);
            ++j;
        }
        ++i;
    }
    for(i=j;i<num[0];++i) wait[0]+=songs[n-1]-dancers[0][i];
    for(i=j;i<num[1];++i) wait[1]+=songs[n-1]-dancers[1][i];
    cout<<fixed<<setprecision(2)<<wait[0]/double(num[0])<<" "<<wait[1]/double(num[1]);
    delete [] songs;
    delete [] dancers[0];
    delete [] dancers[1];
}
