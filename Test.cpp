#include "doctest.h"
#include "sources/Fraction.hpp"
#include <random>
#include <sstream>

using namespace ariel;


TEST_CASE("CTOR test") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
    int rand_num = dis(gen); //random number > 0
    CHECK_THROWS(Fraction(rand_num, 0));
    CHECK_NOTHROW(Fraction(0, rand_num));
    CHECK_NOTHROW(Fraction(0.2));
    CHECK_NOTHROW(Fraction(0, 1));
}

TEST_CASE("+ operator") {
    Fraction a(3, 5); // 3/5
    Fraction b(2, 5); // 2/5
    float scalar = 1;
    Fraction c(1, 6);
    Fraction d(1, 6);
    Fraction res1(1, 3);
    Fraction res2(8, 5);
    float res3 = 1.6;
    CHECK((a + b == scalar));
    CHECK((c + d == res1)); //check reduced form
    CHECK((scalar + a == res2));
    CHECK((scalar + a == res3));
    CHECK(((scalar + a == a + scalar) && (a + b == b + a)));
    CHECK(((a + b) + c == a + (b + c)));
}

TEST_CASE("- operator") {
    Fraction a(3, 5); // 3/5
    Fraction b(2, 5); // 2/5
    Fraction zero(0, 1);
    float zero_scalar = 0;
    float scalar = 0.4;
    Fraction res1(-1, 5);
    Fraction c(9, 10);
    Fraction d(1, 10);
    Fraction f(0, 1);
    Fraction reduced(4, 5);
    CHECK((a - a == zero));
    CHECK((c - d == reduced));
    CHECK((a - a == zero_scalar));
    CHECK((b - a == res1));
    CHECK(((scalar - a != a - scalar) && (a - b != b - a)));
    CHECK((a - a == f));
}

TEST_CASE("* operator") {
    Fraction a(3, 5); // 3/5
    Fraction b(2, 5); // 2/5
    float res_scalar = 0.24;
    Fraction c(2, 2);
    Fraction d(2, 1);
    CHECK((a * b == res_scalar));
    CHECK((c * d == d)); //check reduced form
    CHECK(((res_scalar * a == a * res_scalar) && (a * b == b * a)));
    CHECK((a * (b + c) == ((a * b) + (a * c))));
}

TEST_CASE("/ operator") {
    Fraction a(4, 6);
    Fraction b(2, 6);
    Fraction c(3, 6);
    Fraction res1(2, 1);
    CHECK(((a / b == 2) && (a / b == res1))); //reduced form
    CHECK((a / b != b / a));
    CHECK((((a / b) / c) != (a / (b / c))));

}

TEST_CASE("divide by 0") {
    Fraction a(3, 5);
    CHECK_THROWS(a / 0);
    CHECK_NOTHROW(0 / a);
}


TEST_CASE("negative numbers") {
    Fraction a(3, 5);
    Fraction b(-2, 5);
    Fraction c(-2, -5);
    CHECK(((a * -1) < 0));
    CHECK(((b * -1) > 0));
    CHECK(((a * -1) < 0));
    CHECK((c > 0));
    CHECK(((b / -1) > 0));
    CHECK(((a * b) < 0));
}

TEST_CASE(">=,<=,==,!=") {
    Fraction a(1, 5);
    Fraction b(1, 5);
    float scalar = 0.2;
    float scalar2 = 0.3;
    CHECK((a >= scalar));
    CHECK((a <= scalar));
    CHECK((a == scalar));
    CHECK((a == b));
    CHECK((a != scalar2));

}
TEST_CASE("fra++ and ++frac") {
    Fraction frac{2, 7};
    Fraction res{9, 7};
    CHECK_NE(frac++, res);
    CHECK_EQ(frac++, res);

    // Result changes signs
    Fraction neg_frac{-2, 7};
    Fraction neg_control{5, 7};
    CHECK_NE(neg_frac++, neg_control);
    CHECK_EQ(neg_frac++, neg_control);
}
TEST_CASE("frac-- and --frac") {
    Fraction frac{9, 7};
    Fraction res{2, 7};
    CHECK_NE(frac--, res);
    CHECK_EQ(frac--, res);
    Fraction neg_frac{2, 7};
    Fraction neg_control{-5, 7};
    CHECK_NE(neg_frac--, neg_control);
    CHECK_EQ(neg_frac--, neg_control);
}

TEST_CASE("input and output") {
    Fraction f1;

    // Simulate user input of "1/5"
    std::istringstream input("1 5");
    input >> f1;

    CHECK((f1 == 0.2));

    // Simulate output to console
    std::ostringstream output;
    output << f1;

    CHECK(output.str() == "1/5");
}





