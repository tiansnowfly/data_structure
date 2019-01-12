#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int len1,len2;
    string str1,str2;
    cin>>str1>>str2;
    len1=str1.length();
    len2=str2.length();
    int p[len2];
    int i,j;
    p[0]=-1;
    for(i=1;i<len2;++i){
        j=i-1;
        while(j>=0&&str2[p[j]+1]!=str2[i]) j=p[j];
        if(j<0) p[i]=-1;
        else p[i]=p[j]+1;
    }
    i=j=0;
    while(i<len1&&j<len2){
        if(str2[j]==str1[i]){++i;++j;}
        else if(j==0) ++i;
        else j=p[j-1]+1;
    }
    if(j==len2) cout<<i-j;
    return 0;
}
