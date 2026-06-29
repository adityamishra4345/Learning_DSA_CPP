#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr,int left,int right){
    int pivot=arr[right];
    int i=left-1;
    for(int j=left;j<right;j++){
        if(arr[j]<pivot){
             i++;
             swap(arr[i],arr[j]);//sare pivot se chote pivot se pehle aa jai
        }
    }
    swap(arr[i+1],arr[right]);//pivot at its position
    return i+1;
}
void quicksort(vector<int>& arr,int left,int right){
    if(left>=right) return;
    int pivot=partition(arr,left,right);
    quicksort(arr,left,pivot-1);
    quicksort(arr,pivot+1,right);
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
    if(n > 0) quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<"\n";
    return 0;

}