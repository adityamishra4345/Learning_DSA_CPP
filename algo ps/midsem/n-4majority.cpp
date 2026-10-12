#include<iostream>
#include<vector>

using namespace std;

bool maj(vector<int> arr){
    int a=0;
    int b=0;
    int c=0;
    int a1=arr[0];
    int b1=arr[1];
    int c1=arr[2];

    for(int i=0;i<arr.size();i++){
        if(arr[i]==a1) a++;
        else if(arr[i]==b1) b++;
        else if(arr[i]==c1) c++;
        else if(a==0) a1=arr[i];
        else if(b==0) b1=arr[i];
        else if(c==0) c1=arr[i];
        else{
            a--;
            b--;
            c--;
        }
    }
    a=0;b=0;c=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==a1) a++;
        if(arr[i]==b1) b++;
        if(arr[i]==c1) c++;
    }
    if(a>arr.size()/4 || b>arr.size()/4 || c>arr.size()/4) return true;

}

int main(){
    vector<int> arr={1,3,5,5,7,2,5,6};
    cout<<maj(arr);
}