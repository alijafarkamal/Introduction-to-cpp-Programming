#include <iostream>
using namespace std;
void Eratosthenes(int first, int last) {
    bool arr[100] = { 0 };
    for (int i = first; i <= last; i++) 
        for (int j = i; j <= last; j += i)
            if (j % i == 0 && j != i ||( j%2==0 && j != 2 )|| j%3==0)
                arr[j - first] = true;        
    for (int i = 0; i <= last - first; i++)
        if (!arr[i]) cout << i + first << " ";
}
int main(){
    int m = 2, n = 100;
    Eratosthenes(m, n);
    return 0;
}