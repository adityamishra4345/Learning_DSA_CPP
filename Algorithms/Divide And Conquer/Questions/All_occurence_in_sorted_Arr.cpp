#include<iostream>
#include<vector>
using namespace std;

int binSerModifiedf(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid=(left+right)/2;
    
    if(arr[mid]==target){
        
        int child = binSerModifiedf(arr, left, mid-1, target);
        if(child == -1)
            return mid;
        else
            return child;
    }
    else if(arr[mid]<target){
         return binSerModifiedf(arr,mid+1,right,target);
    }
    else{
        return binSerModifiedf(arr,left,mid-1,target);
    }

    
}

int binSerModifiedl(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid=(left+right)/2;
    
    if(arr[mid]==target){
        
        int child = binSerModifiedl(arr,mid+1,right, target);
        if(child == -1)
            return mid;
        else
            return child;
    }
    else if(arr[mid]<target){
         return binSerModifiedl(arr,mid+1,right,target);
    }
    else{
        return binSerModifiedl(arr,left,mid-1,target);
    }

    
}

int main(){
    vector<int> arr={1,2,3,3,3,3,4,5};
    int first = binSerModifiedf(arr,0,arr.size()-1,9);
    int last = binSerModifiedl(arr,0,arr.size()-1,9);
    
    if(first == -1)
        cout << 0;
    else
        cout << last - first + 1;
    
}