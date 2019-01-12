#include <iostream>
#include <cstring>
//#include <cstdio>
#define MAX 200000
using namespace std;

int main(){
    char ch[MAX];
    char str[100][2000];
    int ct=0,len,i,j;
    cin.get(ch,MAX,'*');
    len=strlen(ch);
    int ch1[len],lineNumber=0;

    for(i=0;i<len;++i){
        if(ch!='\n'){str[ct][lineNumber]=ch;++lineNumber;}
        if(ch[i]=='\n'){++ct;lineNumber=0;}
    }
    string str0,str1;
    int x,y;

    cin>>str0;
    while(str0!="quit"){
        switch(str0){
            case str0=="list":cin>>x>>y;
            case str0=="ins":
            case str0=="del":
        }
    }
    return 0;
}

