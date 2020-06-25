// CISP400V9Ad2.cpp
// Test program for class Encrypt and Decrypt.

#include "Encrypt.h" // include definition of class Encrypt
#include "Decrypt.h" // include definition of class Decrypt
#include <iostream>
#include <cstdlib>
#include "CISP400V10AD2.h"
using std::cin;
using std::cout;
using std::endl;
using std::atoi;


int main()
{  int Long[]={1,2,3,4,5,6,7,8};
int Negative[]={-8,7,6,5,4,3,2,1};
   Encrypt eapp1(0), eapp2(40), eapp3(4560), eapp4(6145698),eapp5(-6), eapp6(Long), eapp7(Negative); // create Encrypt objects  
   Decrypt dapp1(0), dapp2(40), dapp3(4560), dapp4(6145698), dapp5(-6), dapp6(Long), dapp7(Negative); // create Decrypt objects  
  
   cout<<endl<< "Reset the eapp1's data to 100." << endl<<endl;// display the reset title for eapp1.
   eapp1.storeData(100);// call eapp1's storeData function
   eapp1.displayOriginalData();//display the eapp1's original data.
   eapp1.displayEncryptedData();// display the eapp1's encrypted data.

   cout<<endl<< "Reset the dapp1's data to 200." << endl;// display the reset of aapp1.
   dapp1.storeData(200);// call dapp1's storeData function
   dapp1.displayOriginalData();//display the dapp1's original data.
   dapp1.displayDecryptedData();// display the dapp1's encrypted data.


   cout<<endl<< "\n$$$$Use eapp3 and dapp3 to test the program.$$$$"<<endl<<endl;// display a heading for testing program
   cout<< "  Call eapp3 to display its data." << endl<<endl;// display the call to eapp3.
   eapp3.displayOriginalData();//display the eapp3's original data.
   eapp3.displayEncryptedData();// display the eapp3's encrypted data.

   cout<<endl<< "  Get encrypted data from eapp3 and" <<endl<<"  use the data on the dapp3 to test program." << endl<<endl;// display the reset of aapp1.
   dapp3.storeData(eapp3.getEncryptedData());// call dapp6's storeData function
   dapp3.displayOriginalData();//display the dapp3's original data.
   dapp3.displayDecryptedData();// display the dapp3's encrypted data.

   cout<<endl<< "\n$$$$Use eapp6 and dapp6 to test the program.$$$$"<<endl<<endl;// display a heading for testing program
   cout<< "  Call dapp6 to display its data." << endl;// display the call to dapp6
   dapp6.displayOriginalData();//display the dapp6's original data.
   dapp6.displayDecryptedData();// display the dapp6's encrypted data.

   cout<<endl<< "  Get decrypted data from dapp6 and"<< endl<<"  use the data on the eapp6 to test program." << endl<<endl;// display the reset of aapp1.
   eapp6.storeData(dapp6.getDecryptedData());// call eapp6's storeData function
   eapp6.displayOriginalData();//display the eapp6's original data.
   eapp6.displayEncryptedData();// display the eapp6's encrypted data.


   system("PAUSE");
   return 0; // indicate successful termination
} // end main