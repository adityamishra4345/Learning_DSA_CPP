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

void maxint(vector<int>& start,vector<int>& end,vector<vector<pair<int,int>>>& ans){
    vector<pair<int,int>> final;
    bubbleSort(end,start);
    int lastEnd = end[0];
    final.push_back({start[0], end[0]});
    start.erase(start.begin());
    end.erase(end.begin());

    int i = 0; 
while (i < start.size()) {
    if (start[i] >= lastEnd) { 
        final.push_back({start[i], end[i]});
        lastEnd = end[i];
        start.erase(start.begin() + i);
        end.erase(end.begin() + i);
    } else { 
        i++;
    }
}
    ans.push_back(final);
    
}

int main(){
    vector<vector<pair<int,int>>> ans;
    vector<int> start={1,2,3,7};
    vector<int> end={3,4,5,8};
    while(start.size()>0){
        maxint(start,end,ans);
    }
    int k=1;
    for(int i=0;i<ans.size();i++){
        cout<<"Group "<<k <<": ";
        for(int j=0;j<ans[i].size();j++){
           cout<<"["<<ans[i][j].first<<","<<ans[i][j].second<<"]";           
        }
        k++;
        
        cout<<"\n";
    }
    

}