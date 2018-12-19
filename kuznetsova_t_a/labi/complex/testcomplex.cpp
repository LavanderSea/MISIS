#include <sstream>
#include <iostream>
#include "complex.h"

using namespace std;

bool testParse(const std::string& str);
void runArufmeticsTests(Complex a, Complex b);
void runParseTest();


int main()
{
    runArufmeticsTests({ 6,3 }, { 9, 1 });

    cout << endl;

    runParseTest();

    return 0;
}

void runParseTest()
{
    cout << endl << "Parse tests: " << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
}

bool testParse(const std::string& str)
{
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}
void runArufmeticsTests(Complex a, Complex b)
{
    cout << "Arifmetics tests: " << endl;
    Complex q(a), v(b);

    cout << "Q = " << q << "; Q += {5, 4}; Q = ";
    q += Complex{ 5, 6 };
    cout << q << endl;

    cout << v << " + " << q << " = " << (v + q) << endl;
    cout << v << " - " << q << " = " << (v - q) << endl;
    cout << v << " * " << q << " = " << (v * q) << endl;
	
	cout << v << " + " << 3 << " = " << (q + 3) << endl;
    cout << v << " - " << 5 << " = " << (q - 5) << endl;
    cout << v << " * " << 2 << " = " << (q * 2) << endl << endl;	
	
    cout << v << " equal to " << z << " = " << (v == q) << endl;
    cout << v << " not equal to " << z << " = " << (v != q) << endl;
            
    
}