#include <iostream>
#include<vector>

using namespace std;

int maxim(vector<int> arr,int left,int right){
    if(left>=right) return arr[left] ;
    int mid=(left+right)/2;
    
    int x=maxim(arr,left,mid);
    int y=maxim(arr,mid+1,right);
      
     int maximum=max(x,y);
     return maximum;
}
int main() {
    vector<int> arr = {3, 1, 7, 22, 9, 4};
    cout << maxim(arr, 0, arr.size()-1);
    return 0;
}
