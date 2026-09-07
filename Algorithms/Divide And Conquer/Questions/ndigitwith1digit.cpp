#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long digi(long long x) {
    if (x < 10) return 1;
    return 1 + digi(x / 10);
}

long long powerOf10(int m) {
    long long res = 1;
    for (int i = 0; i < m; ++i) {
        res *= 10;
    }
    return res;
}


int multi(int x,int k){
    if(x<10) return x*k;
    int n=digi(x);
    int m=floor(n/2);
    int a=floor(x/powerOf10(m));
    int b=floor(x%powerOf10(m));
    int ans1=multi(a,k);
    int ans2=multi(b,k);
    int res=(ans1)*powerOf10(m)+ans2;
    return res;   
}

int main(){
    cout<<multi(998,8);
}#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long digi(long long x) {
    if (x < 10) return 1;
    return 1 + digi(x / 10);
}

long long powerOf10(int m) {
    long long res = 1;
    for (int i = 0; i < m; ++i) {
        res *= 10;
    }
    return res;
}


int multi(int x,int k){
    if(x<10) return x*k;
    int n=digi(x);
    int m=floor(n/2);
    int a=floor(x/powerOf10(m));
    int b=floor(x%powerOf10(m));
    int ans1=multi(a,k);
    int ans2=multi(b,k);
    int res=(ans1)*powerOf10(m)+ans2;
    return res;   
}

int main(){
    cout<<multi(998,8);
}