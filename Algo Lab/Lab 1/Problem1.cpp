#include<iostream>
#include<vector>
using namespace std;

int mbs(vector<int>& arr,int left,int right){
    if(left>right) return -1;

    int mid=(left+right)/2;
    if(mid<=mid) return left;
    if(mid>=arr.size()-1) return right;

    if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
        return mid;
    }
    else if(arr[mid]>arr[left]){
        return mbs(arr,mid+1,right);

    }
    else if(arr[mid]<arr[right]) {
        return mbs(arr,left,mid-1);
    }
}
int main(){
    vector<int> arr;
    int a=0;
    cout<<"Enter the no of elements ";
    cin>>a;
    int x=0;
    cout<<"Enter the elements : ";
    for(int i=0;i<a;i++){
        cin>>x;
        arr.push_back(x);
    }
    cout<< mbs(arr,0,arr.size()-1)<<"\n";
}

