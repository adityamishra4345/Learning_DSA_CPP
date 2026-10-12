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

int main(){
    vector<int> elements={3,5,9,2};
    vector<vector<int>> matrix(elements.size(),vector<int> (elements.size(),0));
    vector<ll*> arr;
    
    for(int i=0;i<elements.size();i++){
        ll* newnode= new ll(elements[i]);
        arr.push_back(newnode);
        char a;
        ll* c=arr[i];
        
        do{
            
            cout<<endl<<"Enter the value for  "<< arr[i]->val<<" : ";
            int ans;
            cin>>ans;
            ll* nn=new ll(ans);
            c->next=nn;
            c=nn;
            cout<<"Enter y to enter connections of "<<arr[i]->val<<" : ";
            cin>>a;
        }
        while(a=='y');
    }
    
    for(int i=0;i<elements.size();i++){
        ll* nn=arr[i]->next;
        while (nn!=NULL)
        {
        for(int j=0;j<elements.size();j++){
            if(nn->val==arr[j]->val)
                {
                matrix[i][j]=1;
            }
        }
        nn=nn->next;
    }
    }

    for(int i=0;i<elements.size();i++){
        for(int j=0;j<elements.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    
}