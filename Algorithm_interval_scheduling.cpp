#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare1(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
bool compare2(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.push_back({4,2});
    vec.push_back({3,3});
    vec.push_back({2,1});
    sort(vec.begin(),vec.end(),compare1);
    for(vector<pair<int,int>>::iterator itr=vec.begin();itr!=vec.end();++itr) {
        cout<<"("<<itr->first<<","<<itr->second<<")"<<endl;
    }
    sort(vec.begin(),vec.end(),compare2);
    for(vector<pair<int,int>>::iterator itr=vec.begin();itr!=vec.end();++itr) {
        cout<<"("<<itr->first<<","<<itr->second<<")"<<endl;
    }
    system("pause");
    return 0;
}