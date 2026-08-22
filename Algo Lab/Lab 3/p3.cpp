#include<iostream>
#include<vector>
using namespace std;
int prod(vector<int> arr,int left,int right){
    if(left==right) return arr[left];
    int mid=(left+right)/2;
    int left_maj=prod(arr,left,mid);
    int right_maj=prod(arr,mid+1,right);

    if(left_maj==right_maj) return left_maj;
    
    int l1=0;
    int r1=0;
    for(int i=left;i<right+1;i++){
        if(right_maj==arr[i]) r1++;
        if(left_maj==arr[i]) l1++;
    }
    if(r1>l1) return right_maj;
    else if(r1<l1)return left_maj;
    return -1;
    
    
    
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
    int a=prod(arr,0,arr.size()-1);
    if(a==-1) cout<<"No Majority Element";
    else cout<<"Majority Element : "<<a;
    return 0;
}