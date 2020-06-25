#include "Encrypt.h"
#include <iostream>
#include <algorithm>
using namespace std;
Encrypt::Encrypt(int input)
{
	cout << "\n\n**The dafault constructor is called\nand the passed in number is " << input << ".**\n\n";
	storeData(input);
	displayOriginalData();
	displayEncryptedData();
}
void Encrypt::storeData(int input)
{
	if (input > 9999)
	{
		input = input % 10000; //take the last 4 digit

	}
	if (input < 1)
	{
		input = 9436;
		cout << "The inputted number is less than or equal to 0. Reset to 9436\n";
	}
	digits[0] = input/1000%10;
	digits[1] = input/100%10;
	digits[2] = input / 10 % 10;
	digits[3] = input  % 10;

	//start to Encrypt data
	digits[4] = (digits[0] + 7) % 10;
	digits[5] = (digits[1] + 7) % 10;
	digits[6] = (digits[2] + 7) % 10;
	digits[7] = (digits[3] + 7) % 10;

	swap(digits[4], digits[6]);
	swap(digits[5], digits[7]);


}
void Encrypt::Encrypt::displayOriginalData()
{
	cout << "The original Data is ";
	for (int i = 0; i < 4; i++) {
		cout << " "<<digits[i];
	}
	cout << "." << endl;
}

void Encrypt::displayEncryptedData()
{
	cout << "The Encrypt Data is ";
	for (int i = 4; i < 8; i++) {
		cout << " " << digits[i];
	}
	cout << "." << endl;
}


