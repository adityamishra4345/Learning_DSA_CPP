#include<iostream>
#include<vector>
using namespace std;

int stone(vector<int>& arr,int n){
    int min_energy=0;
    int p1=abs(arr[0]-arr[1]);
    int p2=0;
    for(int i=2;i<n;i++){
        int jump1=p1+abs(arr[i]-arr[i-1]);
        int jump2=p2+abs(arr[i]-arr[i-2]);

        min_energy=min(jump1,jump2);
        p2=p1;
        p1=min_energy;
    }
    return p1;
    }
int main(){
    int n;
    cout<<"Enter the no of the stones : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the heights of the stone : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<stone(arr,n);
}
    