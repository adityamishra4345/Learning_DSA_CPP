#include<iostream>
#include<vector>
using namespace std;

void lis(vector<int>& arr,int i,vector<int>& curr,vector<vector<int>>& ll,int* max){
    if(i>=arr.size()){
        ll.push_back(curr);
        if(curr.size()>*max){
            *max=curr.size();
        }
        return;
    }
    if(curr.empty() || curr.back()<arr[i]){
        curr.push_back(arr[i]);
        lis(arr,i+1,curr,ll,max);
        curr.pop_back();
        lis(arr,i+1,curr,ll,max);
    }
    else{
        lis(arr,i+1,curr,ll,max);
    }
    
}

int main(){
    int n;
    vector<int> curr;
    vector<vector<int>> ll;
    int max=0;
    int k=0;
    cout<<"Enter the lenght of array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elemetns of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lis(arr,0,curr,ll,&max);
    cout<<max;
}