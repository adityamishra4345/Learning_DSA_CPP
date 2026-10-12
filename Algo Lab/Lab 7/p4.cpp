#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dp(100, vector<int>(100, 0));

void fjump(vector<vector<int>>& cost){
    dp[0][0]=cost[0][0];
    for(int i=0;i<cost.size();i++){
        for(int j=0;j<cost[i].size();j++){
            
            if(i==0){
                if(j!=0){
                dp[i][j]=cost[i][j]+dp[i][j-1];
                }
               }
            else if(j==0){
                 if(i!=0){
                dp[i][j]=cost[i][j]+dp[i-1][j];
            }
                 }
            else{
                dp[i][j]=cost[i][j] + max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
}

int main(){
    vector<vector<int>> cost={{1,1,2},{1,3,2},{1,1,1},{5,1,8}};
    fjump(cost);
    cout<<dp[cost.size()-1][cost[0].size()-1];
    
   

}