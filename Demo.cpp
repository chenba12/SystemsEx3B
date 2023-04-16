/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    const Fraction a(0, 1);
    const Fraction b(1, 2);
    Fraction c(1, 4);
    Fraction d(3, 4);
    Fraction e = a - a;
    Fraction f = c - d;
    cout << e << endl;
    cout << f << endl;
//    cout << "a: " << a << "b: " << b << endl;
//    cout << "a+b" << a + b << endl;
//    cout << "a-b" << a - b << endl;
//    cout << "a/b" << a / b << endl;
//    cout << "a*b" << a * b << endl;
//    cout << "2.3*b" << 2.3 * b << endl;
//    cout << "a+2.421" << a + 2.421 << endl;
//    Fraction c = a + b - 1;
//    cout << c++ << endl;
//    cout << --c << endl;
//    cout << "c >=b ? : " << (c >= b) << endl;
//    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
//    else cout << " a is smaller than 1.1" << endl;


}