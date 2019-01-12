#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str1,str2;
    char st1[102],st2[102];
    char str0[102];
    int ch,sh=0,i;

    cin>>str1>>str2;
    int len1=str1.length(),len2=str2.length();
    int len=len1>=len2?len1:len2;

    if(len1>=len2){
         int t1=0;
          while(t1<len1-len2){st2[t1]='a';++t1;}
          for(i=0;i<len2;++i){
              st2[len1-len2+i]=str2[i];
          }
          for(i=0;i<len;++i){
              st1[i]=str1[i];
          }
    }
    if(len2>len1){
          int t2=0;
          while(t2<len2-len1){st1[t2]='a';++t2;}
          for(i=0;i<len1;++i){
              st1[len2-len1+i]=str1[i];
          }
          for(i=0;i<len;++i){
              st2[i]=str2[i];
          }
    }
    for(i=0;i<len;++i){
            ch=((st1[len-1-i]-'a')+(st2[len-1-i]-'a'));
            str0[len-i]=(sh+ch)%26+'a';
            sh=(sh+ch)/26;
    }
    if(sh==1){
        cout<<'b';
        for(i=1;i<len+1;++i){
            cout<<str0[i];
        }
    }
    if(sh==0){
        for(i=1;i<len+1;++i){
            cout<<str0[i];
        }
    }
    return 0;
}
