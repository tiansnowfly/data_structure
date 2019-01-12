#include <iostream>
using namespace std;

int matrix[405][405];
struct numCount{
	long long odd;
	long long even;
};
numCount numCt[405][405];
int main(){
	int n,x,i,j,k;
	long long ans1=0,ans2=0;
	cin>>n;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>x;
			matrix[i][j]=x%2;
		}
	}
	for(i=1;i<=n;i++) {
		int sum=0;
		for(j=i;j<=n;j++) {
			sum+=matrix[1][j];
            numCt[i][j].even=(sum%2)^1;
            numCt[i][j].odd=(sum%2)&1;
            ans1+=numCt[i][j].odd;
            ans2+=numCt[i][j].even;
		}
	}
	for(k=2;k<=n;k++) {
		for(i=1;i<=n;i++) {
			int sum=0;
			for(j=i;j<=n;j++) {
				sum+=matrix[k][j];
				if(sum%2==0) numCt[i][j].even+=1;
				else{
					long long tmp=numCt[i][j].even;
					numCt[i][j].even=numCt[i][j].odd;
					numCt[i][j].odd=tmp+1;
				}
                ans1+=numCt[i][j].odd;
                ans2+=numCt[i][j].even;
			}
		}
	}
    cout<<ans1<<" "<<ans2;
	return 0;
}
