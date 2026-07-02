#include<iostream>
#include<vector>
using namespace std;
long long merge(vector<int>& arr,int left,int mid,int right){
    vector<int> L;
    vector<int> R;
    long long count = 0;
    for(int i=left;i<=mid;i++) L.push_back(arr[i]);
    for(int i=mid+1;i<=right;i++) R.push_back(arr[i]);

    int i=0;
    int j=0;
    int k=left;
    while(i<L.size()&&j<R.size()){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            k++;i++;
        }
        else{
            count+=(mid-left+1)-i;
            arr[k]=R[j];
            k++;j++;
        }
    }
    while(i<L.size()) arr[k++]=L[i++];
    while(j<R.size()) arr[k++]=R[j++];
    
    return count;
}

long long mergecount(vector<int>& arr , int left , int right){

    if(left>=right) return 0;
    long long count=0;
    int mid=(left+right)/2;
    count+=mergecount(arr,left,mid);
    count+=mergecount(arr,mid+1,right);
    count+=merge(arr,left,mid,right);

    return count;
}

int main(){
    vector<int> arr={1,4,7,21,32,4,51,8,786754,67};
    cout<<"No ot Total inversion is : "<<mergecount(arr,0,arr.size()-1);
    return 0;
}