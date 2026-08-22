#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>& arr,int left,int right,int mid){
    int i=left;
    int j=mid+1;
    int invcount=0;
    vector<int> temp;

    while(i<=mid && j<=right){
        if(arr[i]>2*arr[j]){
            invcount+=mid-i+1;
            j++;
        }
        else i++;
    }
    
    i=left;
    j=mid+1;
     while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        else {
            temp.push_back(arr[i]);
            i++;
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
    return invcount;
}

void bs(vector<int>& arr,int left,int right,int* c){
    if(left>=right) return;
    int mid=(left+right)/2;
    bs(arr,left,mid,c);
    bs(arr,mid+1,right,c);
    (*c )+=count(arr,left,right,mid);
}

int main(){
    vector<int> arr={2, 4, 3, 5, 1};
    int c=0;
    bs(arr,0,arr.size()-1,&c);
    cout<<c;
    return 0;
}