#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> house={3,6,8,3,14};
    vector<int> dp(100);
    dp[0]=3;
    dp[1]=6;
    for(int i=2;i<house.size();i++){
        dp[i]=max(house[i]+dp[i-2],dp[i-1]);
    }
    cout<<dp[4];
    
}