//
// Created by chen on 4/14/23.
//

#include <limits>
#include "Fraction.hpp"

namespace ariel {

    /**
     * empty constructor
     */
    Fraction::Fraction() : numerator(0), denominator(1), gcdVal(0) {

    }

    /**
     * basic constructor that get 2 ints
     * @param numerator
     * @param denominator
     */
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator),
                                                         gcdVal(0) {
        if (denominator == 0) {
            throw std::invalid_argument("division by 0");
        }
    }

    /**
     * copy constructor
     * @param other fraction to copy from
     */
    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->gcdVal = other.gcdVal;
    }

    /**
     * float constructor
     * @param number
     */
    Fraction::Fraction(float number) : gcdVal(0) {
        this->numerator = (int) (number * 1000);
        this->denominator = 1000;
        reduce();
    }

    /**
     *  assigment operator constructor
     * @param other fraction
     * @return
     */
    Fraction &Fraction::operator=(const Fraction &other) = default;


    Fraction &Fraction::operator=(float number) {
        this->numerator = (int) (number * 1000);
        this->denominator = 1000;
        this->gcdVal = 0;
        return *this;
    }

    /**
     *  assigment move operator copy the fields of the other fraction into this
     *  and change the other fraction to 0/1 (default fraction)
     * @param other fraction
     * @return
     */
    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        other.numerator = 0;
        other.numerator = 1;
        return *this;
    }

    /**
     * move
     * @param other
     */
    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->gcdVal = other.gcdVal;
    }

    /**
     * destructor
     */
    Fraction::~Fraction() = default;

    /**
     * used < to implement the rest of the comparison operators
     * >, < ,== ,!= ,>= ,<=
     */

    /**
     * == operator functions
     */
    bool Fraction::operator==(const Fraction &other) const {
        float a = static_cast<float>(this->numerator) / static_cast<float>(this->denominator);
        float b = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
        float epsilon = 0.001;
        return std::abs(a - b) < epsilon;
    }

    bool Fraction::operator==(float number) const {
        Fraction fraction(number);
        return *this == fraction;
    }

    bool operator==(float number, const Fraction &other) {
        const Fraction fraction(number);
        return other == fraction;
    }

    /**
     * != operator functions
     */
    bool Fraction::operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool Fraction::operator!=(float number) const {
        const Fraction fraction(number);
        return !(*this == fraction);
    }

    bool operator!=(float number, const Fraction &other) {
        const Fraction fraction(number);
        return !(other == fraction);
    }

    /**
     * < operator functions
     */
    bool Fraction::operator<(const Fraction &other) const {
        Fraction a(*this);
        Fraction b(other);
        if (denominator < 0) {
            a.denominator = std::abs(a.denominator);
            a.numerator = (-1) * a.numerator;
        }
        if (other.denominator < 0) {
            b.denominator = std::abs(b.denominator);
            b.numerator = (-1) * b.numerator;
        }
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }

    bool Fraction::operator<(float number) const {
        Fraction numberFraction(number);
        return *this < numberFraction;
    }

    bool operator<(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction < other;
    }

    /**
     * <= operator functions
     */
    bool Fraction::operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool Fraction::operator<=(float number) const {
        Fraction numberFraction(number);
        return *this <= numberFraction;
    }

    bool operator<=(float number, const Fraction &other) {
        Fraction numberFraction(number);
        std::cout << number << std::endl;
        return numberFraction <= other;
    }

    /**
     * > operator functions
     */
    bool Fraction::operator>(const Fraction &other) const {
        return !(*this < other) && !(*this == other);
    }

    bool Fraction::operator>(float number) const {
        Fraction numberFraction(number);
        return *this > numberFraction;
    }

    bool operator>(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction > other;
    }

    /**
     * >= operator functions
     */
    bool Fraction::operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    bool Fraction::operator>=(float number) const {
        Fraction numberFraction(number);
        return *this >= numberFraction;
    }

    bool operator>=(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction >= other;
    }

    /**
     * + operator functions
     */
    Fraction Fraction::operator+(const Fraction &other) const {
        long nume1 = static_cast<long>(numerator) * other.denominator;
        long nume2 = static_cast<long>(other.numerator) * denominator;
        long deno = static_cast<long>(denominator) * other.denominator;

        long nume = nume1 + nume2;

        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
            deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("add overflows");
        }
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Fraction result(resultNumerator, resultDenominator);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator+(float number) const {
        Fraction numberFraction(number);
        return *this + numberFraction;
    }

    Fraction operator+(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction + other;
    }

    /**
     * += operator functions
     */
    Fraction &Fraction::operator+=(const Fraction &other) {
        *this = *this + other;
        return *this;
    }

    Fraction &Fraction::operator+=(float number) {
        Fraction numberFraction(number);
        return *this += numberFraction;
    }

    /**
     * - operator functions
     */
    Fraction Fraction::operator-(const Fraction &other) const {
        return fractionMinus(other);
    }

    Fraction Fraction::fractionMinus(const Fraction &other) const {
        if (this == &other) {
            return {0, 1};
        }
        long nume1 = static_cast<long>(numerator) * other.denominator;
        long nume2 = static_cast<long>(other.numerator) * denominator;
        long deno = static_cast<long>(denominator) * other.denominator;

        long nume = nume1 - nume2;

        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
            deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("add overflows");
        }
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Fraction result(resultNumerator, resultDenominator);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator-(float number) const {
        Fraction numberFraction(number);
        return *this - numberFraction;
    }

    Fraction operator-(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction - other;
    }

    /**
     * -= operator functions
     */
    Fraction &Fraction::operator-=(const Fraction &other) {
        *this = *this - other;
        return *this;
    }

    Fraction &Fraction::operator-=(float number) {
        Fraction numberFraction(number);
        return *this -= numberFraction;
    }

    /**
     * * operator functions
     */
    Fraction Fraction::operator*(const Fraction &other) const {
        Fraction a(*this);
        Fraction b(other);
        a.reduce();
        b.reduce();
        long nume1 = static_cast<long>(a.numerator) * b.numerator;
        long deno1 = static_cast<long>(a.denominator) * b.denominator;

        if (nume1 > std::numeric_limits<int>::max() || nume1 < std::numeric_limits<int>::min() ||
            deno1 > std::numeric_limits<int>::max() || deno1 < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflows");
        }

        int resultNumerator = static_cast<int>(nume1);
        int resultDenominator = static_cast<int>(deno1);
        Fraction result(resultNumerator, resultDenominator);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator*(float number) const {
        Fraction numberFraction(number);
        return *this * numberFraction;
    }

    Fraction operator*(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction * other;
    }


    /**
     * *= operator functions
     */
    Fraction &Fraction::operator*=(const Fraction &other) {
        *this = *this * other;
        return *this;
    }

    Fraction &Fraction::operator*=(float number) {
        Fraction numberFraction(number);
        return *this *= numberFraction;
    }

    /**
     * / operator functions
     */
    Fraction Fraction::operator/(const Fraction &other) const {
        return fractionDiv(other);
    }

    Fraction Fraction::fractionDiv(const Fraction &other) const {
        if (other.numerator == 0) {
            throw std::runtime_error("division by 0");
        }
        Fraction a(*this);
        Fraction b(other);
        a.reduce();
        b.reduce();
        long nume1 = static_cast<long>(a.numerator) * b.denominator;
        long deno1 = static_cast<long>(a.denominator) * b.numerator;

        if (nume1 > std::numeric_limits<int>::max() || nume1 < std::numeric_limits<int>::min() ||
            deno1 > std::numeric_limits<int>::max() || deno1 < std::numeric_limits<int>::min()) {
            throw std::overflow_error("division overflows");
        }

        int resultNumerator = static_cast<int>(nume1);
        int resultDenominator = static_cast<int>(deno1);
        Fraction result(resultNumerator, resultDenominator);
        result.reduce();

        return result;
    }

    Fraction Fraction::operator/(float number) const {
        Fraction numberFraction(number);
        return *this / numberFraction;
    }

    Fraction operator/(const float number, const Fraction &other) {
        Fraction numberFraction(number);
        return numberFraction / other;
    }

    Fraction Fraction::operator/(const Fraction &other) {
        return fractionDiv(other);
    }

    /**
     * /= operator functions
     */
    Fraction &Fraction::operator/=(const Fraction &other) {
        *this = *this / other;
        return *this;
    }

    Fraction &Fraction::operator/=(const float number) {
        Fraction numberFraction(number);
        return *this /= numberFraction;
    }

    /**
     * ++fraction
     */
    Fraction &Fraction::operator++() {
        Fraction one(1, 1);
        return *this += one;
    }

    /**
     * fraction++
     */
    const Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        numerator += denominator;
        return copy;
    }

    /**
     * --fraction
     */
    Fraction &Fraction::operator--() {
        Fraction one(1, 1);
        return *this -= one;
    }

    /**
     * fraction--
     */
    const Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        numerator -= denominator;
        return copy;
    }

    /**
     * print the fraction to the terminal as x/y
     * @param ostream
     * @param fraction to print
     * @return the ostream
     */
    std::ostream &operator<<(std::ostream &ostream, const Fraction &fraction) {
        Fraction temp(fraction);
        if (temp.denominator < 0) {
            temp.numerator = -temp.numerator;
            temp.denominator = std::abs(temp.denominator);
        }
        temp.reduce();
        return ostream << temp.numerator << "/" << temp.denominator;
    }

    /**
     * overload the >> operator
     * checks if the input includes / if it does take both numbers and set them as numerator and denominator
     * if there is no / use the float ctor
     * @param istream
     * @param other the fraction that will hold the input value
     * @return the istream
     */
    std::istream &operator>>(std::istream &istream, Fraction &other) {
        int numerator;
        int denominator;
        istream >> numerator;

        if (istream.peek() == ' ') {
            istream.ignore();
            istream >> denominator;
        } else {
            throw std::runtime_error("bad input");
        }

        if (numerator < 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        } else if (denominator == 0) {
            throw std::runtime_error("division by 0");
        }

        other = Fraction(numerator, denominator);

        return istream;
    }


    /**
     * calculate the GCD of a fraction
     * @param num numerator
     * @param den denominator
     * @return the GCD result
     */
    int Fraction::GCD(int num, int den) {
        while (den != 0) {
            int temp = den;
            den = num % den;
            num = temp;
        }
        return num;
    }

    /**
     * change a fraction to the reduced form
     */
    void Fraction::reduce() {
        if (numerator == 0) {
            denominator = 1;
            gcdVal = 1;
            return;
        }
        int gcd = GCD(abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
        gcdVal = gcd;
        if (numerator < 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int Fraction::getNumerator() const {
        return numerator;
    }

    int Fraction::getDenominator() const {
        return denominator;
    }
}
