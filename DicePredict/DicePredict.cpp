#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int prediction, rolls, combined, die;  //prediction = user guess / rolls = total number of rolls / combined = results combined / die = a single result
	const int MIN_VALUE = 1; //dice roll minimum
	const int MAX_VALUE = 6; //dice roll maximum
	
	cout << "How many six-sided die rolls do you predict it will take for the results to add up to 100?" <<endl;
	cin >> prediction;
	
	rolls = 0;
	combined = 0;
		unsigned seed = time(0); //rng
		srand(seed); 
		
cout << "Roll"<< '\t' << "Combined" << endl;
	do
	{
		rolls++; // counter
		
		die = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; //dice roll
		
		combined += die; //accumulator - dice roll added each iteration
		cout << die << '\t' << combined << endl;
	
		
	} while (combined < 100);
	
	cout << "It took " << rolls << " rolls to reach 100" << endl;
	
	//Ranges for results message. +/-5 = Great job! // +/- 10 = Good job. // +/- 15 = Okay. // +/- 20 = Think harder next time.
	if (prediction <= rolls + 5 && prediction >= rolls - 5)
	cout << "Great job!" << endl;
	else if (prediction <= rolls + 10 && prediction >= rolls - 10)
	cout << "Good job." << endl;
	else if (prediction <= rolls + 15 && prediction >= rolls - 15)
	cout << "Okay." << endl;
	else if (prediction <= rolls + 20 && prediction >= rolls - 20)
	cout << "Think harder next time." << endl;
	else
	cout << "Not even close." << endl; 
	
	
	return 0;
}
