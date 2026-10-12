#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int divi(vector<int>& arr,int left,int right){
    if(left==right){
        return arr[left];
    }
    int mid=(left+right)/2;
    int lefty=divi(arr,left,mid);
    int righty=divi(arr,mid+1,right);
    int i=mid;
    int j=mid+1;
    
    int mini=min(arr[i],arr[j]);
    int maxi=2*mini;
    while(i>left || j<right){
        if(i==left){
            j++;
            mini=min(arr[j],mini);
            
        }
        else if(j==right){
            i--;
            mini=min(mini,arr[i]);
            
        }
        else if(arr[i-1]>arr[j+1]){
            mini=min(arr[i-1],mini);
            i--;
        }
        else {
            mini=min(arr[j+1],mini);
            j++;
        }
        int width=j-i+1;
        int cross=width*mini;
        if(cross>maxi) maxi=cross;
    }
  

    return max(max(lefty,righty),maxi);
}

int main(){
    vector<int> arr={2,1,5,6,2,3};
    cout<<divi(arr,0,arr.size()-1);
}