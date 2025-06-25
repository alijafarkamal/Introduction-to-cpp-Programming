#include<iostream>
using namespace std;

template<typename T, typename T1>
T GetMax(T x, T1 y) {
    if (x > y)
        return x;
    return y;
}

template<typename T, typename T1>
T GetMin(T x, T1 y) {
    if (x > y)
        return y;
    return x;
}

int main() {
    char i = 'Z';
    int j = 6, k;
    long l = 10, m = 5, n;
    
    k = GetMax<int, long>(i, m);
    n = GetMin<int, char>(j, l);
    
    cout << "Max: " << k << endl;
    cout << "Min: " << n << endl;
    
    return 0;
} 