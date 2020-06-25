#include<array>
#include <algorithm>
using namespace std;

class Encrypt
{
public: 
	explicit Encrypt(int input);
	void storeData(int input);
	void displayOriginalData();
	void displayEncryptedData();
private : 
	int digits[8];

};