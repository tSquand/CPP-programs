#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct planeActivity {
	int landed;
	int departed;
	int greatestLanded;
	int leastLanded;
};

int main(int argc, char *argv[]) {
	planeActivity monthly[12]; //structure array that will hold all input
	string current[12] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //declaring an array that holds each month for output purposes.
	double accumulator, average;
	
	cout << "Hello! The purpose of this program is track monthly arrivals/departures.\nPlease have this information ready for the entire year." << endl;
	
		for (int count = 0; count < 12; count++) //for loop to receive input for every month
		{
			cout << "\nPlease enter the following information for the month of " << current[count] << "." << endl;
			
			cout << "How many planes arrived?" << endl;
			cin >> monthly[count].landed;
			
			cout << "How many planes departed" << endl;
			cin >> monthly[count].departed;
			
			cout << "What was the greatest number of planes that arrived in one day this month?" << endl;
			cin >> monthly[count].greatestLanded;
			
			cout << "What was the least number of planes that arrived in one day this month?" << endl;
			cin >> monthly[count].leastLanded;	
		}	
		
			cout << "\t\t\tHere is the information you have entered: " << endl;
			for (int count = 0; count < 12; count++) // for loops to display all info for each month
		{
			cout << "\n\t\t\t\t\t" << current[count] << ":" << endl;
			cout << "==========================================================================================================" << endl;
			cout << "Arrivals: " << monthly[count].landed << " \t\t Departures: " << monthly[count].departed << "\t\t Most Arrived/Day: " <<  monthly[count].greatestLanded << "\t\t Least Arrived/Day: " << monthly[count].leastLanded << endl; 
	
		
		}
		
		for (int count = 0; count < 12; count++) //for loop to add each months landings together and find the average
		{
			accumulator += monthly[count].landed;
			average = accumulator/12;
		}
				
		cout << "\nThe average number of arrivals per month this year is " << average << "!" << endl;
				
	return 0;
}
