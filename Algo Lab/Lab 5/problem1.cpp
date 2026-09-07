#include<iostream>
#include<vector>


using namespace std;
int mini(vector<int>& arr){
    int a=arr[0];
    int x=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<a){
             a=arr[i];
             x=i;
            }
    }
    arr[x]=__INT_MAX__;
    return a;
}

int find(vector<int>& arr){
    vector<int> final;
    int a=mini(arr);
    int b=mini(arr);
    int currsum=a+b;

   
    while(1){
        final.push_back(currsum);
        arr.push_back(currsum);
        int a=mini(arr);
        if(a==__INT_MAX__) break;
        int b=mini(arr);
        if(b==__INT_MAX__) {
            final.push_back(a);
            break;
        }
        currsum=a+b;
        
        
    }
    int sum=0;
    for(int i=0;i<final.size()-1;i++){
        sum+=final[i];
    }
    return sum;
}

int main(){
    vector<int> files={5,7,9,13};
    cout<<find(files);
}