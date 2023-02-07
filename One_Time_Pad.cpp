// C++ program Implementing One Time Pad Algorithm

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// Method 1
// Returning encrypted text
string stringEncryption(string text, string key)
{

	// Initializing cipherText
	string cipherText = "";

	// Initialize cipher array of key length
	// which stores the sum of corresponding no.'s
	// of plainText and key.
	int cipher[key.length()];

	for (int i = 0; i < key.length(); i++) {
		cipher[i] = text.at(i) - 'A' + key.at(i) - 'A';
	}

	// If the sum is greater than 25
	// subtract 26 from it
	// and store that resulting value
	for (int i = 0; i < key.length(); i++) {

        cipher[i] = cipher[i] % 26;

	}

	// Converting the no.'s into integers

	// Convert these integers to corresponding
	// characters and add them up to cipherText
	for (int i = 0; i < key.length(); i++) {
		int x = cipher[i] + 'A' + 1;
		cipherText += (char)x;
	}

	// Returning the cipherText
	return cipherText;
}

// Method 2
// Returning plain text
static string stringDecryption(string s, string key)
{
	// Initializing plain text
	string plainText = "";

	// Initializing integer array of key length
	// which stores difference
	// of corresponding no.'s of
	// each character of cipherText and key
	int plain[key.length()];

	// Running for loop for each character
	// subtracting and storing in the array
	for (int i = 0; i < key.length(); i++) {
		plain[i] = s.at(i) - 'A' - (key.at(i) - 'A');
	}

	// If the difference is less than 0
	// add 26 and store it in the array.
	for (int i = 0; i < key.length(); i++) {
		if (plain[i] < 0) {
			plain[i] = plain[i] + 26;
		}
	}

	// Converting int to corresponding char
	// add them up to plainText
	for (int i = 0; i < key.length(); i++) {
		int x = plain[i] + 'A' - 1;
		plainText += (char)x;
	}

	// Returning plainText
	return plainText;
}

// Method 3
// Main driver method
int main()
{
	// Declaring plain text
	string plainText = "ONETIMEPAD";

	// Declaring key
	string key = "TBFRGFARFM";

	cout << "Orginal Message - " << plainText << endl;
	cout << "Key - " << key << endl;

	// Converting plain text to toUpperCase
	// function call to stringEncryption
	// with plainText and key as parameters
	for (int i = 0; i < plainText.length(); i++) {
		// convert plaintext to uppercase
		plainText[i] = toupper(plainText[i]);
	}
	for (int i = 0; i < key.length(); i++) {
		// convert key to uppercase
		key[i] = toupper(key[i]);
	}
	string encryptedText = stringEncryption(plainText, key);

	// Printing cipher Text
	cout << "Cipher Text - " << encryptedText << endl;

	// Calling above method to stringDecryption
	// with encryptedText and key as parameters

	cout << "Message - "
		<< stringDecryption(encryptedText, key);

	return 0;
}

// This code was contributed by Pranay Arora
