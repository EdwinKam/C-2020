#include<array>
#include <algorithm>
using namespace std;

class Encrypt
{
public: 
	explicit Encrypt(int input);
	explicit Encrypt(int*);
	void storeData(int input);
	void displayOriginalData();
	void displayEncryptedData();
	int getEncryptedData();
private : 
	int digits[8];

};