#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int mom(vector<int> arr){
    if(arr.size()<=5) {
        sort(arr.begin(),arr.end());
        return arr[arr.size()/2];
    }
    vector<vector<int>> pentals;
    for(int i=0;i<arr.size();i+=5){
        vector<int> grps;
        for(int j=i;j<i+5 && j<arr.size();j++){
            grps.push_back(arr[j]);
        }
        pentals.push_back(grps);
    }
    for(int i=0;i<pentals.size();i++){
        sort(pentals[i].begin(),pentals[i].end());
    }

    vector<int> med;
    for(int i=0;i<pentals.size();i++){
        med.push_back(pentals[i][pentals[i].size()/2]);
    }
    
    return mom(med);
}


int pivot(vector<int> arr,int left,int right,int k){
    if(left==right) return arr[left];

    vector<int> send;
    for (int i = left; i <=right; i++)
    {
      send.push_back(arr[i]);
    }
    int a=mom(send);
    int b=a;
    vector<int> l;
    vector<int> r;
    vector<int> eq;
     for(int i=left;i<=right;i++){
        if(arr[i]==b){ 
            b=i; 
        break;
     } 
    }
    for(int i=left;i<=right;i++){
        if(arr[i]==arr[b]) eq.push_back(arr[i]);
        else if(arr[i]<arr[b]) l.push_back(arr[i]);
        else if(arr[i]>arr[b]) r.push_back(arr[i]);
    }
    if(l.size()>=k) return pivot(l,0,l.size()-1,k);
    else if(l.size()+eq.size()>=k) return arr[b];
    else return pivot(r,0,r.size()-1,k-l.size()-eq.size());  
}
int main(){
    vector<int> arr={2,5,1,4,4,8,9,5,5,5,5,5};
    cout<<pivot(arr,0,arr.size()-1,3);
    return 0;
}