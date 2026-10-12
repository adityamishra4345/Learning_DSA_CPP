#include<iostream>
#include<vector>

using namespace std;
vector<int> dp(100,-1);
int profit(vector<int>& cost,int i){
    if(i==0) return cost[i];
    if(i<0)  return 0;
    if(dp[i]!=-1) {
        return dp[i];
    }
    
    int a=cost[i]+profit(cost,i-2);
    int b=profit(cost , i-1);   
    dp[i]=max(a,b);
    return dp[i];
}

int main(){
    vector<int> cost={5,1,2,10,6};
    cout<<profit(cost,cost.size()-1);
}