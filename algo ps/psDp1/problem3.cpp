// Describe an efficient algorithm to compute the length of the shortest oscillating
// supersequence of an arbitrary array A of integers.

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr={3, 1, 5, 2, 4};
    if(arr.size()==0) return 0;
    if(arr.size()==1) return 1;
    bool curr=true;
    bool last;
    if(arr[1] < arr[0]) last = false;
    else last = true;
    int start = 2;
    if(arr[1] == arr[0]){
    arr.insert(arr.begin()+1, arr[0]+1);
    last = true;
    start = 3;
}
    for(int i=start;i<arr.size();i++){
        if(arr[i]<arr[i-1]) curr=false;
        else if(arr[i]>=arr[i-1]) curr=true;
        
        if(curr==last) {
            if(curr==false) arr.insert(arr.begin()+i,max(arr[i-1],arr[i])+1);
            else  arr.insert(arr.begin()+i,min(arr[i-1],arr[i])-1);
            i++;
        }
        last=curr;
    }
    cout<<arr.size();

}