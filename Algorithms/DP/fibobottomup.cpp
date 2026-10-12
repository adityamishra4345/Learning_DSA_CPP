#include<iostream>
#include<vector>
using namespace std;
vector<long long> dp(100,-1);


int main() {
    int n=90;
    int i=2;
    dp[0]=0;
    dp[1]=1;
    while(i<=n){
        dp[i]=dp[i-1]+dp[i-2];
        i++;

    }
    cout<<dp[n];
}