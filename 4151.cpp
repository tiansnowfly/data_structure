#include <iostream>
#define MAX 1000002
using namespace std;

int data[MAX],data0[MAX];
char ch[11];
class stack{
    private:
        int *elem;
        int top_p;
        int size;
        void dSpace();
    public:
        stack(int t=100){
            elem=new int[t];
            size=t;
            top_p=-1;
        }
        ~stack(){delete [] elem;}
        void clear(){top_p=-1;}
        bool isEmpty(){return top_p==-1;}
        void push(const int &x){
            if(top_p==size-1)dSpace();
            elem[++top_p]=x;
        }
        int top_pN(){return top_p;}
        int top(){return elem[top_p];}
        int pop(){return elem[top_p--];}
};
void stack::dSpace(){
    int *tmp=elem;

    elem=new int[2*size];
    for(int h=0;h<size;++h){
        elem[h]=tmp[h];
    }
    size*=2;
    delete [] tmp;
}
int main(){
    int T,n,x,ct,count=0;
    cin>>T;
    stack st(n+1);
    while(T>0){
        ct=1;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>data[i];
        }
        int c=1;
        for(int k=1;k<=n;++k){
            for(int j=c;j<=n;++j){
                st.push(j);
                ++c;
                if(st.top()==data[k]){
                    data0[ct]=st.pop();
                    ++ct;
                    break;
                }
            }
        }
        while(!st.isEmpty()){data0[ct]=st.pop();++ct;}
        bool flag=true;
        for(int r=1;r<=n;++r){
            if(data[r]!=data0[r])flag=false;
        }
        if(flag)ch[count++]='Y';
        else ch[count++]='N';
        --T;
    }
    for(int r=0;r<count;++r){
        if(ch[r]=='Y')cout<<"YES"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
