#include<iostream>
#include<vector>
using namespace std;
void combisum(vector<int>& arr,int start,vector<int>& curr,vector<vector<int>>& final,int currsum,int target){
    if(currsum>=target){
       if(currsum==target){
            final.push_back(curr);
       
       }
        return;
    }
    for(int i=start;i<arr.size();i++){

            curr.push_back(arr[i]);
            currsum+=arr[i];
            combisum(arr,i,curr,final,currsum,target);
            curr.pop_back();
            currsum-=arr[i];
}
   
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> final;
    vector<int> curr;
   
    combisum(arr,0,curr,final,0,8);
    for (int i = 0; i < final.size(); i++)
    {
        for (int j = 0; j < final[i].size(); j++)
        {
           cout<<final[i][j];
           
        } cout<<"  ";
        
    }
    

}