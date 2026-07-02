#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> mono(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    stack<int> a;
    for(int i=0;i<n;i++){
        while(!a.empty() && arr[i]>arr[a.top()]){
            ans[a.top()]=arr[i];
            a.pop();
        }
        a.push(i);
    }
    return ans;


}
//this code will return arr with greater elemnt of each

int main(){
    vector<int> arr = {4, 5, 2, 10};
    vector<int> result = mono(arr);
    for(int x : result) cout << x << " ";
    return 0;
    
}