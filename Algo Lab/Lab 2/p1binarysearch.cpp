#include<iostream>
#include<vector>
using namespace std;
int lb(vector<int>& arr,int left,int right,int target){
    if(left>right) return arr.size();
    
    int mid=(left+right)/2;
    if(arr[mid]>=target){
        // int ans=mid;
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
int lis(vector<int>& arr,int n){
    vector<int> fake;
    for(int i=0;i<n;i++){
        int idx=lb(fake,0,fake.size()-1,arr[i]);
        if(idx==fake.size()){
            fake.push_back(arr[i]);
        }
        else{
            fake[idx]=arr[i];
        }
    }
    return fake.size();
     
    }
int main(){
    int n;
   
  
    cout<<"Enter the lenght of array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elemetns of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis(arr,n);
}
    