#include <iostream>
using namespace std;

char str1[1001],str2[1001];
int len1,len2;
int slen(char *str1,char *str2,int l1,int l2){
    if(l1>=len1||l2>=len2) return 0;
    if(str1[l1]==str2[l2])return slen(str1,str2,l1+1,l2+1)+1;
    else return slen(str1,str2,l1+1,l2)>slen(str1,str2,l1,l2+1)?slen(str1,str2,l1+1,l2):slen(str1,str2,l1,l2+1);
}
int main(){
    cin>>len1>>len2;
    cin>>str1>>str2;
    cout<<slen(str1,str2,0,0);
    return 0;
}
