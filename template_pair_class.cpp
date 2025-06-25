#include<iostream>
using namespace std;

template<typename T>
class Pair {
    T values[2];
public:
    Pair(T x, T y) {
        values[0] = x;
        values[1] = y;
    }
    
    T GetMax() {
        if (values[0] > values[1])
            return values[0];
        return values[1];
    }
    
    T GetMin();
};

template<typename T>
T Pair<T>::GetMin() {
    if (values[0] > values[1])
        return values[1];
    return values[0];
}

int main() {
    Pair<double> myobject(1.012, 1.01234);
    cout << "Max value: " << myobject.GetMax() << endl;
    cout << "Min value: " << myobject.GetMin() << endl;
    
    return 0;
} 