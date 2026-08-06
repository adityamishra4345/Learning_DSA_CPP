#include<iostream>
#include<vector>
using namespace std;

int binSerModified(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid=(left+right)/2;
    
    if(arr[mid]==target){
        
        int child = binSerModified(arr, left, mid-1, target);
        if(child == -1)
            return mid;
        else
            return child;
    }
    else if(arr[mid]<target){
         return binSerModified(arr,mid+1,right,target);
    }
    else{
        return binSerModified(arr,left,mid-1,target);
    }

    
}

int main(){
    vector<int> arr={1,2,3,3,3,3,4,5};
    cout<<binSerModified(arr,0,arr.size()-1,3)<<" \n";
    
}