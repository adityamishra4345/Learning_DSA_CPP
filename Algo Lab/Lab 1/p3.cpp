
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int mbs(vector<int>& arr,int left,int right,int z){
    if(left>=right) return -1;

  
    int pos=left+floor(((z-arr[left])*(right-left))/(arr[right]-arr[left]));

    if(arr[pos]==z){
        return pos;
    }
    else if(arr[pos]>z){
        return mbs(arr,left,pos,z);

    }
    else if(arr[pos]<z) {
        return mbs(arr,pos+1,right,z);
    }
}
int main(){
    vector<int> arr;
    int a=0; int z=0;
    cout<<"Enter the no of elements  and target";
    cin>>a;
    cin>>z;
    int x=0;
    cout<<"Enter the elements : ";
    for(int i=0;i<a;i++){
        cin>>x;
        arr.push_back(x);
    }
    cout<< mbs(arr,0,arr.size()-1,z)<<"\n";
}

