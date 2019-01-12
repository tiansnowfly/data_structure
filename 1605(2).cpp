#include <iostream>
using namespace std;

int op[1000002];
char str[1000002];

class stack{
    private:
        char *elem;
        int maxSize;
        int top_p;
        void doubleSpace();
    public:
        stack(int initSize=1000002){
            elem=new char[initSize];
            maxSize=initSize;
            top_p=-1;
        }
        ~stack(){delete [] elem;}
        void clear(){top_p=-1;}
        bool isEmpty()const{return top_p==-1;}
        void push(const char &x){
             if(top_p==maxSize-1){doubleSpace();}
             elem[++top_p]=x;
        }
        char pop(){return elem[top_p--];}
        char top()const {return elem[top_p];}
};
void stack::doubleSpace(){
    char *tmp=elem;
    elem=new char[2*maxSize];
    for(int h=0;h<maxSize;++h){
        elem[h]=tmp[h];
    }
    maxSize*=2;
    delete [] tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,ct=0;
    cin>>n;
    stack st,st0;

    int count=0;
    for(i=0;i<n;++i){
        cin>>op[i];
        switch(op[i]){
            case 1:cin>>str[ct];
                   st.push(str[ct]);
                   ++ct;
                   break;
            case 2:if(!st.isEmpty()){
                      st.pop();
                      ++count;
                      str[ct-count]='\0';}
                      break;
            case 3:if(!st.isEmpty()){cout<<st.top()<<'\n';}break;
            case 4:bool flag=true;
                   int k=0;
                   st0.clear();
                   while(flag&&(k<=(ct-count))&&str[k]!='\0'){
                   switch(str[k]){
                       case '(':case '[':case '{':st0.push(str[k]);break;
                       case ')':if(st0.top()!='(') {flag=false;}
                                else{st0.pop();}
                                break;
                       case '}':if(st0.top()!='{') {flag=false;}
                                else{st0.pop();}
                                break;
                       case ']':if(st0.top()!='[') {flag=false;}
                                else{st0.pop();}
                                break;
                       }
                   ++k;
                   }
                   if(flag&&st0.isEmpty()){cout<<"YES"<<'\n';}
                   else{cout<<"NO"<<'\n';}
                   break;
        }
    }
    return 0;
}
