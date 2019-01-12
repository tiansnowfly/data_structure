#include <iostream>
#include <cstring>
using namespace std;

int ans=0;
class stack{
    int size;
    int *elem;
    int top;
    void doubleSpace();
public:
    stack(int sz=10){
        size=sz;
        elem=new int[size];
        top=-1;
    }
    ~stack(){delete [] elem;}
    bool empty()const {return top==-1;}
    int getTop()const {return elem[top];}
    void push(const int &x){
        if(top==size-1) doubleSpace();
        elem[++top]=x;
    }
    int pop(){return elem[top--];}
};
void stack::doubleSpace(){
    int *tmp=elem;
    size*=2;
    elem=new int[size];
    for(int k=0;k<=top;++k) elem[k]=tmp[k];
    delete [] tmp;
}
int main(){
    stack st1(1001),st2(1001);
    int str[1001];
    char str1[1001];
    int num_tmp,str_len=0,ct,i=0;
    cin.getline(str1,1001,'\n');
    int len=strlen(str1);
    while(i!=len){
        if(str1[i]==' ')++i;
        else if(str1[i]=='+'){str[str_len++]=-1;++i;}
        else if(str1[i]=='-'){str[str_len++]=-2;++i;}
        else if(str1[i]=='*'){str[str_len++]=-3;++i;}
        else if(str1[i]=='/'){str[str_len++]=-4;++i;}
        else if(str1[i]=='('){str[str_len++]=-5;++i;}
        else if(str1[i]==')'){str[str_len++]=-6;++i;}
        else{
            int num=0;
            while(str1[i]>='0'&&str1[i]<='9'){
                num=num*10+str1[i]-'0';
                ++i;
            }
            str[str_len++]=num;
        }
    }
    ct=str_len-1;
    while(ct>=0){
        if(str[ct]==-1||str[ct]==-2||str[ct]==-3||str[ct]==-4){
            if(st2.empty()||st2.getTop()==-6)st2.push(str[ct]);
            else if(str[ct]==-3||str[ct]==-4)st2.push(str[ct]);
            else if(str[ct]==-2||str[ct]==-1){
                if(st2.getTop()==-2||st2.getTop()==-1)st2.push(str[ct]);
                else if(st2.getTop()==-3||st2.getTop()==-4){
                    while(st2.getTop()!=-6&&!st2.empty()&&st2.getTop()!=-1&&st2.getTop()!=-2){
                        st1.push(st2.pop());
                    }
                    st2.push(str[ct]);
                }
            }
        }
        else if(str[ct]==-5){
             int ch_tmp;
             while((ch_tmp=st2.pop())!=-6&&!st2.empty())st1.push(ch_tmp);
        }
        else if(str[ct]==-6) st2.push(str[ct]);
        else {
             st1.push(str[ct]);

        }
        --ct;
    }
    while(!st2.empty())st1.push(st2.pop());
    while(!st1.empty()){
        int ch=st1.pop();
        st2.push(ch);
        if(ch==-1)cout<<"+ ";
        else if(ch==-2)cout<<"- ";
        else if(ch==-3)cout<<"* ";
        else if(ch==-4)cout<<"/ ";
        else {cout<<ch<<" ";}
    }
    cout<<endl;
    while(!st2.empty()){
        int tmp=st2.pop();
        if(tmp==-1||tmp==-2||tmp==-3||tmp==-4){
            int add;
            if(tmp==-1) add=st1.pop()+st1.pop();
            if(tmp==-2) add=st1.pop()-st1.pop();
            if(tmp==-3) add=st1.pop()*st1.pop();
            if(tmp==-4) add=st1.pop()/st1.pop();
            st1.push(add);
        }
        else st1.push(tmp);
    }
    cout<<st1.pop();
    return 0;
}
/*
1 + 2 * 3 - (4 + 44) / 15
*/
