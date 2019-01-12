#include <iostream>
using namespace std;

struct node{
    int dt;
    node *next;
};
int main(){
    int i,n,m,num;
    node *head,*p,*q;
    head=new node;
    head->next=NULL;
    p=head;
    cin>>n;
    for(i=0;i<n;++i){
        q=new node;
        q->next=NULL;
        cin>>q->dt;
        p->next=q;
        p=q;
    }
    cin>>m;
    int sum=0,count;
    for(i=0;i<m;++i){
        cin>>num;
        count=0;
        node *savep=head,*p1=head->next;
        while(p1!=NULL&&p1->dt!=num){
            ++count;
            savep=p1;
            p1=p1->next;
        }
        if(p1!=NULL){
            ++count;
            savep->next=p1->next;
            p1->next=head->next;
            head->next=p1;
        }
        sum+=count;
    }
    cout<<sum;
    return 0;
}
