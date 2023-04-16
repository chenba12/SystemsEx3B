//
// Created by chen on 4/14/23.
//

#ifndef SYSTEMSEX3A_FRACTION_H
#define SYSTEMSEX3A_FRACTION_H

#include <ostream>
#include "iostream"

namespace ariel {
    class Fraction {
    private:
        int numerator;
        int denominator;
        int gcdVal;
        int lcmVal;
    public:
        Fraction(int numerator, int denominator);

        Fraction(const Fraction &other);

        Fraction &operator=(const Fraction &other);

        Fraction &operator=(float number);

        explicit Fraction(float number);

        Fraction &operator=(Fraction &&other) noexcept;

        Fraction(Fraction &&other) noexcept;

        ~Fraction();

        // fraction vs fraction comparison operators

        // == operator functions
        bool operator==(const Fraction &other) const;

        bool operator==(float number) const;

        friend bool operator==(float scalar, const Fraction &other);

        // != operator functions
        bool operator!=(const Fraction &other) const;

        bool operator!=(float number) const;

        friend bool operator!=(float scalar, const Fraction &other);

        // < operator functions
        bool operator<(const Fraction &other) const;

        bool operator<(float number) const;

        friend bool operator<(float scalar, const Fraction &other);


        // <= operator functions
        bool operator<=(const Fraction &other) const;

        bool operator<=(float number) const;

        friend bool operator<=(float scalar, const Fraction &other);

        // > operator functions
        bool operator>(const Fraction &other) const;

        bool operator>(float number) const;

        friend bool operator>(float scalar, const Fraction &other);

        // >= operator functions
        bool operator>=(const Fraction &other) const;

        bool operator>=(float number) const;

        friend bool operator>=(float scalar, const Fraction &other);

        // + operator functions
        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float number) const;

        friend Fraction operator+(float scalar, const Fraction &other);

        // += operator functions
        Fraction &operator+=(const Fraction &other);

        Fraction &operator+=(float number);

        // - operator functions
        Fraction operator-(const Fraction &other) const;

        Fraction operator-(float number) const;

        friend Fraction operator-(float scalar, const Fraction &other);

        // -= operator functions
        Fraction &operator-=(const Fraction &other);

        Fraction &operator-=(float number);

        // * operator functions
        Fraction operator*(const Fraction &other) const;

        Fraction operator*(float number) const;

        friend Fraction operator*(float scalar, const Fraction &other);

        // *= operator functions
        Fraction &operator*=(const Fraction &other);

        Fraction &operator*=(float number);

        // / operator functions
        Fraction operator/(const Fraction &other) const;

        Fraction operator/(float number) const;

        friend Fraction operator/(float scalar, const Fraction &other);


        Fraction operator/(const Fraction &other);

        // /= operator functions
        Fraction &operator/=(const Fraction &other);

        Fraction &operator/=(float number);

        // ++fraction
        Fraction &operator++();

        // fraction++
        const Fraction operator++(int);

        // --fraction
        Fraction &operator--();

        // fraction--
        const Fraction operator--(int);


        // overload << output function
        friend std::ostream &operator<<(std::ostream &ostream, const Fraction &other);

        // overload >> input function
        friend std::istream &operator>>(std::istream &istream, Fraction &other);

    private:
        static int LCM(int num, int den);

        static int GCD(int num, int den);

        void setGCDAndLCM();

        Fraction fractionMinus(const Fraction &other) const;

        Fraction fractionDiv(const Fraction &other) const;
    };
}

#endif //SYSTEMSEX3A_FRACTION_H
