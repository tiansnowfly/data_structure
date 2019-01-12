#include <iostream>
#include <cstring>
using namespace std;

int ans=0;
class stack{
    int size;
    char *elem;
    int top;
    void doubleSpace();
public:
    stack(int sz=10){
        size=sz;
        elem=new char[size];
        top=-1;
    }
    ~stack(){delete [] elem;}
    bool empty()const {return top==-1;}
    char getTop()const {return elem[top];}
    void push(const char &x){
        if(top==size-1) doubleSpace();
        elem[++top]=x;
    }
    char pop(){return elem[top--];}
};
void stack::doubleSpace(){
    char *tmp=elem;
    size*=2;
    elem=new char[size];
    for(int k=0;k<=top;++k) elem[k]=tmp[k];
    delete [] tmp;
}
int main(){
    stack st1(1001),st2(1001);
    char str[1001];
    int num_tmp,str_len=0,ct=0;
    char ch;
    while(true){
        ch=cin.get();
        if(ch=='\n') break;
        if(ch!=' ') str[str_len++]=ch;
    }
    ct=str_len-1;
    while(ct>=0){
        if(str[ct]=='*'||str[ct]=='/'||str[ct]=='-'||str[ct]=='+'){
            if(st2.empty()||st2.getTop()==')')st2.push(str[ct]);
            else if(str[ct]=='*'||str[ct]=='/')st2.push(str[ct]);
            else if(str[ct]=='-'||str[ct]=='+'){
                if(st2.getTop()=='-'||st2.getTop()=='+')st2.push(str[ct]);
                else if(st2.getTop()=='*'||st2.getTop()=='/'){
                    while(st2.getTop()!=')'&&!st2.empty()&&st2.getTop()!='+'&&st2.getTop()!='-'){
                        st1.push(st2.pop());
                    }
                    st2.push(str[ct]);
                }
            }
        }
        else if(str[ct]=='('){
             char ch_tmp;
             while((ch_tmp=st2.pop())!=')'&&!st2.empty())st1.push(ch_tmp);
        }
        else if(str[ct]==')') st2.push(str[ct]);
        else {
             st1.push(str[ct]);

        }
        --ct;
    }
    while(!st2.empty())st1.push(st2.pop());
    while(!st1.empty())cout<<st1.pop();
    return 0;
}
