#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class list{
    private:
        T *data;
        int len;
    public:
        list(int x){
            len=x;
            data=new T[x];
        }
        void add(){
            for(int i=0;i<len;++i){
                cin>>data[i];
            }
        }
};
int main(){
    string type;
    //int ct1,ct2;
    //double ct3,ct4;
    list<double> ct;

    cin>>type;
    /*if(type=="int"){
        cin>>ct1>>ct2;
        list<int> A(ct1),B(ct2);
    }
    if(type=="double"){
        cin>>ct3>>ct4;
        list<double> A,B;
    }
    if{type=="char"}{list<char> A,B;}*/
    return 0;
}
