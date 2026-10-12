#include<iostream>
#include<vector>
using namespace std;


long long stair(int n,vector<int>& dp) {
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;

    if(dp[n]==-1) {
        dp[n]=stair(n-1,dp)+stair(n-2,dp);

    }
    return dp[n];
}

int main() {
    int a;
   cout<<"Enter no of stairs : ";
   cin>>a;
   vector<int> dp(a+1,-1);
   cout<<stair(a,dp);
   
}