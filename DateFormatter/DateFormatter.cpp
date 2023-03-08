#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//This program will validate a user's input for a date and return three different formats for that date.
class Date{
	private:
		int month;
		int date;
		int year;
		string names[12];
		void setNames()
		{
			names[0] = "January";
			names[1] = "February";
			names[2] = "March";
			names[3] = "April";
			names[4] = "May";
			names[5] = "June";
			names[6] = "July";
			names[7] = "August";
			names[8] = "September";
			names[9] = "October";
			names[10] = "November";
			names[11] = "December";
		};
	public:
		Date(){};
		Date(int, int, int); //overloaded constructor, will take the input variables and assign them to the private class variables.
		void setMonth(int mon) //mutator functions to set the private class variables, to be called within the constructor function.
		{month = mon;}
		void setDate(int day)
		{date = day;}
		void setYear(int yr)
		{year = yr;}
		void dateFormat1(); //prototypes for the formatting functions
		void dateFormat2();
		void dateFormat3();
};



int main(int argc, char *argv[]) {
int inMonth, inDay, inYear;
	cout << "Please enter the date you would like formatted." << endl;
	cout <<"Month: (NN)" << endl;
	cin >> inMonth;
		while (inMonth > 12 || inMonth < 1){ //month input validation
				cout <<"Please enter a valid month." << endl;
				cin >> inMonth;
			}

	cout << "Day: (NN)" << endl;
	cin >> inDay;
		while (inDay > 31 || inDay < 1){ //day input validation
				cout <<"Please enter a valid day." << endl;
				cin >> inDay;
			}
		
	cout <<"Year: (NNNN)" << endl;
	cin >> inYear;

Date date1(inMonth, inDay, inYear); //creates the class object using the input variables
date1.dateFormat1(); //function calls to format the dates
date1.dateFormat2();
date1.dateFormat3();

	return 0;
}



Date::Date(int mon, int day, int yr) //overloaded constructor function
{
	setNames(); //sets the names of the months to the names array, must call here because it is a private function
	setMonth(mon);
	setDate(day);
	setYear(yr);
}

void Date::dateFormat1(){
	cout << month << "/" << date << "/" << year << endl;	
}

void Date::dateFormat2(){
	cout << names[month-1] << " " << date << ", " << year << endl;
}

void Date::dateFormat3(){
	cout << date << " " << names[month-1] << " " << year << endl;
}




