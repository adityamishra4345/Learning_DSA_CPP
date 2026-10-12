// 4. Call a sequence X[1..n] of numbers weakly increasing if each element is larger than
// the average of the two previous elements; that is, 2X[i] > X[i − 1] + X[i − 2] for all
// i > 2. Describe an efficient algorithm to compute the length of the longest weakly
// increasing subsequence of an arbitrary array A of integers.



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int weakly(vector<int>& arr,vector<vector<int>>& dp) {
    int n = arr.size();
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            for(int k=0;k<j;k++){
                if (arr[j]+arr[k] < 2*arr[i]) {
                    dp[i][j] = max(dp[i][j], dp[j][k] + 1);
            }}
        }
    }
    return ans;
}
