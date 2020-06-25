#pragma once
class Decrypt
{
public: 
	explicit Decrypt(int);
	explicit Decrypt(int*);
	void storeData(int input);
	void displayOriginalData();
	void displayDecryptedData();
	int getDecryptedData();

private: 
	int digits[8];

};