#include <iostream>
#include <cstring>
using namespace std;

struct linkNum{
    int data;
    linkNum *pre,*next;
    linkNum(){}
    linkNum(const int &dt,linkNum *pr=NULL,linkNum *nt=NULL)
    :data(dt),pre(pr),next(nt){}
    ~linkNum(){}
};
int main(){
    string str1,str2;
    linkNum *head,*rear;
    head=new linkNum();
    rear=new linkNum();
    int len1,len2;
    cin>>str1>>str2;
    len1=str1.length();
    len2=str2.length();
    return 0;
}
