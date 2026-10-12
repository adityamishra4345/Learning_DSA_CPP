#include<iostream>
#include<vector>

using namespace std;

int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={3,4,1,5,5,31,3,34,11};
    cout<<lis(arr);
}