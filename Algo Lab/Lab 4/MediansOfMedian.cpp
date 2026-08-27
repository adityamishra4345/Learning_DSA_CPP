#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//learn to debug the code

int mom(vector<int> arr){
    if(arr.size()==1) return arr[0];
    vector<vector<int>> divi;
    for(int i=0;i<arr.size();i+=5){
        vector<int> grp;
        for(int j=i;j<i+5&&j<arr.size();j++){
            grp.push_back(arr[j]);
        }
        divi.push_back(grp);
    }
    for(int i=0;i<divi.size();i++){
        sort(divi[i].begin(), divi[i].end());
    }
    vector<int> ans;
    for(int i=0;i<divi.size();i++){
        ans.push_back(divi[i][divi[i].size()/2]);
    }
    return mom(ans);
}

int find(vector<int>& arr,int left,int right,int k){
    if(left==right){
        return arr[left];
    }
    vector<int> sent;
    for(int i=left;i<=right;i++){
        sent.push_back(arr[i]);
    }
   
    int pivot = mom(sent);
    int pivotIndex = left;
    for(int i=left; i<=right; i++){
        if(arr[i] == pivot){
            pivotIndex = i;
            break;
        }
    }

    swap(arr[pivotIndex], arr[right]);
    int p = left;
    for(int i=left; i<right; i++){
        if(arr[i] < pivot){
            swap(arr[i], arr[p]);
            p++;
        }
    }
    swap(arr[p], arr[right]);
    if(k == p-left+1)
        return arr[p];
    else if(k < p-left+1)
        return find(arr, left, p-1, k);
    else
        return find(arr, p+1, right, k-(p-left+1));
   
}
int main(){
    vector<int> arr={2,5,1,4,4,8,9,5,5,5,5,5};
    cout<<find(arr,0,arr.size()-1,3);
    return 0;
}

