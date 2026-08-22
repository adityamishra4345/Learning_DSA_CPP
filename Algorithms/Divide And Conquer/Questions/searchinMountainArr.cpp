#include<iostream>
#include<vector>
using namespace std;
void maxindex(vector<int>& arr,int left , int right,int& i){
    if(left>right) return ;
    int mid=(left+right)/2;
    
    if((mid==0 || arr[mid]>arr[mid-1]) && (mid==arr.size()-1 || arr[mid]>arr[mid+1])) i=mid;
    else if(arr[mid]<arr[mid+1]){
        return maxindex(arr,mid+1,right,i);
    }
    else{
        return maxindex(arr,left,mid-1,i);
    }
}
int dbs(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target){
         return dbs(arr,mid+1,right,target);
    }
    else{
        return dbs(arr,left,mid-1,target);
    }
}

int ibs(vector<int>& arr,int left,int right,int target){
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target){
         return ibs(arr,left,mid-1,target);
    }
    else{
        return ibs(arr,mid+1,right,target);
    }
}

int  mbs(vector<int>& arr,int target){
    int i;
    maxindex(arr,0,arr.size()-1,i);
    int a=ibs(arr,0,i,target);
    int b=dbs(arr,i+1,arr.size()-1,target);
    return max(a,b);


}
int main(){
    vector<int> arr={1,3,5,7,8,9,6,4,2};
    
    cout<<mbs(arr,6);
    return 0;
}