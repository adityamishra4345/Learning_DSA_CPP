#include<iostream>
#include<vector>

using namespace std;
void bubbleSort(vector<int>& arr,vector<int>& arr2) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr2[j], arr2[j + 1]);
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

vector<pair<int,int>> maxint(vector<int> start,vector<int> end){
    vector<pair<int,int>> final;
    bubbleSort(end,start);
    int lastEnd = end[0];
final.push_back({start[0], end[0]});

for(int i = 1; i < end.size(); i++){
    if( start[i]>=lastEnd ){ 
        final.push_back({start[i], end[i]});
        lastEnd =end[i];
    }
}
return final;
    
}