#include <iostream>
#include "rational.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*b / gcd(a, b);
}

//== and !=

bool Rational::operator==(const Rational& rhs) { return (p == rhs.p) && (q == rhs.q); }
bool Rational::operator!=(const Rational& rhs) { return !operator==(rhs); }

//< and >

bool Rational::operator > (const Rational& rhs) { 
    int del = lcm(q, rhs.q);
    return (p*(del/q) > rhs.p*(del/rhs.q)); 
}

bool Rational::operator < (const Rational& rhs) {
    int del = lcm(q, rhs.q);
    return (p*(del / q) < rhs.p*(del / rhs.q));
}

Rational& Rational::operator+=(const Rational rhs) {
    int del = lcm(q, rhs.q);
    p = p*(del / q) + rhs.p*(del / rhs.q);
    q = del;
    return *this;
}

Rational& Rational::operator-=(const Rational rhs) {
    int del = lcm(q, rhs.q);
    p = p*(del / q) - rhs.p*(del / rhs.q);
    q = del;
    return *this;
}

Rational& Rational::operator*=(const Rational rhs) {
    p *= rhs.p;
    q *= rhs.q;
    int del = gcd(p, q);
    p /= del; q /= del;
    return *this;
}

Rational& Rational::operator/=(const Rational rhs) {
    p *=rhs.q;
    q *= rhs.p;
    int del = gcd(p,q);
    p /= del; q /= del;
    return *this;
}

Rational& Rational::operator+=(const int rhs) {
    return Rational(p + rhs*q, q);
}

Rational& Rational::operator-=(const int rhs) {
    return Rational(p - rhs*q, q);
}

Rational& Rational::operator*=(const int rhs) {
    return Rational(p * rhs, q);
}

Rational& Rational::operator/=(const int rhs) {
    return Rational(p, q * rhs);
}
