//============================================================================
// Name        : HenryT_Chapter10_Assignment.cpp
// Author      : Henry Timmons
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

bool checkPassword(char arrayP[], bool &passwordRight, int &lowC, int &upC, int &numC) {
	int i = 0;
	passwordRight = false;
	while (passwordRight == false) {
		cout << "Enter your password (at least 2 upper, 2 lower, 2 numbers and must be at least 8 characters long): ";
		cin.getline(arrayP, 25);

		for (i = 0; i < 25; i++) { //determines the size of the password the user entered
			if (arrayP[i] == '\0') {
				break;
			}

		} //for

		for (int j = 0; j < i; j++) {

			for (int lower = 97; lower <= 122; lower++) { //use of for loop to scan through a series of numbers, lowercase
				if (int(arrayP[j]) == lower) {
					lowC += 1;
				} //if
			} //for lower
			for (int upper = 65; upper <= 90; upper++) { //use of for loop to scan through a series of numbers, uppercase
				if (int(arrayP[j]) == upper) {
					upC += 1;
				} //if
			} //for upper
			for (int num = 48; num <= 57; num++) { //use of for loop to scan through a series of numbers, number
				if (int(arrayP[j]) == num) {
					numC += 1;
				} //if
			} //for number
		} // for j
		if (i < 8) {
			cout << "Error password must be at least 8 characters long. Please try again." << endl;
			i = 0;

		} else if (lowC < 2) {
			cout << "Error password must have at least 2 lowercase letters. Please try again." << endl;
			lowC = 0;
			upC = 0;
			numC = 0;
		} else if (upC < 2) {
			cout << "Error your password does not have 2 uppercase letters. Please try again."	<< endl;
			lowC = 0;
			upC = 0;
			numC = 0;
		} else if (numC < 2) {
			cout << "Error your password needs at least 2 numbers. Please try again." << endl;
			lowC = 0;
			upC = 0;
			numC = 0;
		}
		if (lowC >= 2 && upC >= 2 && numC >= 2 && i >= 8) {
			passwordRight = true;
		} else {

		}

	} //while
	return passwordRight;
}

int main() {
	bool passwordRight = false;
	string userPassword;
	char arrayPassword[25];
	int lowerCounter = 0;
	int upperCounter = 0;
	int numberCounter = 0;

	checkPassword(arrayPassword, passwordRight, lowerCounter, upperCounter, numberCounter);

	if(passwordRight == true){
		cout << "Your password is valid" << endl;
	}

	cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
	return 0;
}

