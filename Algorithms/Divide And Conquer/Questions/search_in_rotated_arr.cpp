#include<iostream>
#include<vector>
using namespace std;

int rbs(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid = left + (right - left) / 2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid]>=arr[left]){
        if(arr[mid]>target && target>arr[left]){
            return rbs(arr,left,mid-1,target);
        }
        else{
            return rbs(arr,mid+1,right,target);
        }
    }
    else{
        if(arr[mid]<target && target<=arr[right]){
            return rbs(arr,mid+1,right,target);
        }
        else{
            return rbs(arr,left,mid-1,target);
        }
    }
    
}
int main(){
    vector<int> arr={4,5,6,7,0,1,2,3};
    cout<<rbs(arr,0,arr.size()-1,1);
    return 0;
}