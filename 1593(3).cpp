#include<iostream>
#define mx 200001
using namespace std;

struct node{
	int score;
	int power;
	int number;
	bool operator>(const node &obj)const{
		if (score!=obj.score) return score>obj.score;
		else return number<obj.number;
	}
	node(int s,int p,int i):score(s),power(p),number(i){}
    node(){}
};
int N,R;
int P[mx],S[mx];
node mice[mx];
class proque{
private:
	int len;
	node *elem;
	int size;
	void doubleSpace();
	void buildHeap();
	void preDown(int hole);
public:
	proque(int sz=mx){
		elem=new node[sz];
		size=sz;
		len=0;
	}
	~proque() {delete[]elem;}
	void enQueue(const node &x);
	node deQueue(){
	    node max_x;
	    max_x = elem[1];
	    elem[1] = elem[len--];
	    preDown(1);
	    return max_x;
	}
};
void proque::enQueue(const node &x){
	if(len==size-1) doubleSpace();
	int hole=++len;
	for(;hole>1&&x>elem[hole/2];hole/=2) elem[hole]=elem[hole/2];
	elem[hole]=x;
}
void proque::preDown(int hole){
	int child;
	node tmp=elem[hole];
	for (;hole*2<=len;hole=child){
		child=hole*2;
		if (child!=len&&elem[child+1]>elem[child])++child;
		if (elem[child]>tmp) elem[hole]=elem[child];
		else break;
	}
	elem[hole]=tmp;
}
void proque::buildHeap(){for(int i=len/2;i>0;--i)preDown(i);}
void proque::doubleSpace(){
	node *tmp=elem;
	size*=2;
	elem=new node[size];
	for (int i=0;i<=len;++i) elem[i]=tmp[i];
	delete[]tmp;
}
void sort(int number){
	if (number==0||mice[number-1]>mice[number]) return;
	node tmp = mice[number];
	while (number>0&&tmp>mice[number-1]){
		mice[number]=mice[number-1];
		--number;
	}
	mice[number]=tmp;
}
void compare(int num1,int num2){
	if (mice[num1].power>mice[num2].power){
		mice[num1].score+=2;sort(num1);
	}
	else if (mice[num1].power<mice[num2].power){
		mice[num2].score+=2;sort(num2);
	}
	else{
		mice[num1].score+=1; sort(num1);
		mice[num2].score+=1; sort(num2);
	}
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	proque q;
	node m1, m2,tmp;
	cin>>N>>R;
	for (int i=0;i<2*N;++i)cin>>P[i];
	for (int i=0;i<2*N;++i){
		cin>>S[i];
		q.enQueue(node(P[i],S[i],i+1));
	}
	for(int i=0;i<2*N;++i) mice[i]=q.deQueue();
	while (R--)for (int i=0;i<N;++i) compare(i*2,i*2+1);
	for(int i=0;i<2*N; ++i) cout<<mice[i].number<<" ";
	return 0;
}
