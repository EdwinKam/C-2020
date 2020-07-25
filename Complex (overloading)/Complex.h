// Complex.h
// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;
class Complex
{
public:
   explicit Complex( double = 0.0, double = 0.0 ); // constructor
    Complex(string name); // constructor
   Complex operator+( const Complex & ) const; // addition
   Complex operator-( const Complex & ) const; // subtraction
   Complex operator*(const Complex&) const; // addition
   Complex operator/(const Complex&) const; // subtraction
  // Complex operator=(const Complex&) const; // subtraction
   bool operator==(const Complex&) const;
   bool operator!=(const Complex&) const;
   void print() const; // output
   friend ostream& operator<<(ostream&, const Complex&);
   friend istream& operator>>(istream&,  Complex&);
private:
   double real; // real part
   double imaginary; // imaginary part
   string iname="";
}; // end class Complex

#endif
