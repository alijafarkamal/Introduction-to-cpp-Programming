#include <iostream>
#include <algorithm>
using namespace std;
class flexibleVectors {
private:
    double* components;
    int dimensions;
public:
    // Constructor
    flexibleVectors() : components(nullptr), dimensions(0) {}

    // Constructor with specified dimensions
    flexibleVectors(int dim) : dimensions(dim) {
        components = new double[dim];
        for (int i = 0; i < dim; ++i)
            components[i] = 0.0;
    }

    // Copy constructor
    flexibleVectors(const flexibleVectors& other) : dimensions(other.dimensions) {
        components = new double[dimensions];
        for (int i = 0; i < dimensions; ++i)
            components[i] = other.components[i];
    }

    // Destructor
    ~flexibleVectors() {
        delete[] components;
    }

    // Overloading input operator >>
    friend istream& operator>>(istream& is, flexibleVectors& vec) {
        cout<<"Input \n";
        for (int i = 0; i < vec.dimensions; ++i)
            is >> vec.components[i];
        return is;
    }

    // Overloading output operator <<
    friend ostream& operator<<(ostream& os, const flexibleVectors& vec) {
        os << "[";
        for (int i = 0; i < vec.dimensions; ++i)
            os << vec.components[i] << " ";
        os << "]\n";
        return os;
    }

    // Overloading addition operator +
   friend flexibleVectors operator+(const flexibleVectors& obj,const flexibleVectors& other) {
        flexibleVectors result(max(obj.dimensions, other.dimensions));
        for (int i = 0; i < result.dimensions; ++i) 
            if (i < obj.dimensions && i < other.dimensions)
                result.components[i] = obj.components[i] + other.components[i];
            else if (i < obj.dimensions)
                result.components[i] = obj.components[i];
            else
                result.components[i] = other.components[i];
        return result;
    }
    friend flexibleVectors operator*(double scalar, const flexibleVectors& vec) {
        flexibleVectors result(vec.dimensions);
        for (int i = 0; i < vec.dimensions; ++i)
            result.components[i] = scalar * vec.components[i];

        return result;
    }

    flexibleVectors& operator=(const flexibleVectors& other) {
        if (this != &other) {
            if (dimensions != other.dimensions) {
                delete[] components;
                dimensions = other.dimensions;
                components = new double[dimensions];
            }
            for (int i = 0; i < dimensions; ++i)
                components[i] = other.components[i];
        }
        return *this;
    }
};

int main() {
 flexibleVectors v1, v2(2), v3(5);
 cin >> v2 >> v3;
 flexibleVectors v4 = v3;
 v1 = v2 + v3;
 cout << v1;
 cout << 3 * v4;
 return 0;
}
//Assume the following input for v2 and v3
v2= [-2 9], v3=[-9 0 7 3 4]
output must be [-9 0 7 1 13] 
output must be [-27 0 21 9 12