#include <iostream>
using namespace std;

int elem[6][6];
bool check[6][6];
int per[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int minCost;
int begin_x,begin_y,end_x,end_y;
void minCostBfs(int b_x,int b_y,int p_state,int answer){
    int next_x,next_y,per_cost;
    if(b_x==end_x&&b_y==end_y){
        if(answer<minCost)minCost=answer;
        return;
    }
    if(answer>minCost) return;
    for(int i=0;i<4;++i){
        next_x=b_x+per[i][1];
        next_y=b_y+per[i][0];
        if(next_x>5||next_y>5||next_x<0||next_y<0) continue;
        if(check[next_x][next_y]==true){
           check[next_x][next_y]=false;
           per_cost=elem[next_x][next_y]*p_state;
           minCostBfs(next_x,next_y,per_cost%4+1,answer+per_cost);
           check[next_x][next_y]=true;
        }
    }

}
int main(){
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<6;++i){
            for(int j=0;j<6;++j){
                cin>>elem[i][j];
                check[i][j]=true;
            }
        }
        minCost=9999999;
        cin>>begin_x>>begin_y>>end_x>>end_y;
        minCostBfs(begin_x,begin_y,1,0);
        cout<<minCost;
    }
    return 0;
}
