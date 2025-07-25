#include<iostream>
using namespace std;

template <class T, int N>
class Sequence {
    T memblock[N];
public:
    void setmember(int x, T value);
    T getmember(int x);
};

template<typename T, int N>
void Sequence<T, N>::setmember(int index, T value) {
    memblock[index] = value;
}

template<typename T, int N>
T Sequence<T, N>::getmember(int index) {
    return memblock[index];
}

int main() {
    Sequence<int, 5> myints;
    Sequence<double, 5> myfloats;
    
    myints.setmember(0, 100);
    myfloats.setmember(3, 3.1416);
    
    cout << "Integer at index 0: " << myints.getmember(0) << endl;
    cout << "Float at index 3: " << myfloats.getmember(3) << endl;
    
    return 0;
} 