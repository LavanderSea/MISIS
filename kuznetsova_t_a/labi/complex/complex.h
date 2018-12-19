#ifndef HG_COMPLEX_H_20160926
#define HG_COMPLEX_H_20160926


struct Complex 
{
    Complex() = default;
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
	~Complex() = default;

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-= (const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const double rhs);

    std::istream &readFrom(std::istream& istrm);

    std::ostream &writeTo(std::ostream &os) const override;

    double re{ 0.0 };
    double im{ 0.0 };
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

std::istream& operator >> (std::istream& istrm, Complex& rhs);

#endif // HG_COMPLEX_H_20160926