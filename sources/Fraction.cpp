//
// Created by chen on 4/14/23.
//

#include "Fraction.hpp"

namespace ariel {

    /**
     * empty constructor
     */
    Fraction::Fraction() : numerator(0), denominator(1), gcdVal(0), lcmVal(0) {

    }

    /**
     * basic constructor that get 2 ints
     * @param numerator
     * @param denominator
     */
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator), lcmVal(0),
                                                         gcdVal(0) {
        if (denominator == 0) {
            throw std::logic_error("division by 0");
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
        this->lcmVal = other.lcmVal;
    }

    /**
     * float constructor
     * @param number
     */
    Fraction::Fraction(float number) : gcdVal(0), lcmVal(0) {
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
        this->numerator = (int) number * 1000;
        this->denominator = 1000;
        this->gcdVal = 0;
        this->lcmVal = 0;
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
        this->lcmVal = other.lcmVal;
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
        return !(*this < other) && !(other < *this);
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
        return this->numerator * other.denominator < other.numerator * this->denominator;
    }

    bool Fraction::operator<(float number) const {
        Fraction numberFraction(number);
        return *this < numberFraction;
    }

    bool operator<(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other < numberFraction;
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
        return other <= numberFraction;
    }

    /**
     * > operator functions
     */
    bool Fraction::operator>(const Fraction &other) const {
        return !(*this < other);
    }

    bool Fraction::operator>(float number) const {
        Fraction numberFraction(number);
        return *this > numberFraction;
    }

    bool operator>(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other > numberFraction;
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
        return other >= numberFraction;
    }

    /**
     * + operator functions
     */
    Fraction Fraction::operator+(const Fraction &other) const {
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
        return other + numberFraction;
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
        return other - numberFraction;
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
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
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
        return other * numberFraction;
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
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
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
        return other / numberFraction;
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
        return ostream << fraction.numerator << "/" << fraction.denominator;
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
        std::string input;
        istream >> input;
        size_t position = input.find('/');
        if (position == std::string::npos) {
            try {
                float value = std::stof(input);
                other = Fraction(value);
                return istream;
            } catch (std::invalid_argument &) {
                std::cout << "error parsing string" << std::endl;
            }
        }
        try {
            int numerator = std::stoi(input.substr(0, position));
            int denominator = std::stoi(input.substr(position + 1));
            if (numerator < 0 && denominator < 0) {
                numerator = abs(numerator);
                denominator = abs(denominator);
            }
            other = Fraction(numerator, denominator);
        }
        catch (std::invalid_argument &) {
            std::cout << "error parsing string" << std::endl;
        }
        return istream;
    }

    /**
     * calculate the LCM of a fraction
     * @param num numerator
     * @param den denominator
     * @return the LCM result
     */
    int Fraction::LCM(int num, int den) {
        return num * (den / GCD(num, den));
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
            lcmVal = 0;
            return;
        }
        int gcd = GCD(abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
        gcdVal = gcd;
        lcmVal = LCM(abs(numerator), denominator);
        if (numerator < 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}
