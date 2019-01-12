#include <iostream>
#define mx 51
using namespace std;

long long elem[mx][mx]={0};
long long answer=0;
int main(){
    int k,h,i;
    elem[0][0]=1;
    cin>>k>>h;
    for(i=1;i<h-1;++i){
        for(int j=0;j<k;++j){
            for(int r=0;r<k-j;++r){
                elem[i][j]+=elem[i-1][r];
            }
        }
    }
    for(i=0;i<k;++i){
        answer+=elem[h-2][i]*(k-i);
    }
    cout<<answer;
    return 0;
}
