#include "Complex.h"

Complex::Complex(int rl, int im):real(rl),imaginary(im)
{
}

bool Complex::operator==(const Complex& other)
{
	return (this->real==other.real && this->imaginary==other.imaginary);
}

ostream& operator<<(ostream& stream, const Complex& other)
{
	stream << other.real;
	if (other.imaginary < 0) {
		stream << " - ";
	}
	else {
		stream << " + ";

	}
	stream << other.imaginary;
	stream << "i";
	return stream;

}
