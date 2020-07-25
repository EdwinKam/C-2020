// Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart ) 
{ 
   // empty body
} // end Complex constructor

Complex::Complex(string name)
{
	iname = name;

}

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
      imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
      imaginary - operand2.imaginary );
} // end function operator-

Complex Complex::operator*(const Complex& other) const
{
	return Complex(real*other.real-imaginary*other.imaginary,real*other.imaginary+imaginary*other.real);
}

Complex Complex::operator/(const Complex& other) const
{
	if (other.real==0&&other.imaginary==0){
		
		return Complex("infinite");	
		}
	else {
		return Complex(real * other.real + imaginary * other.imaginary,
			(imaginary * other.real - real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary));
	}
}
	


bool Complex::operator==(const Complex& other ) const
{
	if (real == other.real && imaginary == other.imaginary)
		return true;
	else return false;
}

bool Complex::operator!=(const Complex& other) const
{
	return !(*this==other);
}

// display a Complex object in the form: (a, b)
void Complex::print() const
{ 
   cout << '(' << real << ", " << imaginary << ')';
} // end function print

ostream& operator<<(ostream& stream, const Complex& other)
{
	if (other.iname == "infinite") {
		stream << "infinite";
	}
	else {
	stream << "(" << other.real << "," << other.imaginary << ")";
}
	//stream << other.print();
	return stream;
}

istream& operator>>(istream& stream, Complex& other)
{
	stream.ignore();
	stream >> other.real;
	stream.ignore();
	stream >> other.imaginary;
	return stream;
}




