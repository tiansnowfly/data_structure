#include <iostream>
#define MAX 1000002
using namespace std;

int DT[MAX];
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T,T0,n,count=0;
    cin>>T;
    T0=T;
    stack st(MAX);
    while(T>0){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>DT[i];
        }
        int ct=0,ct0=1;
        while(ct<n){
            st.push(++ct);
            while(ct0<=n&&st.top()==DT[ct0]){
                st.pop();
                ++ct0;
            }
        }
        if(st.isEmpty())ch[count++]='Y';
        else ch[count++]='N';
        st.clear();
        --T;
    }
    for(int r=0;r<T0;++r){
        if(ch[r]=='Y')cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

