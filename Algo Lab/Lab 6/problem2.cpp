#include<iostream>
#include<vector>
using namespace std;
int max(vector<int>& arr){
    int max=arr[0];
    int b=0;
    for(int i=0;i<arr.size();i++){
        if(max<arr[i]){ 
            max=arr[i];
            b=i;
        }
    }
    arr[b]=0;
    return max;
}

using namespace std;

int stop(vector<int> x,vector<int> f,int f1,int d){
    int fuel=f1;
    int totaldist=x[0];
    for(int i=0;i<x.size()-1;i++){
         


    }




}