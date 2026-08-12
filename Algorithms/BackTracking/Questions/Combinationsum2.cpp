#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr,int left,int mid,int right){
    vector<int> L;
    vector<int> R;
    int c=0;
    int l=left;
    for(int i=left;i<=mid;i++){
        L.push_back(arr[i]);
        c++;
    }
    c=0;
    for(int i=mid+1;i<=right;i++){
        R.push_back(arr[i]);
        c++;
    }
    int i=0,j=0;
    while(i<L.size()&&j<R.size()){
        if(L[i]<R[j]) {
            arr[l]=L[i];
            l++;
            i++;
        }
        else {
            arr[l]=R[j];
            j++;
            l++;
        }
    }
    while(i<L.size()){
        arr[l]=L[i];
        i++;l++;
    }
    while(j<R.size()){
        arr[l]=R[j];
        j++;l++;
    }
}

void mergesort(vector<int>& arr,int left,int right){
    if(left>=right) return;
    int mid=(left+right)/2;

     mergesort(arr,left,mid);
     mergesort(arr,mid+1,right);

     merge(arr,left,mid,right);

}

void combisumII(vector<int>& arr,int start,int currsum,int target,vector<int>& curr,vector<vector<int>>& final){
    if(currsum>=target){
        if(currsum==target) {
            final.push_back(curr);
            
        }
        return;
    }
    for(int i=start;i<arr.size();i++){
        if(i>start && arr[i]==arr[i-1]) continue;
        curr.push_back(arr[i]);
        currsum+=arr[i];
        combisumII(arr,i+1,currsum,target,curr,final);
        curr.pop_back();
        currsum-=arr[i];
    }
}

int main(){
    vector<int> arr={1,2,1};
    vector<vector<int>> final;
    vector<int> curr;
    mergesort(arr,0,arr.size()-1);
   
    combisumII(arr,0,0,3,curr,final);
    for (int i = 0; i < final.size(); i++)
    {
        for (int j = 0; j < final[i].size(); j++)
        {
           cout<<final[i][j];
           
        } cout<<"  ";
        
    }
    

}