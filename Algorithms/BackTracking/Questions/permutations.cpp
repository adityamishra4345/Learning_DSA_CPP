#include<iostream>
#include<vector>
using namespace std;
void permu(vector<int>& arr,vector<int>& curr,vector<vector<int>>& final,vector<bool>& check){
    if(curr.size()==arr.size()){
        final.push_back(curr);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(check[i]!=true){
            check[i]=true;
            curr.push_back(arr[i]);
            permu(arr,curr,final,check);
            check[i]=false;
            curr.pop_back();
            
    }
}
   
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> final;
    vector<int> curr;
    vector<bool> check(3,false);
    permu(arr,curr,final,check);
    for (int i = 0; i < final.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout<<final[i][j];
           
        } cout<<"  ";
        
    }
    

}