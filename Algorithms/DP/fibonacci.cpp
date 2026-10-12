#include<iostream>
#include<vector>
using namespace std;
long long dp[100];

long long fib(int n) {
    if(n<0) return 0;
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n]==-1) {
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
    else return dp[n];
}

int main() {
    for(int i=0;i<100;i++) dp[i]=-1;
   cout<<fib(9);
}