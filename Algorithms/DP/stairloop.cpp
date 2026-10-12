#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cout << "Enter no of stairs : ";
    cin >> a;
    vector<int> dp(a + 1, -1);
    dp[0] = 1;
    
    for (int i = 1; i < a + 1; i++)
    {
        if(i==1) dp[i]=dp[i-1];
        else dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[a];
}