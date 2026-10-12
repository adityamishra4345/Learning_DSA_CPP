#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int>& arr,vector<int>& dead){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swap(dead[j],dead[j+1]);
            }
        }
    }
}


int lateness(vector<int>& ptime,vector<int>& deadline){
    bubble_sort(deadline,ptime);
    int max=-100000000;
    int end=ptime[0];
    for(int i=1;i<ptime.size();i++){
        end+=ptime[i];
        if(max<end-deadline[i]){
            max=end-deadline[i];
        }
    }
    return max;
}

int main(){
    vector<int> ptime={1,2,4,6};
    vector<int> deadline={9,7,5,6};
    cout<<lateness(ptime,deadline);
}
