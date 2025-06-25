#include <iostream>
#include <string>
using namespace std;

class book {
public:
    int num;
    int year;
    int publication;

    // Default constructor
    book() : num(0), publication(0), year(0) {
    }

    // Parameterized constructor
    book(int n, int y, int p) : num(n), year(y), publication(p) {
    }

    // Copy constructor
    book(const book& obj) : num(obj.num), year(obj.year), publication(obj.publication) {
    }

    void display() const {
        cout << "Number: " << num << endl;
        cout << "Year: " << year << endl;
        cout << "Publication: " << publication << endl;
        cout << endl;
    }
};

int main() {
    // Using the default constructor
    book bkDefault;
    cout << "Default Constructor:" << endl;
    bkDefault.display();

    // Using the parameterized constructor
    book bkParam(89, 2000, 1997);
    cout << "Parameterized Constructor:" << endl;
    bkParam.display();

    // Using the copy constructor
    book bkCopy(bkParam);
    cout << "Copy Constructor:" << endl;
    bkCopy.display();

    return 0;
} 