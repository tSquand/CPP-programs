#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

// this function gets four assignment grades and averages them
float averageQuizzes(int, int, int, int);
// this function gets a midterm, a final and the assignment average and averages them 
float averageFinal(int, int, float);
//  this functions takes the final average and returns the correspondingletter grade
char getLetterGrade(int);
//  this function takes the final average and the number of classes attended to determine if the student passes
void ifPassedClass(int, int);

int main(int argc, char *argv[])
{
    //open file
    ifstream myfile;
    myfile.open ("bettergrades.txt");
    while (!myfile.eof())
    {
    	float quizavg, gradeavg;
    	char letterGrade;
    	string firstName, lastName; 
    	int q1, q2, q3, q4, midterm, exam, attendance;
    	
    	//read in student information here
    	myfile >> firstName >> lastName >> q1 >> q2 >> q3 >> q4 >> midterm >> exam >> attendance;

          //call functions in order here
        cout << firstName << " " << lastName << " ";
        
        quizavg = averageQuizzes(q1,q2,q3,q4);
        cout << quizavg << " ";
        
        gradeavg = averageFinal(midterm, exam, quizavg);
        cout << gradeavg << " ";
       
        letterGrade = getLetterGrade(gradeavg);
        cout << letterGrade << endl;
        
    	ifPassedClass (letterGrade, attendance);
    
    }
    //close file
    myfile.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
//gets average of first four quizzes and sends it back to main as variable quizavg
 float averageQuizzes(int q1, int q2, int q3, int q4)
    {
    	float quizavg = (q1 + q2 + q3 + q4)/4.0;
    	return quizavg;
    }
//gets avg of midterm + exam + quiz avgs and sends it back to main as variable gradeavg
float averageFinal(int midterm, int exam, float quizavg)
	{
		float gradeavg = (midterm + exam + quizavg)/3.0;
		return gradeavg;
	}
// calculates letter grade based on gradeavg
char getLetterGrade(int gradeavg)
	{
		char letterGrade;
		if (gradeavg >= 90.0)
		letterGrade = 'A';
		else if (gradeavg < 90.0 && gradeavg >= 80.0)
		letterGrade = 'B';
		else if (gradeavg < 80.0 && gradeavg >= 70.0)
		letterGrade = 'C';
		else if (gradeavg < 70.0 && gradeavg >= 60.0)
		letterGrade = 'D';
		else if (gradeavg < 60.0)
		letterGrade = 'F';
		
		return letterGrade;
	}
//shows if student passed or failed based on attendance and gradeavg
void ifPassedClass(int letterGrade, int attendance)
	{
		if (attendance < 30)
		cout << "The student has failed due to attendance." << endl;
		else if (letterGrade <= 'D')
		cout << "The student has passed." << endl;
		else if (letterGrade > 'D')
		cout << "The student has failed." << endl;
	}

