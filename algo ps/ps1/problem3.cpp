#include<iostream>
#include<vector>
using namespace std;
 
int findright(vector<int>& arr,int right,int t){
    if(arr[right]>t){
        return right;
    }
    return findright(arr,2*right,t);
}

int bs(vector<int>& arr,int left,int right,int t){
    if(left>=right) return -1;
    int mid=(left+right)/2;
    if(arr[mid]==t) return mid;
    else if(arr[mid]>t) return bs(arr,left,mid-1,t);
    else return bs(arr,mid+1,right,t);
}
int search(vector<int>& arr, int t){
    int right=findright(arr,1,t);
    return bs(arr,0,right,t);
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,209384,93284,238,912813980,923849028,238402};
    cout<<search(arr,5);

    return 0;
}