#include<iostream>
#include<vector>
using namespace std;
int lb(vector<int> arr,int left,int right,int target){
    if(left>right) return arr.size();
    
    int mid=left + (right - left) /2 ;
    if(arr[mid]>target){
       
        int child=lb(arr,left,mid-1,target);
        if(child==arr.size()){
            return mid;
        }
        else{ 
            return child;
        }  
    }
    else{
        return lb(arr,mid+1,right,target);
    }
}
int main(){
    vector<int> arr={1,2,3,3,3,4,5,5,6};
    cout<<lb(arr,0,arr.size()-1,3);
    return 0;
}