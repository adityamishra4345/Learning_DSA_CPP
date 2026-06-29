#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the no of lines";
    cin >> n;
    int e=1;
    for(int i=1;i<=n;i++){
        for (int j=0;j<i;j++){
                cout << e;
                e=1-e;
        }
        cout << "\n";
    }
    

    return 0;
}
