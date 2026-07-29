#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int left ,int right , int mid,int& inv){
    int i=left;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            inv+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=right){
        temp.push_back(arr[j]);
        j++;
    }
    i=0;
    for(int k=left;k<=right;k++){
        arr[k]=temp[i];
        i++;
    }
    
}

void ms(vector<int>& arr,int left , int right,int& inv){
    if(left==right) return ;
    int mid=(left+right)/2;
    ms(arr,left,mid,inv);
    ms(arr,mid+1,right,inv);
    merge(arr,left,right, mid,inv);
}

int main(){
    vector<int> arr={1,4,2,6,8,90,3};
    int inv=0;
    ms(arr,0,size(arr)-1,inv);
    cout<<inv<<"\n";
}