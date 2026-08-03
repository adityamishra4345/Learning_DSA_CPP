#include<iostream>
#include<vector>
using namespace std;

int ibs(vector<int>& arr,int left,int right){
    if(left>right) return -1;

    int mid=(left+right)/2;
    if(arr[mid]==mid){
        return mid;
    }
    else if(arr[mid]<mid){
        return ibs(arr,mid+1,right);

    }
    else {
        return ibs(arr,left,mid);
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
    cout<< ibs(arr,0,arr.size()-1)<<"\n";
}

