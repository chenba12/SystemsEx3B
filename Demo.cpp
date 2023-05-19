#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5, 3), b(14, 21);
    cout << "a: " << a << "b: " << b << endl;
    float f = static_cast<float>(1) / 3;
    Fraction d(1, 333);
    cout << "d==f" << (d == f) << endl;
    cout << "d==f" << (d) << endl;
    cout << "d==f" << f << endl;
    cout << "a+b" << a + b << endl;
    cout << "a-b" << a - b << endl;
    cout << "a/b" << a / b << endl;
    cout << "a*b" << a * b << endl;
    cout << "2.3*b" << 2.3 * b << endl;
    cout << "a+2.421" << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;


}
