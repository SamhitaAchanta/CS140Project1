#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

string generateRandomKey();
void isValid(string);

int main() {

	int choice;
	int spacing;
	string key;
	string plaintext;
	
	cout << "Testing Monoalphabetic Substitution Cipher (MASC) program:" << endl;
	cout << endl;
	cout << "Please make a selection:" << endl;
	cout << "(1) Type in a key" << endl;
	cout << "(2) Have a key generated for you" << endl;
	cout << endl;

	// asking user for their choice
	cout << "Choice: ";
	cin >> choice;
	cin.ignore();
	cout << endl;

	if (choice == 1) {
		
		cout << "Enter a key to be used for encryption and decryption. Include each letter of alphabet, none repeated:" << endl;
		getline(cin, key);
		isValid(key);
		transform(key.begin(), key.end(), key.begin(), ::toupper);
		cout << "Key is now: " << key << endl;
		cout << endl;

		cout << "Enter the plaintext: ";
		getline(cin, plaintext);
		cout << endl;

		cout << "We will now disguise the original spacing." << endl;
		cout << "How many letters should appear in each grouping? " << '\n' << "(press Enter for default spacing of 5, negative entry leaves original spacing" << endl;
		cout << "Spacing: ";
		cin >> spacing;
		cout << endl;
		// call  encryption() function here
		// call spacing() function here
		cout << "Ciphertext is: ";
	}
	else if (choice == 2) {

		cout << "Key is now: " << generateRandomKey() << endl;
		cout << endl;
		cout << "Enter the plaintext: ";
		getline(cin, plaintext);
		cout << endl;

		cout << "We will now disguise the original spacing." << endl;
		cout << "How many letters should appear in each grouping? " << '\n' << "(press Enter for default spacing of 5, negative entry leaves original spacing" << endl;
		cout << "Spacing: ";
		cin >> spacing;
		cout << endl;
		// call encryption() function here
		// call spacing() function here
		cout << "Ciphertext is: ";
	}

}

std::string generateRandomKey()
{
	std::string randomKey{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	std::random_device rnd;
	const auto seed = rnd.entropy() ? rnd() : time(nullptr);
	std::mt19937_64 eng(static_cast<std::mt19937_64::result_type>(seed));

	std::cout << "\nGenerating random key..." << std::endl;
	shuffle(randomKey.begin(), randomKey.end(), eng);

	return randomKey;
}

void isValid(string input) {

	// checking for max length
	if (input.length() > 26) {
		cout << "Incorrect key length. Must be 26 characters." << endl;
	}
	else {

		for (int i{ 0 }; i < input.length()-1; i++) {

			// checking for non-alphabetic characters 
			if (!isalpha(input.at(i))) {
				cout << "Error: invalid character in key." << endl;
				break;
			}

			// checking for same consecutive letters
			if (input.at(i) == input.at(i + 1)) {
				cout << "Error: letters in key must be used only once." << endl;
				break;
			}
		}

	}
	
}

