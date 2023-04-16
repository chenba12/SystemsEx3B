//
// Created by chen on 4/14/23.
//

#include "Fraction.hpp"

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    Fraction::Fraction(const Fraction &fraction) {
        this->numerator = 0;
        this->denominator = 0;
    }

    Fraction::Fraction(float scalar) {
        this->numerator = 0;
        this->denominator = 0;
    }

    Fraction &Fraction::operator=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator=(float scalar) {
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        return *this;
    }

    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }


    Fraction::~Fraction() = default;


// == operator functions
    bool Fraction::operator==(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator==(float scalar) const {
        return false;
    }

    bool operator==(float scalar, const Fraction &other) {
        return false;
    }

// != operator functions
    bool Fraction::operator!=(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator!=(float scalar) const {
        return false;
    }

    bool operator!=(float scalar, const Fraction &other) {
        return false;
    }

// < operator functions
    bool Fraction::operator<(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator<(float scalar) const {
        return false;
    }

    bool operator<(float scalar, const Fraction &other) {
        return false;
    }

// <= operator functions
    bool Fraction::operator<=(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator<=(float scalar) const {
        return false;
    }

    bool operator<=(float scalar, const Fraction &other) {
        return false;
    }

// > operator functions
    bool Fraction::operator>(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator>(float scalar) const {
        return false;
    }

    bool operator>(float scalar, const Fraction &other) {
        return false;
    }

// >= operator functions
    bool Fraction::operator>=(const Fraction &other) const {
        return false;
    }

    bool Fraction::operator>=(float scalar) const {
        return false;
    }

    bool operator>=(float scalar, const Fraction &other) {
        return false;
    }

// + operator functions
    Fraction Fraction::operator+(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator+(float scalar) const {
        return {0, 0};
    }

    Fraction operator+(float scalar, const Fraction &other) {
        return {0, 0};
    }

// += operator functions
    Fraction &Fraction::operator+=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator+=(float scalar) {
        return *this;
    }

// - operator functions
    Fraction Fraction::operator-(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator-(float scalar) const {
        return {0, 0};
    }

    Fraction operator-(float scalar, const Fraction &fraction) {
        return {0, 0};
    }

    Fraction Fraction::operator-(const Fraction &other) {
        return {0, 0};
    }

// -= operator functions
    Fraction &Fraction::operator-=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator-=(float scalar) {
        return *this;
    }

// * operator functions
    Fraction Fraction::operator*(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator*(float scalar) const {
        return {0, 0};
    }

    Fraction operator*(double scalar, const Fraction &other) {
        return {0, 0};
    }


// *= operator functions
    Fraction &Fraction::operator*=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator*=(float scalar) {
        return *this;
    }

// / operator functions
    Fraction Fraction::operator/(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator/(float scalar) const {
        return {0, 0};
    }

    Fraction operator/(double scalar, const Fraction &other) {
        return {0, 0};
    }

    Fraction Fraction::operator/(const Fraction &other) {
        return {0, 0};
    }

// /= operator functions
    Fraction &Fraction::operator/=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator/=(const float scalar) {
        return *this;
    }

// ++fraction
    Fraction &Fraction::operator++() {
        return *this;
    }

// fraction++
    const Fraction Fraction::operator++(int) {
        Fraction f(0, 0);
        return f;
    }

    // --fraction
    Fraction &Fraction::operator--() {
        return *this;
    }

    // fraction--
    const Fraction Fraction::operator--(int) {
        return {0, 0};
    }

    std::ostream &operator<<(std::ostream &ostream, const Fraction &fraction) {
        return ostream;
    }

    std::istream &operator>>(std::istream &istream, Fraction &other) {
        return istream;
    }

}
