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
    for(int i=0;i<len1;++i){
        if(!strncmp(&str1[i],&str2[0],len2)){
            cout<<i;
            break;
        }
    }
    return 0;
}
/*
abadedsbcabc
bcab
*/
