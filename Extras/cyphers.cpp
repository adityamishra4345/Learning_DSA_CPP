#include<iostream>
#include<vector>
using namespace std;
int main(){
     vector <char> a;
     cout<<"enter no of letters";
     int s;
     cin>>s;
     cout<<"Enter the text in Encrypt";
     char n;
     int c=0;
     
     for(int i=0;i<s;i++){
        cin>>n;
        a.push_back(n);
        c=i;
     }
     vector<char> b;
     char x;
     for(int i=0;i<c;i++){
        x=a[i]+3;
        if(x>'z'){
            int e;
            e=x;
            x=e-26;
            b.push_back(x);

        }
        else{
        b.push_back(x);
     }

     }
     for(char val:b){
        cout<<val;
     }

    return 0;
}