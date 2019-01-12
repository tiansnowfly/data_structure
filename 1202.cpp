#include <iostream>
#include <cstring>
using namespace std;

 struct node{
     int data;
     node *next,*pre;
 };
int main(){
    string str1,str2;
    node *p1,*head1,*rear1,*p2,*head2,*rear2;
    int count1=0,count2=0,sL1,sL2,sL;

    cin>>str1>>str2;

    head1=rear1=new node;
    head2=rear2=new node;
    sL1=str1.length();
    sL2=str2.length();

    if(sL1>sL2){
        sL=sL1;
        while(count1<sL){
            p1=new node;
            p1->data=str1[sL1-1-count1]-48;
            rear1->next=p1;
            rear1=p1;
            ++count1;
        }
        while(count2<sL){
            p2=new node;
            if(count2<sL2) {p2->data=str2[sL2-1-count2]-48;}
            else{p2->data=0;}
            rear2->next=p2;
            rear2=p2;
            ++count2;
        }
        rear1->next=NULL;
        rear2->next=NULL;
    }
    else{
        sL=sL2;
        while(count1<sL){
            p1=new node;
            if(count1<sL1) {p1->data=str1[sL1-1-count1]-48;}
            else{p1->data=0;}
            rear1->next=p1;
            rear1=p1;
            ++count1;
        }
        while(count2<sL){
            p2=new node;
            p2->data=str2[sL2-1-count2]-48;
            rear2->next=p2;
            rear2=p2;
            ++count2;
        }
        rear1->next=NULL;
        rear2->next=NULL;
    }
    p1=head1->next;
    p2=head2->next;
    node *p,*head,*rear;
    head=rear=new node;
    int num=0;
    while(sL>0){
        p=new node;
        node *tmp;
        tmp=new node;
        p->data=(p1->data+p2->data)+num;
        if(p->data>=10){num=1;p->data=p->data-10;}
        else{num=0;}
        p1=p1->next;
        p2=p2->next;
        rear->next=p;
        tmp=rear;
        rear=p;
        p->pre=tmp;
        --sL;
    }
    rear->next=NULL;

    p=rear;
    if(num==1)cout<<num;
    while(p!=head){
        cout<<p->data;
        p=p->pre;
    }
    return 0;
}
