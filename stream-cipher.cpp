// This is a Menu-Based CPP Program, for encryption/decryption
#include <iostream>
using namespace std;

int main()
{
   int i, x; //x is going to be used for selecting option from Menu 
   char str[100];

   cout << "[*] Enter Your String:\t";
   cin >> str;

   cout << "\n [*] Do you want to Encrypt or Decrypt the string ??:\n";
   cout << "1 --> To Encrypt the string.\n";
   cout << "2 --> To Decrypt the string.\n";
   cin >> x;

   //using switch case statements
   switch(x)
   {
      //first case for encrypting a string
      case 1:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value

         cout << "\n[*] Encrypted string is: " << str << endl;
         break;

      //second case for decrypting a string
      case 2:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
         str[i] = str[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

      cout << "\n [*] Decrypted string: " << str << endl;
      break;

      default:
         cout << "\n[!] Enter 1 or 2 !!!\n";
   }
   return 0;
}