#include<iostream>
#define mx 100001
using namespace std;

int new_array[mx],state[mx];
int value[mx],kind[mx],address[mx];

void quickSort(int low,int high){
    if(low>=high)return;
    int first=low;
    int last=high;
    int key=value[first];
    int key_=address[first];
    while(first<last){
        while(first<last&&value[last]>=key)--last;
        value[first]=value[last];
        address[first]=address[last];
        while(first<last&&value[first]< key)++first;
        value[last]=value[first];
        address[last]=address[first];
    }
    value[first]=key;
    address[first]=key_;
    quickSort(low, first-1);
    quickSort(first+1, high);
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>value[i];
        address[i]=i;
    }
    quickSort(1,n);
    kind[1]=1;
    for(int i=2;i<=n;++i){
        if(value[i]==value[i-1]) kind[i]=kind[i-1];
        else kind[i]=kind[i-1]+1;
    }
    for(int i=1;i<=n;++i) new_array[address[i]]=kind[i];
    state[new_array[1]]++;
    int ans=0;
    int num=1;
    int head=1;
    for(int i=2;i<=n;++i){
        if(num==k+1 and state[new_array[i]]==0){
            while(state[new_array[head]]!=1){
                state[new_array[head]]--;
                head++;
            }
            state[new_array[head]]--;
            head++;
            state[new_array[i]]++;
            if(state[new_array[i]]>ans) ans=state[new_array[i]];
        }
        else{
            if(state[new_array[i]]==0) num++;
            state[new_array[i]]++;
            if(state[new_array[i]]>ans) ans=state[new_array[i]];
        }
    }
    cout<<ans;
}

