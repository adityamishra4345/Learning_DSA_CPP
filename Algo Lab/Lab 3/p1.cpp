#include<iostream>
#include<vector>
using namespace std;

int missing_no(vector<int>& arr,int left,int right){
    if(left>right) return left;
    int mid=(left+right)/2;
    if(arr[mid]==mid+1){
        return missing_no(arr,mid+1,right);
    }
    else if(arr[mid]!=mid+1){
        return missing_no(arr,left,mid-1);
    }
}
int main(){
    vector<int> arr;
    int n=0;
    cout<<"Enter the no of elment in array";
    cin>>n;
    cout<<"Enter the Element : ";
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        arr.push_back(c);   
       
    }
    cout<<"Missing Number is : "<<missing_no(arr,0,arr.size()-1)+1;
    return 0;
}