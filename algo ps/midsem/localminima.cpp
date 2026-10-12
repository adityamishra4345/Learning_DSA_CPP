#include<iostream>
#include<vector>
using namespace std;

int lm(vector<int>& arr,int l,int r){
    if(l>=r) return arr[l];
    int mid=(l+r)/2;
    // if(mid==arr.size()-1) return arr[arr.size()-1];
    if(arr[mid+1]>arr[mid]) return lm(arr,l,mid);
    else return lm(arr,mid+1,r);  
}
int main(){
    vector<int> arr={2,1,3};
    cout<<lm(arr,0,arr.size()-1);

}               