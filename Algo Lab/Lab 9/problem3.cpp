#include<iostream> 
#include<vector>

using namespace std;

class ll{
    public:
        int val;
        ll* next;
        ll(int value){
            this->val=value;
            this->next=NULL;
        }
};
//code to transform matrix to list
void matrixtolist(vector<vector<int>>& matrix,vector<ll*>& arr,vector<int>& elements){
    for(int i=0;i<elements.size();i++){
        ll* newnode= new ll(elements[i]);
        arr.push_back(newnode);
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            if(matrix[i][j]==1)
                {
                ll* nn=new ll(arr[j]->val);
                nn->next=arr[i]->next;
                arr[i]->next=nn;
            }
        }
    }
}
void printlist(vector<ll*>& arr){
    for(int i=0;i<arr.size();i++){
        ll* a=arr[i];
        while(a!=NULL){
            cout<<a->val<<"->";
            ll* temp=a;
            a=a->next;
            delete temp;
        }
        cout<<"NULL";
        cout<<endl;
        
    }

}
void transpose(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=i+1;j<matrix.size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}
int main(){
    vector<vector<int>> matrix={{0,1,0,1},{1,1,1,0},{0,1,0,1},{1,0,1,0}};
    vector<ll*> arr;
    vector<int> elements={3,5,9,2};
    transpose(matrix);
    matrixtolist(matrix,arr,elements);
    printlist(arr);
    
    
}