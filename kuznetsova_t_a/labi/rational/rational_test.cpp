#include "rational.h"
#include <sstream>
#include <iostream>

//bool testParse(const std::string& str)
//std::ostream& writeTo(std::ostream& ostr) const;
//std::istream& readFrom(std::istream& istr);

int main()
{
    using namespace std;

    Rational a;
    a += Rational(4, 6);
    Rational b(6, 10);
    a -= b;
    b *= a;
    a /= a;
    bool check;
    check = a > b;
    check = a < b;
    check = a != b;
    /*testParse("2/3");
    testParse("10/4");
    testParse("3.3/4");*/

    return 0;
}
