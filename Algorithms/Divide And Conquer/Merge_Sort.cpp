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
int main(){
    int n;
    cout<<"Enter the no of Elements of arr : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter elemnt : ";
        cin>>arr[i];
    }
    if(n > 0) mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}