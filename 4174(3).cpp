#include<iostream>//8 3 1 1 0 0 1 0 1 0 2 3 5 1 3 7 1 3 2 8
using namespace std;
struct node{
	int val;
	int l,r;
	node(int x=-1,int y=-1,int z=-1):val(x),l(y),r(z){}
};
node tree[1<<18];
int *arr;int ans,tmp;//全局变量少用，尽量传址

void pushup(int i){
	for(int t=i;t>0;t/=2){
		tree[t].val=tree[t<<1].val+tree[t<<1|1].val;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;tree[i].r=r;
	if(l==r){tree[i].val=arr[l];return;}//叶节点赋值01序列，回撤
	if(l<r){
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build(i<<1|1,mid+1,r);
		pushup(i);//推
	}
}
void querynum(int i,int l,int r){
	//cout<<i<<' '<<l<<' '<<r<<endl;
	if(l<=tree[i].l&&r>=tree[i].r) {ans+=tree[i].val;return;}//囊括，返回值
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid) querynum(i<<1,l,r);
	if(r>mid) querynum(i<<1|1,l,r);
}
void change(int i,int l,int r,int x){
	//cout<<"deep into "<<i<<' '<<tree[i].l<<' '<<tree[i].r<<endl;
	if(tree[i].l==tree[i].r){tree[i].val=x;cout<<"叶子 "<<i<<' '<<tree[i].l<<' '<<x<<endl;return;}//到达叶节点，change
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid) change(i<<1,l,r,x);
	if(r>mid) change(i<<1|1,l,r,x);
	pushup(i);
}

void querycon(int i,int l,int r){//中序遍历，遇到叶节点就判定，先判在区间内，1则累加，更新最值，0则清空，
	if(tree[i].l==tree[i].r) {
		if(tree[i].l>=l&&tree[i].r<=r&&tree[i].val==1) {
		tmp+=1;ans=(ans>tmp)?ans:tmp;//cout<<"tmp "<<tmp<<"ans "<<ans<<endl;
		}
		else tmp=0;
		return;
	}
	querycon(i<<1,l,r);
	querycon(i<<1|1,l,r);
}
int main(){
	int n,m,oper,l,r,x;cin>>n>>m;
	arr=new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	for(int i=0;i<m;i++){
		cin>>oper;
		switch(oper){
			case 1:cin>>l>>r>>x;
			change(1,l,r,x);break;
			case 2:cin>>l>>r;ans=0;
			querynum(1,l,r);cout<<ans<<endl;break;
			case 3:cin>>l>>r;ans=tmp=0;
			querycon(1,l,r); cout<<ans<<endl;break;
		}
	}

}

