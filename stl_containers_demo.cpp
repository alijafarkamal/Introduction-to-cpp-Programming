#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <set>
using namespace std;

int main() {
    cout << "=== Vector Demo ===" << endl;
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    
    cout << "Vector elements: ";
    for (const auto& num : numbers)
        cout << num << " ";
    cout << endl;
    
    numbers.pop_back();
    cout << "After pop_back: ";
    for (const auto& num : numbers)
        cout << num << " ";
    cout << endl;
    
    cout << "Element at index 2: " << numbers.at(2) << endl;
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    
    cout << "\n=== Array Demo ===" << endl;
    array<int, 4> arr = {1, 2, 3, 4};
    cout << "Array elements: ";
    for (const auto& num : arr)
        cout << num << " ";
    cout << endl;
    cout << "Array size: " << arr.size() << endl;
    
    cout << "\n=== List Demo ===" << endl;
    list<int> l(5, 100);
    cout << "List with 5 elements of 100: ";
    for (int i : l)
        cout << i << " ";
    cout << endl;
    
    cout << "\n=== Stack Demo ===" << endl;
    stack<string> s;
    s.push("kumar");
    s.push("john");
    s.push("ali");
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "After pop, top element: " << s.top() << endl;
    
    cout << "\n=== Priority Queue Demo ===" << endl;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    
    mini.push(5);
    mini.push(1);
    mini.push(3);
    mini.push(2);
    
    cout << "Min heap elements: ";
    int size = mini.size();
    for (int i = 0; i < size; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
    
    cout << "\n=== Set Demo ===" << endl;
    set<int> set1;
    set1.insert(5);
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    
    cout << "Set elements: ";
    for (auto i : set1)
        cout << i << " ";
    cout << endl;
    
    set<int>::iterator it = set1.begin();
    it++;
    set1.erase(it);
    cout << "After erasing second element: ";
    for (int i : set1)
        cout << i << " ";
    cout << endl;
    
    cout << "\n=== Map Demo ===" << endl;
    map<int, string> map1;
    map1[1] = "kumar";
    map1[12] = "john";
    map1[3] = "ali";
    map1.insert({4, "bheam"});
    
    cout << "Map elements:" << endl;
    for (auto i : map1)
        cout << i.first << ": " << i.second << endl;
    
    cout << "Count of key 12: " << map1.count(12) << endl;
    map1.erase(12);
    cout << "After erasing key 12, count: " << map1.count(12) << endl;
    
    cout << "\n=== Queue Demo ===" << endl;
    queue<string> q;
    q.push("kumar");
    q.push("john");
    q.push("ali");
    cout << "Front element: " << q.front() << endl;
    q.pop();
    cout << "After pop, front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    
    return 0;
} 