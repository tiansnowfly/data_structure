#include <iostream>
#include <cstring>
using namespace std;
int n,num1,num2;
int parent[26], son[26];
void move_onto(){
    int a=num1, b=num2, t;
    for (t=0; t<n; t++){
        if (son[t] == num1){son[t] = -1;break;}
    }
    while (son[a]>=0){
        t = son[a];
        parent[t] = t;
        son[a] = -1;
        a = t;
    }
    while (son[b]>=0){
        t = son[b];
        parent[t] = t;
        son[b] = -1;
        b = t;
    }
    son[num2] = num1;
    parent[num1] = parent[num2];
}
void move_over(){
    int a=num1, b=num2, t;
    for (t=0; t<n; t++){
        if (son[t] == num1){son[t] = -1;break;}
    }
    while (son[a]>=0){
        t = son[a];
        parent[t] = t;
        son[a] = -1;
        a = t;
    }
    while (son[b]>=0){
        b = son[b];
    }
    son[b] = num1;
    parent[num1] = parent[num2];
}
void pile_over(){
    int a=num1, b=num2, t;
    for (t=0; t<n; t++){
        if (son[t] == num1){son[t] = -1;break;}
    }
    while (son[b]>=0){
        b = son[b];
    }
    son[b] = num1;
    parent[num1] = parent[num2];
    while (son[a]>=0){
        parent[a] = parent[num2];
        a = son[a];
    }
}
void pile_onto(){
    int a=num1, b=num2, t;
    for (t=0; t<n; t++){
        if (son[t] == num1){son[t] = -1;break;}
    }
    while (son[b]>=0){
        t = son[b];
        parent[t] = t;
        son[b] = -1;
        b = t;
    }
    son[num2] = num1;
    parent[num1] = parent[num2];
    while (son[a]>=0){
        parent[a] = parent[num2];
        a = son[a];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    char ch1[5], ch2[5];
    cin >> n;
    int i,t;
    for (i=0; i<n; i++){parent[i] = i;son[i] = -1;}
    while (true){
        cin >> ch1;
        if (strcmp(ch1, "quit")==0)break;
        else{
            cin >> num1 >> ch2 >> num2;
            if (parent[num2] == parent[num1])continue;
            if (ch1[0]=='m' && ch2[1]=='n')move_onto();
            if (ch1[0]=='m' && ch2[1]=='v')move_over();
            if (ch1[0]=='p' && ch2[1]=='n')pile_onto();
            if (ch1[0]=='p' && ch2[1]=='v')pile_over();
        }
    }
    for (i=0; i<n; i++){
        t = i;
        cout << i << ": ";
        if (parent[i] != i){cout << "\n";continue;}
        else{
            cout << t << " ";
            while (son[t] >= 0){cout << son[t] << " ";t = son[t];}
            cout << "\n";
        }
    }
    return 0;
}
