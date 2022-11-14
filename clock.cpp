/*
 * 
 * Digital Clock Interface
 * CS 210
 * Nolan Pratt
 * 11/11/2022
 * 
 * This program continuously updates a digital clock with a 1 second 
 * refresh timer that can be incremented by the hour, minute, and second.
 * The clock runs discretly on the user's machine, so the time 
 * setting must be manually set upon first use to ensure accuracy.
 * 
 */

// Enables system input and output
#include <iostream>
// Utilizes string manipulation
#include <string>
// Utilizes tuple manipulation
#include <tuple>
// Utilizes Windows sleep function
#include <windows.h>
// Utilizes Windows keystroke recognition
#include <conio.h>

using namespace std;

// Converts inputted integer to string with leading 0's
string numToString(int num) {
	// Return integers of length 2 as strings
	if (to_string(num).size() != 1) {
		return to_string(num);
	}
	// Generate leading zeros for single digit strings
	else {
		return '0' + to_string(num);
	}
}

// Generates a string from the inputted char of size n
string nCharString(string c, size_t n) {
	string new_string = "";
	for (size_t i = 0; i < n; i++) {
		new_string += c;
	}
	return new_string;
}

// Generate 12-hour time
string time12Hours(int hour, int min, int sec) {
	string time = numToString(hour) + ':' + numToString(min) + ':' + numToString(sec);
	return time;
}

// Generate 24-hour time
string time24Hours(int hour, int min, int sec) {
	string time = numToString(hour) + ':' + numToString(min) + ':' + numToString(sec);
	return time;
}

// Increments respective time values in 12 hour clock time
tuple<int,int,int> increment12Hours(int hour, int min, int sec) {
	// Increment second
	if (sec != 60) {
		sec += 1;
	}
	// Increment minute
	else if (sec == 60) {
		min += 1;
		sec = 0;
	}
	// Increment hour
	if (min == 60) {
		hour += 1;
		min = 0;
	}
	// Check for 12 hour mark
	if (hour == 13) {
		hour = 1;
	}
	// Return tuple of size 3 that contains the updated hour, minute, and second values
	return make_tuple(hour, min, sec);
}

// Increments respective time values in 24 hour clock time
tuple<int, int, int> increment24Hours(int hour, int min, int sec) {
	// Increment second
	if (sec != 60) {
		sec += 1;
	}
	// Increment minute
	else if (sec == 60) {
		min += 1;
		sec = 0;
	}
	// Increment hour
	if (min == 60) {
		hour += 1;
		min = 0;
	}
	// Check for 24 hour mark
	if (hour == 24) {
		hour = 0;
	}
	// Return tuple of size 3 that contains the updated hour, minute, and second values
	return make_tuple(hour, min, sec);
}

// Displays the digital clock faces
void clockDisplay(string time12, string time24, string timeOfDay) {
	// Four sides of the clock face represented as the respective strings
	string divider = nCharString("*", 26);
	string l_Panel = "*" + nCharString(" ", 5);
	string r_Panel = nCharString(" ", 6) + "*";
	string center = nCharString(" ", 4);
	string colon = ":";

	// Printing out the clock faces
	cout << divider << center << divider << endl;
	cout << l_Panel << "12-Hour Clock" << r_Panel << center << l_Panel << "24-Hour Clock" << r_Panel << endl;
	cout << l_Panel << time12 << timeOfDay << r_Panel << center << l_Panel << "  " << time24 << "   " << r_Panel << endl;
	cout << divider << center << divider << endl;
}

// Determines whether 12 hour clock reads AM or PM
string checkTimeOfDay(int hour12, int hour24) {
	string timeOfDay;

	if ((hour24 - hour12) <= 0 && hour12 != 12 || hour24 == 0) {
		timeOfDay = " A M ";
	}
	else if ((hour24 - hour12) > 0) {
		timeOfDay = " P M ";
	}
	else {
		timeOfDay = " P M ";
	}
	return timeOfDay;
}

// Displays the user menu for incrementing time and exiting the program
void menuDisplay() {
	// Four sides of the clock face represented as the respective strings
	string divider = nCharString("*", 26);
	string l_Panel = "*" + nCharString(" ", 5);
	string r_Panel = nCharString(" ", 6) + "*";
	string center = nCharString(" ", 15);

	// Printing out the menu
	cout << center << divider << endl;
	cout << center << "* 1 - Add One Hour " << r_Panel << endl;
	cout << center << "* 2 - Add One Minute " << r_Panel.substr(2, r_Panel.size()) << endl;
	cout << center << "* 3 - Add One Second " << r_Panel.substr(2, r_Panel.size()) << endl;
	cout << center << "* 4 - Exit Program " << r_Panel << endl;
	cout << center << divider << endl;
}

// Records and interprets menu selections
tuple<int,int,int,int,int,int> menuChoice(int hour12, int min12, int sec12, int hour24, int min24, int sec24) {
	// Read in user selection
	char choice;
	menuDisplay();
	cin >> choice;

	// Increment hour
	if (choice == '1') {
		hour12 += 1;
		hour24 += 1;
	}
	// Increment minute
	if (choice == '2') {
		min12 += 1;
		min24 += 1;
	}
	// Increment second
	if (choice == '3') {
		sec12 += 1;
		sec24 += 1;
	}
	// Exit program
	if (choice == '4') {
		cout << "Exiting the program";
		Sleep(2000);
		exit(0);
	}
	system("CLS");
	return make_tuple(hour12, min12, sec12, hour24, min24, sec24);
}

// Enter program driver
int main() {

	// Displayed time components
	int hour12 = 12, min12 = 00, sec12 = 00, hour24 = 00, min24 = 00, sec24 = 00;
	char input = '0';

	// Format time components for 12 hour clock
	string timeOfDay;
	string time12 = time12Hours(hour12, min12, sec12);

	// Format time components for 24 hour clock
	string time24 = time24Hours(hour24, min24, sec24);

	// Enter outer program wrapper to ensure continuous runtime
	while (true) {

		// Enter inner clock loop
		while (!_kbhit()) {

			// Display time to user
			clockDisplay(time12, time24, timeOfDay);

			// Display menu to user
			cout << "Press any key to enter into the menu.";

			// Increment respective time values
			tie(hour12, min12, sec12) = increment12Hours(hour12, min12, sec12);
			tie(hour24, min24, sec24) = increment24Hours(hour24, min24, sec24);

			// Update displayed times
			time12 = numToString(hour12) + ':' + numToString(min12) + ':' + numToString(sec12);
			time24 = numToString(hour24) + ':' + numToString(min24) + ':' + numToString(sec24);
			timeOfDay = checkTimeOfDay(hour12, hour24);

			// Delay display refresh
			Sleep(1000);

			// Refresh display for updated times
			system("CLS");
		}
		// Updates the time depending on the user selection
		tie(hour12, min12, sec12, hour24, min24, sec24) = menuChoice(hour12, min12, sec12, hour24, min24, sec24);
	}
	return 0;
};