#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <iostream>

int gcd(int a, int b);
int lcm(int a, int b);

struct Rational
{
    int p{ 0 };
    int q{ 1 };

    static const char separator{ '/' };

    Rational() {}
    ~Rational() = default;
    Rational& operator=(const Rational& rhs) = default;
    explicit Rational(const double chel)
        : p(chel)
        , q(1)
    {};
    Rational(const int chel, const int drob) {
        if (drob > 0) {
            int del = gcd(chel, drob);
            p = chel / del; q = drob / del;
        }
    }

    bool operator==(const Rational& a);
    bool operator!=(const Rational& a);

    bool operator<(const Rational& a);
    bool operator>(const Rational& a);

    Rational& operator+=(const Rational a);
    Rational& operator-=(const Rational a);
    Rational& operator*=(const Rational a);
    Rational& operator/=(const Rational a);

    Rational& operator+=(const int num);
    Rational& operator-=(const int num);
    Rational& operator*=(const int num);
    Rational& operator/=(const int num);

};
#endif
