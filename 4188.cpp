#include <iostream>
#include <string>
using namespace std;
int N,M;
string str[100001];
int main(){
    int i,kind,x,y;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(i=1;i<=N;++i)cin>>str[i];
    cin>>M;
    int k,h,len1,len2,anslen,len;
    for(i=0;i<M;++i){
        cin>>kind;
        if(kind==1){
            cin>>x;
            if(x==1)cout<<"no"<<'\n';
            for(k=1;k<x;++k){
                if(str[x]==str[k]){
                    cout<<"yes"<<'\n';
                    break;
                }
                else cout<<"no"<<'\n';
            }
        }
        else if(kind==2){
            cin>>x>>y;
            anslen=0;
            len1=str[x].length();
            len2=str[y].length();
            len=len1<len2?len1:len2;
            for(k=0;k<len&&str[x][k]==str[y][k];++k)++anslen;
            cout<<anslen<<'\n';
        }
        else {
            cin>>x>>y;
            anslen=0;
            len1=str[x].length();
            len2=str[y].length();
            for(k=len1-1,h=len2-1;str[x][k]==str[y][h];--k,--h);
            cout<<anslen<<'\n';
        }
    }
    cout<<flush;
    return 0;
}
