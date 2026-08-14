#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void npermu(vector<int>& arr){
    int a=-1;
    int pair=-1;
    for(int i=arr.size()-1;i>0;i--){
        if(arr[i]>arr[i-1]) {
            a=i-1;
            break;
        }
    }
    if(a==-1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=arr.size()-1;i>0;i--){
        if(arr[i]>arr[a]) {
            pair=i;
            break;
        }
    }
    
    swap(arr[a],arr[pair]);
    reverse(arr.begin()+a+1,arr.end());
}

int main(){
    vector<int> arr={3,2,1};
    npermu(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
}