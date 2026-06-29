#include <iostream>
using namespace std;
int rev(int arr[],int a){
    int i=0;
    int j=a;
    int temp=0;
    while(a>i){
        temp=arr[i];
        arr[i]=arr[a-1];
        arr[a-1]=temp;
        i++;
        a--;       
    }
    i=0;
    cout<<"\n";
    while(i<j){
        cout<<arr[i]<<" ";
        i++;
    }


}
int main()
{
    int arr[50];
    cout<<"Enter the no of elements in you arr : ";
    int a;
    cin>>a;
    int i=a;
    while(i>0){
        cout<<"Enter the elment";
        cin>>arr[a-i];
        i--;
    }
    i=0;
    while(i<a){
        cout<<arr[i]<<" ";
        i++;
    }
    rev(arr,a);

    
    

    

    return 0;
}