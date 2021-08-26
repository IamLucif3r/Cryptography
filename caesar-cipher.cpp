    #include<bits/stdc++.h>
    using namespace std;
   
    int main() {    
    cout<<"[*] ENTER PLAIN TEXT:\n";
    char msg[100];
    cin.getline(msg,100); //take the message as input
    int i, j, length,choice,key;
    cout << "[*] ENTER KEY: \t";
    cin >> key; //take the key as input
    length = strlen(msg);
    cout<<"[*] SELECT YOUR OPTION \n 1. ENCRYPTION \n 2. DECRYPTION \n";
     cin>>choice;
    if (choice==1) //for encryption
    {
        char ch;
        for(int i = 0; msg[i] != '\0'; ++i) {
            ch = msg[i];
            //encrypt for lowercase letter
            if (ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
                }  
                msg[i] = ch;
            }
            //encrypt for uppercase letter
            else if (ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
                if (ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
                }
                msg[i] = ch;
            }
        }
        printf("[*] ENCRYPTED MESSAGE: %s", msg);
        cout<<endl;
    }
    else if (choice == 2) { //for decryption
        char ch;
        for(int i = 0; msg[i] != '\0'; ++i) {
            ch = msg[i];
            //decrypt for lowercase letter
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
                }
                msg[i] = ch;
            }
            //decrypt for uppercase letter
            else if(ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
                }
                msg[i] = ch;
            }
        }
        cout << "[*] DECRYPTED MESSAGE : " << msg<<endl;
    }
    }