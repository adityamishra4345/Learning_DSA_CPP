#include <iostream>
#include <algorithm>

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

long long karatsuba(long long x, long long y) {
    if (x == 0 || y == 0) return 0;
    if (x < 10 || y < 10) return x * y;
    
    long long w = max(x, y);
    int n = digi(w);
    int m = n / 2; 
    
    long long multiplier = powerOf10(m);

    long long a = x / multiplier;
    long long b = x % multiplier;
    long long c = y / multiplier;
    long long d = y % multiplier;
    
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long pq = karatsuba(a + b, c + d);
    
    long long middle = pq - bd - ac;
    
    long long res = (ac * powerOf10(2 * m)) + (middle * multiplier) + bd;
    return res;
}

int main() {
    long long a, b;
    cout << "Enter the 1st no: ";
    cin >> a;
    cout << "Enter the 2nd no: ";
    cin >> b;
    
    cout << "Result: " << karatsuba(a, b) << endl;
    return 0;
}