#include <iostream>
using namespace std;

int main(){
    int data[12],lmb=0,d=0;
    double save=0;

    for(int i=0;i<12;++i)cin>>data[i];
    for(int j=0;j<12;++j){
        if((lmb+300-data[j])<0){
            cout<<"-"<<j+1;
            ++d;
            break;
        }
        else{
            lmb=300+lmb-data[j];
            if(lmb>=100){
                save=save+(lmb/100)*100;
                lmb=lmb-(lmb/100)*100;
            }
        }
    }
    if(d==0){
        save=save+0.2*save+lmb;
        cout<<save;
    }
    return 0;
}