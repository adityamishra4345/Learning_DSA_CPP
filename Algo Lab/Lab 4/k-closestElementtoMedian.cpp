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
void k_closest(vector<int> arr,int k){
    int median=find(arr,0,arr.size()-1,arr.size()/2);
    vector<int> final;
    
    vector<int> arr1(1000000,0);
    vector<int> arr2(1000000,0);
    
    int max1=0;
    int max2=0;
    for(int i=0;i<arr.size();i++){
        if((median-arr[i])<0) {
            arr1[abs(median-arr[i])]=arr[i];
            max1=arr[i]-median;
            
        }
        else {
            arr2[median-arr[i]]=arr[i];
            max2=median-arr[i];
        }

    }
    
    int i=0;
    int j=0;
    int a=0;
    while(i<k){
        if(i<k && arr1[j]!=0) {
            final.push_back(arr1[j]);
            j++;
            i++;
        } 
        else j++;
        if(i<k && arr2[a]!=0) {
            final.push_back(arr2[a]);
            a++;
            i++;
        }
        else a++;
    }

    for(int l=0;l<final.size();l++){
        cout<<final[l]<<" ";
    }
}
int main(){
    vector<int> arr={2,9,1,5,7};
    k_closest(arr,3);
    return 0;
}

