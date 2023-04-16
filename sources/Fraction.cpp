//
// Created by chen on 4/14/23.
//

#include "Fraction.hpp"

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator), lcmVal(0),
                                                         gcdVal(0) {
        if (denominator == 0) {
            throw std::runtime_error("division by 0");
        }
        setGCDAndLCM();
    }

    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->gcdVal = other.gcdVal;
        this->lcmVal = other.lcmVal;
    }

    Fraction::Fraction(float number) : gcdVal(0), lcmVal(0) {
        this->numerator = (int) number * 1000;
        this->denominator = 1000;
    }

    Fraction &Fraction::operator=(const Fraction &other) = default;

    Fraction &Fraction::operator=(float number) {
        this->numerator = (int) number * 1000;
        this->denominator = 1000;
        this->gcdVal = 0;
        this->lcmVal = 0;
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        other.numerator = 0;
        other.numerator = 1;
        return *this;
    }

    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->gcdVal = other.gcdVal;
        this->lcmVal = other.lcmVal;
    }


    Fraction::~Fraction() = default;


    // == operator functions
    bool Fraction::operator==(const Fraction &other) const {
        Fraction one(1, 1);
        Fraction thisReducedForm = other / one;
        Fraction otherReducedForm = *this / one;
        return thisReducedForm.numerator == otherReducedForm.numerator &&
               thisReducedForm.denominator == otherReducedForm.denominator;
    }

    bool Fraction::operator==(float number) const {
        Fraction fraction(number);
        return *this == fraction;
    }

    bool operator==(float number, const Fraction &other) {
        const Fraction fraction(number);
        return other == fraction;
    }

    // != operator functions
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

    // < operator functions
    bool Fraction::operator<(const Fraction &other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool Fraction::operator<(float number) const {
        Fraction numberFraction(number);
        return *this < numberFraction;
    }

    bool operator<(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other < numberFraction;
    }

    // <= operator functions
    bool Fraction::operator<=(const Fraction &other) const {
        return numerator * other.denominator <= other.numerator * denominator;
    }

    bool Fraction::operator<=(float number) const {
        Fraction numberFraction(number);
        return *this <= numberFraction;
    }

    bool operator<=(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other <= numberFraction;
    }

    // > operator functions
    bool Fraction::operator>(const Fraction &other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool Fraction::operator>(float number) const {
        Fraction numberFraction(number);
        return *this > numberFraction;
    }

    bool operator>(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other > numberFraction;
    }

    // >= operator functions
    bool Fraction::operator>=(const Fraction &other) const {
        return numerator * other.denominator >= other.numerator * denominator;
    }

    bool Fraction::operator>=(float number) const {
        Fraction numberFraction(number);
        return *this >= numberFraction;
    }

    bool operator>=(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other >= numberFraction;
    }

    // + operator functions
    Fraction Fraction::operator+(const Fraction &other) const {
        int newLCM = LCM(this->lcmVal, other.lcmVal);
        int thisNumerator =
                this->numerator * (newLCM / this->denominator) * (this->gcdVal / GCD(this->numerator, this->gcdVal));
        int otherNumerator =
                other.numerator * (newLCM / other.denominator) * (other.gcdVal / GCD(other.numerator, other.gcdVal));
        int resultNumerator = thisNumerator + otherNumerator;
        int gcdResult = GCD(resultNumerator, newLCM);
        return {resultNumerator / gcdResult, newLCM / gcdResult};
    }

    Fraction Fraction::operator+(float number) const {
        Fraction numberFraction(number);
        return *this + numberFraction;
    }

    Fraction operator+(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other + numberFraction;
    }

    // += operator functions
    Fraction &Fraction::operator+=(const Fraction &other) {
        int newLCM = LCM(this->lcmVal, other.lcmVal);
        int thisNumerator =
                this->numerator * (newLCM / this->lcmVal) * (this->gcdVal / GCD(this->numerator, this->gcdVal));
        int otherNumerator =
                other.numerator * (newLCM / other.lcmVal) * (other.gcdVal / GCD(other.numerator, other.gcdVal));
        int resultNumerator = thisNumerator + otherNumerator;
        int gcdResult = GCD(resultNumerator, newLCM);
        this->numerator = resultNumerator / gcdResult;
        this->lcmVal = newLCM / gcdResult;
        this->gcdVal = gcdResult;
        return *this;
    }

    Fraction &Fraction::operator+=(float number) {
        Fraction numberFraction(number);
        return *this += numberFraction;
    }

    // - operator functions
    Fraction Fraction::operator-(const Fraction &other) const {
        return fractionMinus(other);
    }

    Fraction Fraction::fractionMinus(const Fraction &other) const {
        if (this == &other) {
            return {0, 1};
        }
        int lcm = LCM(denominator, other.denominator);
        int thisNumerator = numerator * (lcm / denominator);
        int otherNumerator = other.numerator * (lcm / other.denominator);
        int resultNumerator = thisNumerator - otherNumerator;
        int gcdResult = GCD(resultNumerator, lcm);
        int newDenominator = 0;
        if (lcm / gcdResult == 0) newDenominator = 1;
        else newDenominator = lcm / gcdResult;
        return {resultNumerator / gcdResult, newDenominator};
    }

    Fraction Fraction::operator-(float number) const {
        Fraction numberFraction(number);
        return *this - numberFraction;
    }

    Fraction operator-(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other - numberFraction;
    }

    // -= operator functions
    Fraction &Fraction::operator-=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator-=(float number) {
        return *this;
    }

    // * operator functions
    Fraction Fraction::operator*(const Fraction &other) const {
        int resultNumerator = this->numerator * other.numerator;
        int resultDenominator = this->denominator * other.denominator;
        int gcdResult = GCD(resultNumerator, resultDenominator);
        return {resultNumerator / gcdResult, resultDenominator / gcdResult};
    }

    Fraction Fraction::operator*(float number) const {
        Fraction numberFraction(number);
        return *this * numberFraction;
    }

    Fraction operator*(float number, const Fraction &other) {
        Fraction numberFraction(number);
        return other * numberFraction;
    }


    // *= operator functions
    Fraction &Fraction::operator*=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator*=(float number) {
        return *this;
    }

    // / operator functions
    Fraction Fraction::operator/(const Fraction &other) const {
        return fractionDiv(other);
    }

    Fraction Fraction::fractionDiv(const Fraction &other) const {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        int gcdResult = GCD(resultNumerator, resultDenominator);
        return {resultNumerator / gcdResult, resultDenominator / gcdResult};
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

    // /= operator functions
    Fraction &Fraction::operator/=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator/=(const float number) {
        return *this;
    }

    // ++fraction
    Fraction &Fraction::operator++() {
        Fraction one(1, 1);
        return *this += one;
    }

    // fraction++
    const Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        numerator += denominator;
        return copy;
    }

    // --fraction
    Fraction &Fraction::operator--() {
        Fraction one(1, 1);
        return *this -= one;
    }

    // fraction--
    const Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        numerator -= denominator;
        return copy;
    }

    std::ostream &operator<<(std::ostream &ostream, const Fraction &fraction) {
        return ostream << fraction.numerator << "/" << fraction.denominator;
    }

    std::istream &operator>>(std::istream &istream, Fraction &other) {
        return istream;
    }

    int Fraction::LCM(int num, int den) {
        return num * (den / GCD(num, den));
    }

    int Fraction::GCD(int num, int den) {
        while (den != 0) {
            int temp = den;
            den = num % den;
            num = temp;
        }
        return num;
    }

    void Fraction::setGCDAndLCM() {
        if (gcdVal == 0 || lcmVal == 0) {
            gcdVal = GCD(numerator, denominator);
            lcmVal = LCM(numerator, denominator);
        }
    }

}
