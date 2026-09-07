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


int sum(int x,int k){
    if(x<10 && k<10) return x+k;

    int n=digi(max(x,k));
    int m=floor(n/2);
    int a=floor(x/powerOf10(m));
    int b=floor(x%powerOf10(m));
    int c=floor(k/powerOf10(m));
    int d=floor(k%powerOf10(m));
    int ans1=sum(a,c);
    int ans2=sum(b,d);
    int res=(ans1)*powerOf10(m)+ans2;
    return res;   
}

int main(){
    cout<<sum(998,83);
}