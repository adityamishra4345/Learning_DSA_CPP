#include<iostream>
#include<vector>

using namespace std;

vector<int> dp(100);

vector<int> nos(100);

int fjump(vector<int>& cost,int n){
    dp[0]=cost[0];
    dp[1]=cost[1];
    for (int i = 2; i <cost.size(); i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return dp[n];
    
}

int main(){
    vector<int> cost={1,1,2,1,3,4};
    for(int i=0;i<100;i++){
        dp[i]=-1;
        nos[i]=0;
    }
     cout<<fjump(cost,cost.size()-1)<<"  ";
    for(int i=0;i<6;i++){
        cout<<dp[i]<<" ";
       
    }
   

}