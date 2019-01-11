#include <iostream>
using namespace std;

class MyComplex{
    friend istream &operator>>(istream &in,MyComplex &obj);
    friend ostream &operator<<(ostream &out,const MyComplex &obj);
    friend MyComplex operator+(const MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator-(const MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator*(const MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator/(const MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator+=(MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator-=(MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator*=(MyComplex &obj1,const MyComplex &obj2);
    friend MyComplex operator/=(MyComplex &obj1,const MyComplex &obj2);
    private:
      double real;
      double imag;
    public:
      MyComplex (double x=0,double y=0){
          real=x;
          imag=y;
      }

};
istream &operator>>(istream &in,MyComplex &obj){
    in>>obj.real>>obj.imag;
    return in;
}
ostream &operator<<(ostream &out,const MyComplex &obj){
    out<<obj.real<<" "<<obj.imag;
    return out;
}
MyComplex operator+(const MyComplex &obj1,const MyComplex &obj2){
    MyComplex tmp;

    tmp.real=obj1.real+obj2.real;
    tmp.imag=obj1.imag+obj2.imag;
    return tmp;
}
MyComplex operator-(const MyComplex &obj1,const MyComplex &obj2){
    MyComplex tmp;

    tmp.real=obj1.real-obj2.real;
    tmp.imag=obj1.imag-obj2.imag;
    return tmp;
}
MyComplex operator*(const MyComplex &obj1,const MyComplex &obj2){
    MyComplex tmp;

    tmp.real=obj1.real*obj2.real-obj1.imag*obj2.imag;
    tmp.imag=obj1.real*obj2.imag+obj1.imag*obj2.real;
    return tmp;
}
MyComplex operator/(const MyComplex &obj1,const MyComplex &obj2){
    MyComplex tmp;
    double T=(obj2.real*obj2.real+obj2.imag*obj2.imag);

    tmp.real=(obj1.real*obj2.real+obj1.imag*obj2.imag)/T;
    tmp.imag=(obj2.real*obj1.imag-obj2.imag*obj1.real)/T;
    return tmp;
}
MyComplex operator+=(MyComplex &obj1,const MyComplex &obj2){
    obj1.real=obj1.real+obj2.real;
    obj1.imag=obj1.imag+obj2.imag;
    return obj1;
}
MyComplex operator*=(MyComplex &obj1,const MyComplex &obj2){
    double ob1=obj1.real;
    obj1.real=obj1.real*obj2.real-obj1.imag*obj2.imag;
    obj1.imag=ob1*obj2.imag+obj1.imag*obj2.real;
    return obj1;
}
MyComplex operator-=(MyComplex &obj1,const MyComplex &obj2){
    obj1.real=obj1.real-obj2.real;
    obj1.imag=obj1.imag-obj2.imag;
    return obj1;
}
MyComplex operator/=(MyComplex &obj1,const MyComplex &obj2){
    double ob2=obj1.real;
    double T=(obj2.real*obj2.real+obj2.imag*obj2.imag);
    obj1.real=(obj1.real*obj2.real+obj1.imag*obj2.imag)/T;
    obj1.imag=(obj2.real*obj1.imag-obj2.imag*ob2)/T;
    return obj1;
}
int main(){
    MyComplex z1;
    MyComplex z2;

    cin>>z1>>z2;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<z1+z2<<endl;
    cout<<z1-z2<<endl;
    cout<<z1*z2<<endl;
    cout<<z1/z2<<endl;
    cout<<(z1+=z2)<<endl;
    cout<<(z1-=z2)<<endl;
    cout<<(z1*=z2)<<endl;
    cout<<(z1/=z2)<<endl;

  return 0;
}
