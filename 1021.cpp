#include <iostream>
#include <iomanip>
using namespace std;

 int main(){
     int n,count;
     cin>>n;

     count=n*n;
     int data[n][n];
     for(int i=0;i<n;++i){
         for(int j=0;j<n;++j){
          if(i<j&&i<(n-1-i)&&i<(n-1-j)){
              int t=n,number=0;
              for(int k=0;k<i;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+j-(i-1);
          }
          if((n-1-j)<i&&(n-1-j)<j&&(n-1-j)<(n-1-i)){
              int t=n,number=0;
              for(int k=0;k<n-j-1;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+n-2*(n-1-j)+i-(n-j-1);
          }
          if((n-1-i)<i&&(n-1-i)<(n-1-j)&&(n-1-i)<j){
              int t=n,number=0;
              for(int k=0;k<n-i-1;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+2*(n-2*(n-1-i))-1+i-j;
          }
          if(j<i&&j<(n-1-j)&&j<(n-1-i)){
              int t=n,number=0;
              for(int k=0;k<j;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+3*(n-2*j)-2+n-1-j-i;
          }
          if(i==j&&(n-1-j)==(n-1-i)&&i<(n-1-i)){
              int t=n,number=0;
              for(int k=0;k<i;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+j-(i-1);
          }
          if(i==(n-1-j)&&j==(n-1-i)&&i<j){
              int t=n,number=0;
              for(int k=0;k<i;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+n-2*i;
          }
          if(i==j&&(n-1-j)==(n-1-i)&&i>(n-i-1)){
              int t=n,number=0;
              for(int k=0;k<n-j-1;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+2*(n-2*(n-1-i))-1;
          }
          if(i==(n-1-j)&&j==(n-1-i)&&i>j){
              int t=n,number=0;
              for(int k=0;k<j;++k){
                  number=number+4*t-4;
                  t=t-2;
              }
              data[i][j]=number+3*(n-2*j)-2;
          }
          if(i==(n-1-j)&&j==(n-1-i)&&i==j){
              data[i][j]=n*n;
          }
         }
     }
     for(int i=0;i<n;++i){
         for(int j=0;j<n;++j){
             cout<<setw(6)<<data[i][j];
         }
         cout<<endl;
     }
     return 0;
 }
