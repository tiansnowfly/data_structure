#include <iostream>
using namespace std;

char str1[1001],str2[1001];
int len1,len2;
int len[1001][1001]={0};
int main(){
    cin>>len1>>len2;
    cin>>str1>>str2;
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(str1[i-1]==str2[j-1])len[i][j]=len[i-1][j-1]+1;
            else if(len[i][j-1]>len[i-1][j])len[i][j]=len[i][j-1];
            else len[i][j]=len[i-1][j];
        }
    }
    cout<<len[len1][len2];
    return 0;
}
