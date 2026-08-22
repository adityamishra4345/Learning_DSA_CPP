#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int prod(vector<int>& arr,int left,int right){
    if(left==right) return arr[left];
    int mid=(left+right)/2;
    int left_prod=prod(arr,left,mid);
    int right_prod=prod(arr,mid+1,right);
    int i=mid;
    int j=mid+1; 
    int max1 = arr[i];
    int min1 = arr[i];
    int max2 = arr[j];
    int min2 = arr[j];
    if(arr[i]>0) max1=arr[i];
    else min1=arr[i];
    if(arr[j]>0) max2=arr[j];
    else min2=arr[j];
    int prod1=arr[i];
    int prod2=arr[j];
    i--;
    j++;
    while(i>=left){
        prod1*=arr[i];
        max1=max(max1,prod1);
        min1=min(prod1,min1);
        i--; 
        }
     while(j<=right){
        prod2*=arr[j];
        max2=max(prod2,max2);
        min2=min(prod2,min2);
        j++; 
        }
    int cross_max=max(max1*max2 , min1*min2);
    int ans=max({left_prod, right_prod, cross_max});
    return ans;
    
    
    
    
    
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
    cout<<"product is : "<<a;
    return 0;
}