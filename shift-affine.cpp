// Beatrix House
// East Stroudsburg Univerity
// CPSC 370 - Introduction to Cryptology
// September 27, 2020
// Programming Assignment 1 - Shift & Affine Cipher

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//shift cipher
string shift_encrypt(string, int);
string shift_decrypt(string, int);
void shift_brute_force(string, string);

//affine cipher
string affine_encrypt(string, int, int);
int affineInverse(int input);
string affine_decrypt(string, int, int);
void affine_decrypt_beta(string input, int alpha);
void affineDecryptShiftless(string message, int a);

int main()
{
    string plaintext = "attack";
    string ciphertext = " ";
    int key = 10;

    // Run shift cipher encryption
    ciphertext = shift_encrypt(ciphertext, key);
    cout << "1. Encryption of the plaintext: " << plaintext << endl;
    cout << " Key: " << key << endl;
    cout << " Ciphertext; " << ciphertext << endl;
    cout << endl;

    // Run shift cipher decryption
    ciphertext = "KDDKMU";
    plaintext = shift_decrypt(ciphertext, key);
    cout << "2. Decryption of the ciphertext: " << plaintext << endl;
    shift_brute_force(plaintext, ciphertext);
    cout << endl;

    // Run brute force shift cipher decryption
    ciphertext = "YCVEJQWVHQTDTWVWU";
    cout << "3. Brute force decrypt with shift cipher" << endl;
    cout << "Decryption of the ciphertext: " << ciphertext << endl;
    shift_brute_force(plaintext, ciphertext);
    cout << endl;

    // Run affine cipher 7x + 8 encryption
    plaintext = "cleopatra";
    ciphertext = affine_encrypt(plaintext, 7, 8);
    cout << "4. Encryption of the plaintext: " << plaintext << endl;
    cout << " Key: 7x + 8" << endl;
    cout << "Ciphertext: " << ciphertext;
    cout << endl;

    // Run affine cipher 5x + 12 encryption
    ciphertext = "MZDVEZC";
    plaintext = affine_decrypt(ciphertext, 5, 12);
    cout << "5. Decryption of the ciphertext: " << ciphertext << endl;
    cout << " Key 5x + 12" << endl;
    cout << " Inverse of 5 is " << affineInverse(5) << endl;
    cout << " Plaintext: " << plaintext << endl;
    cout << endl;

    // Run affine cipher 3x + b decryption
    ciphertext = "TCABTIQMFHEQQMRMVMTMAQ";
    cout << "6. Decryption of the ciphertext: " << ciphertext << endl;
    cout << " Key: 3x + b" << endl;
    affine_decrypt_beta("TCABTIQMFHEQQMRMVMTMAQ", 3);
    cout << endl;

    return 0;
}