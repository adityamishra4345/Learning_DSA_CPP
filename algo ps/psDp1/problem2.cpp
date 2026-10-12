// Call a sequence X[1..n] of numbers oscillating if X[i] < X[i + 1] for all even i, and
// X[i] > X[i + 1] for all odd i. Describe an efficient algorithm to compute the length
// of the longest oscillating subsequence of an arbitrary array A of integers.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int wiggle(vector<int>& arr,vector<int>& dpu,vector<int>& dpd) {
    int n = arr.size();
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) dpu[i] = max(dpu[i], dpd[j] + 1);
            if (arr[j] > arr[i]) dpd[i] = max(dpd[i], dpu[j] + 1);
                
        }
        ans =max(ans,max(dpu[i],dpd[i]));
    }
    return ans;
}


int main(){
    vector<int> dpu(100,1);
    vector<int> dpd(100,1);
    vector<int> arr={1, 2, 1, 3, 2};
    cout<<wiggle(arr,dpu,dpd);
    // int max=0;
    // int n= arr.size();
    // for(int i=0;i<n;i++){
    //     if(dpu[i]+dpd[n-i-1]>max)  max=dpu[i]+dpd[n-i-1];
    // }
    // cout<<max-1;
    

}