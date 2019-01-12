#include <iostream> 
using namespace std;

class settest{
	friend settest operator*(const settest &a,const settest &b);
	friend settest operator+(const settest &a,const settest &b);
	friend settest operator-(const settest &a,const settest &b);
	private:
		int *elem;
		int size;
		int volume;
		void doubleSpace();
		bool exist(int x)const{
			for(int i=0;i<size;++i){
				if(elem[i]==x) return true;
			}
			return false;
		}
	public:
		settest(){size=0;volume=200;elem=new int[volume];}
		settest(const settest &a){
			size=a.size;
			volume=a.volume;
			elem=new int[volume];
			for(int i=0;i<size;++i) elem[i]=a.elem[i];
		}
		~settest(){delete [] elem;}
		settest &operator=(const settest &a);
		int getSize(){return size;}
		bool insertx(int x){
			if(exist(x))return false;
			if(size==volume) doubleSpace();
			elem[size++]=x;
			return true;
		}
		void clear(){
			size=0;
			delete [] elem;
			elem=new int[volume];
		}
		bool erasex(int x){
			bool flag=false;
			int i;
			for(i=0;i<size;++i){
				if(elem[i]==x){
				flag=true;
				break;
			   }
			}
			if(flag){
				for(;i<size-1;++i) elem[i]=elem[i+1];
			}
			return flag;
		}
		void display(){
			int tmp;
			for(int i=0;i<size;++i){
				for(int j=i+1;j<size;++j){
					if(elem[i]>elem[j]) {
						tmp=elem[i];
						elem[i]=elem[j];
						elem[j]=tmp;
					}
				}
			}
			for(int i=0;i<size;++i) cout<<elem[i]<<" ";
			cout<<endl;
		}
};
void settest::doubleSpace(){
	volume*=2;
	int *tmp=new int[volume];
	for(int i=0;i<size;++i)tmp[i]=elem[i];
	delete elem;
	elem=tmp;
}
settest &settest::operator=(const settest &a){
	size=a.size;
	delete []elem;
	elem=new int[size];
	for(int i=0;i<size;++i) elem[i]=a.elem[i];
	return *this;
}
settest operator*(const settest &a,const settest &b){
	settest c;
	for(int i=0;i<a.size;++i){
		if(b.exist(a.elem[i])) c.insertx(a.elem[i]);
	}
	return c;
}
settest operator+(const settest &a,const settest &b){
	settest c=a;
	for(int i=0;i<b.size;++i) c.insertx(b.elem[i]);
	return c;
} 
settest operator-(const settest &a,const settest &b){
	settest c;
	for(int i=0;i<a.size;++i){
		if(!b.exist(a.elem[i])) c.insertx(a.elem[i]);
	}
	return c;
}
int main(){
	int n,num,i,k,dt;
    char ch;
    cin>>n;
    settest q1,q;
    for(i=0;i<n;++i){
        cin>>ch;
        switch(ch){
        case '+':cin>>num;
                 for(k=0;k<num;++k) {
                    cin>>dt;
                    q1.insertx(dt);
                 }
                 q=q1+q;
                 q.display();
                 q1.clear();
                 break;
        case '-':cin>>num;
                 for(k=0;k<num;++k){
                    cin>>dt;
                    q1.insertx(dt);
                }
                q=q-q1;
                q.display();
                q1.clear();
                break;
        case '*':cin>>num;
                 for(k=0;k<num;++k){
                     cin>>dt;
                     q1.insertx(dt);
                 }
                 q=q*q1;
				 q.display();  
				 q1.clear();        
        }
    }
	return 0;  
}
