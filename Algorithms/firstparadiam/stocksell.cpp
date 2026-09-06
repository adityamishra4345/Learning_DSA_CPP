#include<iostream>
#include<vector>
using namespace std;

int stock(vector<int>& arr){
    int i=0;
    int j=1;
    int maxi=0;
    int x=15;
    while(i<arr.size() && j< arr.size()){
        if(maxi<(arr[j]-arr[i]-x)){
            maxi=(arr[j]-arr[i])-x;
        }
        if((arr[j]-arr[i]-x)<=0) {
            i++; 
            x-=15;
            if(i==j){
                j++;
                x+=15;
            }
        }
        else{
            j++;
            x+=15;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr={10, 100, 80, 200};
    cout<<stock(arr);
    return 0;
}