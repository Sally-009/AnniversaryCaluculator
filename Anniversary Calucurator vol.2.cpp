// Saori Kojima
// Date: 12/11/2021
// Program Title: Anniversary Caluculator
// Program Description: caluculate anniversary based on the user's input

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Constants
const int CURRENT_YEAR = 2021;
const int RANGE_OF_DAYS = 10000;

// global valuables
bool isLeapYear = false;
int anniversary = 1;

// Function Declaration
void toNext();
bool checkDateError(int a, int b, int c);
bool checkDayError(int x);
void anniversaryFunc(int x, int y, int z);
bool isLeapYearFunc(int x);
int theEndOfTheDayFunc(int x, int y, int z);
void toEnd();

// main function ------------------------------------------------------------------------------

int main()
{
	// Variable Declaration
	int year, month, day;
	bool dateError = false;
	bool dayError = false;

	// Program title and description for the user

	cout << "***********************" << endl << endl;

	cout << "Anniversary Caluculator" << endl << endl;

	cout << "***********************" << endl << endl;

	cout << "This program will calculate optional-days-anniversary" << endl
		<< "based on the following rules: " << endl;
	cout << " - the leap years will be applied." << endl;
	cout << " - the range is within " << RANGE_OF_DAYS << " days." << endl;

	toNext();

	// User Input -------------

	cout << "-------------------------------------------------------" << endl;

	// Enter the date
	do
	{
		dateError = false;
		year, month, day = 0;

		cout << "Enter the date you started dating in the following order (year month day): " << endl
			<< ">> ";
		cin >> year >> month >> day;

		cout << endl;

		// check !cin
		if (!cin)
		{
			cout << "INPUT ERROR. Program Terminating..." << endl;
			return 1;
		}

		// check other inout error
		dateError = checkDateError(year, month, day);

	} while (dateError == true);

	// Enter the days to calculate
	do
	{
		dayError = false;
		anniversary = 0;

		cout << "Enter the days of anniversary that you want to know: " << endl
			<< ">> ";
		cin >> anniversary;

		// check !cin
		if (!cin)
		{
			cout << "INPUT ERROR. Program Terminating..." << endl;
			return 1;
		}

		// check other inout error
		dayError = checkDayError(anniversary);

	} while (dayError == true);

	cout << "-------------------------------------------------------" << endl;

	// check the leap year
	isLeapYear = isLeapYearFunc(year);

	// Caluculations and output-----------
	system("cls");

	anniversaryFunc(year, month, day);

	// End this Program
	toEnd();

	return 0;

}

// user-defined function ------------------------------------------------------------------------------

void toNext()
{
	int next;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "* Enter 1 or any number to go to the next page. *" << endl;
	cin >> next;

	system("cls");
}

/*
a = year
b = month
c = day
*/
bool checkDateError(int x, int y, int z)
{
	bool error = false;
	bool isLeapYear = false;

	// year
	if (x > CURRENT_YEAR || x < CURRENT_YEAR - 100)
	{
		cout << "Enter a valid year." << endl;
		error = true;
	}

	// month
	if (y > 12 || y < 1)
	{
		cout << "Enter a valid month." << endl;
		error = true;
	}

	// day

	if (z < 1)
	{
		cout << "Enter a valid day." << endl;
		error = true;
	}

	switch (y)
	{
		// when 31st
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:

		if (z > 31)
		{
			cout << "Enter a valid day." << endl;
			error = true;
		}

		break;

		// when 30th
	case 4:
	case 6:
	case 9:
	case 11:

		if (z > 30)
		{
			cout << "Enter a valid day." << endl;
			error = true;
		}
		break;

		// when 28 or 29th
	case 2:

		isLeapYear = isLeapYearFunc(x);

		if (isLeapYear == true)	// 29th
		{
			if (z > 29)
			{
				cout << "Enter a valid day." << endl;
				error = true;
			}
		}
		else {

			if (z > 28)
			{
				cout << "Enter a valid day." << endl;
				error = true;
			}
		}

	default:
		break;
	}

	return error;
}

bool checkDayError(int x)
{
	bool error = false;

	// check negative number
	if (x < 0)
	{
		cout << "The days must be a positive number. Try again." << endl;
		error = true;
	}

	// decide the range
	if (x > RANGE_OF_DAYS)
	{
		cout << "The range is within " << RANGE_OF_DAYS << " days. try again." << endl;
		error = true;
	}

	return error;

}

/*
caluculate anniversary
x = year
y = month
z = day
*/
void anniversaryFunc(int x, int y, int z)
{
	int theEndOfTheDay = 0;
	int restOfTheAnniversary = anniversary;

	// Decide the end of the day based on the month
	theEndOfTheDay = theEndOfTheDayFunc(x, y, z);

	while (restOfTheAnniversary > theEndOfTheDay)
	{
		//cout << "the end of the day: " << theEndOfTheDay << endl;

		// add days
		while (z < theEndOfTheDay)
		{
			z++;
			restOfTheAnniversary--;
		}

		/*
		cout << z << endl;
		cout << restOfTheAnniversary << endl;
		*/

		// check if the month reached to December
		if (y == 12)
		{
			x++;
			y = 0;

			isLeapYear = isLeapYearFunc(x);

		}
		// go to the next month
		y++;
		z = 0;

		theEndOfTheDay = theEndOfTheDayFunc(x, y, z);

	}

	// add redt of the days
	z = z + restOfTheAnniversary;

	// Show the result

	cout << "---------------------------------------------------------------" << endl << endl;

	cout << "Your " << anniversary << " days anniversary is " << x << " / " << y << " / " << z << "." << endl << endl;

	cout << "---------------------------------------------------------------" << endl << endl;


}

bool isLeapYearFunc(int x)
{
	bool leapYear = false;

	double remainder;

	// devided by 4

	remainder = x % 4;

	if (remainder == 0)
	{
		leapYear = true;

		// if the year can be divided by 100, 
		remainder = x % 100;

		if (remainder == 0)
		{
			// then divided by 400 as well
			remainder = x % 400;

			if (remainder == 0)
				leapYear = true;
			else
				leapYear = false;
		}
		else {
			leapYear = true;
		}


	}
	else {
		leapYear = false;
	}

	return leapYear;
}

int theEndOfTheDayFunc(int x, int y, int z)
{
	int day = 0;

	switch (y)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:

		day = 31;

		break;

	case 4:
	case 6:
	case 9:
	case 11:

		day = 30;

		break;

	case 2:

		if (isLeapYear == true)
			day = 29;
		else
			day = 28;

		break;

	default:
		break;
	}

	return day;
}

void toEnd()
{
	int next;

	cout << endl;
	cout << "* Enter 1 or any number to go to finish this program. *" << endl;
	cin >> next;

	system("cls");
}
