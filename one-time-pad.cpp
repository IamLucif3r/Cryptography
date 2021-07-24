#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
// We will convert all the Letters to Upper case
void to_upper_case(vector<char>& text, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 97 && text[i] <= 122)
            text[i] -= 32;
    }
}
// A function to print the processed string
void print_string(vector<char> text, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << (char) (text[i] + 65);
    }
    cout << endl;
    return;
}
size_t get_input(vector<char>& msg)
{
    char a;
    while (1)
    {
        a = getchar();
        if (a == '\n')
            break;
        msg.push_back(a);
    }
    return msg.size();
}
int main()
{
    vector<char> msg;
    vector<char> enc_msg;
    vector<char> dec_msg;
    int *p;
    int i;
    size_t len;
    cout << "[*] Enter Text to be Encrypted:";
    len = get_input(msg);
    to_upper_case(msg, len);
    p = (int*) malloc(msg.size() * sizeof(int));
    for (i = 0; i < len; i++)
    {
        p[i] = rand() % 26;
        if (msg[i] >= 65 && msg[i] <= 90)
            enc_msg.push_back((char) ((msg[i] - 65 + p[i]) % 26));
        else if (msg[i] >= 97 && msg[i] <= 122)
            enc_msg.push_back((char) ((msg[i] - 97 + p[i]) % 26));
        else
            enc_msg.push_back((char) msg[i]);
    }
    cout << "\n[-] Encrypted Message:";
    print_string(enc_msg, len);
    cout << "\n [-] The Key for Decryption:\n";
    for (i = 0; i < len; i++)
    {
        cout << (char) (p[i] + 65);
    }
    cout << endl;
    cout << "\n [*] The Decrypted Message:";
    for (i = 0; i < len; i++)
    {
        if ((enc_msg[i] - p[i]) < 0)
            dec_msg.push_back((char) (enc_msg[i] - p[i] + 26));
        else if ((enc_msg[i] - p[i]) >= 0)
            dec_msg.push_back((char) (enc_msg[i] - p[i]));
        else
            dec_msg.push_back((char) enc_msg[i]);
    }
    print_string(dec_msg, len);
    return 0;
}
