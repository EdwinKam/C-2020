#include "Decrypt.h"
#include <iostream>
#include<algorithm>
using namespace std;

Decrypt::Decrypt(int input)
{
	cout << "\n\n**The dafault Decrypt constructor is called\nand the passed in number is " << input << ".**\n\n";
	storeData(input);
	displayOriginalData();
	displayDecryptedData();
}

Decrypt::Decrypt(int* arr)
{
	cout << "\n\n**The dafault Decrypt constructor is called\nand the passed in number is ";
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << ".** \n\n";
	int input;
	input = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	storeData(input);
	displayOriginalData();
	displayDecryptedData();

}

void Decrypt::storeData(int input)
{
	if (input < 1)
	{
		input = 1234;
		cout << "The inputted number is less than or equal to 0. Reset to 1234\n";
	}
	if (input>9999)
	{
		input=input % 10000;
	}

	digits[0] = input / 1000 % 10;
	digits[1] = input / 100 % 10;
	digits[2] = input / 10 % 10;
	digits[3] = input  % 10;
	digits[4] = (digits[0]+3) % 10;
	digits[5] = (digits[1] + 3) % 10;
	digits[6] = (digits[2] + 3) % 10;
	digits[7] = (digits[3] + 3) % 10;
	swap(digits[4], digits[6]);
	swap(digits[5], digits[7]);

}	
void Decrypt::displayOriginalData()
{
	cout << "The original Data is ";
	for (int i = 0; i < 4; i++) {
		cout << " " << digits[i];
	}
	cout << "." << endl;
}

void Decrypt::displayDecryptedData()
{
	cout << "The Decrypt Data is ";
	for (int i = 4; i < 8; i++) {
		cout << " " << digits[i];
	}
	cout << "." << endl;
}

int Decrypt::getDecryptedData()
{
	int result;
	result = digits[4] * 1000 + digits[5] * 100 + digits[6] * 10 + digits[7];
	return result;
}
