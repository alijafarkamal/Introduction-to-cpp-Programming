#include <iostream>
#include <string>
using namespace std;

void rec(string str, int index) {
    if (index >= str.length()) {
        cout << str << endl;
        return;
    }
    
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        rec(str, index + 1);
        swap(str[index], str[i]);
    }
}

int main() {
    char arr[] = "abc";
    string ss = arr;
    cout << "All permutations of '" << ss << "':" << endl;
    rec(ss, 0);
    
    return 0;
} 