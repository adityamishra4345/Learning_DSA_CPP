// . Call a sequence X[1..n] of numbers bitonic if there is an index i with 1 < i < n, such
// that the prefix X[1..i] is increasing and the suffix X[i..n] is decreasing. Describe an
// efficient algorithm to compute the length of the longest bitonic subsequence of an
// arbitrary array A of integers.



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lis(vector<int>& arr,vector<int>& dp) {
    int n = arr.size();
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
    vector<int> dpi(100,1);
    vector<int> arr={3, 1, 5, 2, 4};
    lis(arr,dpi);
    vector<int> dpl(100,1);
    reverse(arr.begin(),arr.end());
    lis(arr,dpl);
    int max=0;
    int n=arr.size();
    for(int i=0;i<arr.size();i++){
        if(dpi[i]+dpl[n-i-1]>max)  max=dpi[i]+dpl[n-i-1];
    }
    cout<<max-1;
    

}