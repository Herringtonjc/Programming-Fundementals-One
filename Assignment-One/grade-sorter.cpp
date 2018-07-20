#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Setting the number of components for our array as a constant variable
const int NUMBER_OF_STUDENTS = 20;

//Global variable for the highestScore
int highestScore = 0;

//The struct to hold our students
struct studentType {
	string studentFName;
	string studentLName;
	int testScore;
	const char* grade;
};

//Assign an array of of the studentType structs with a length of the constant variable
studentType students[NUMBER_OF_STUDENTS];

//Function prototypes
void getStudentData(ifstream& indata, studentType list[], int listSize);
void assignLetterGrade(ifstream& indata, studentType list[], int listSize);
void findHighestScore(ofstream& outdata, studentType list[], int listSize);
void printStudent(ofstream& outdata, studentType list[], int listSize, int highestScore);

int main()
{
	//The file we are reading from
	ifstream infile("Students.txt");
	//The file we output to
	ofstream outfile("StudentsOutput.txt");
	
	getStudentData(infile, students, NUMBER_OF_STUDENTS);
	assignLetterGrade(infile, students, NUMBER_OF_STUDENTS);
	findHighestScore(outfile, students, NUMBER_OF_STUDENTS);
	printStudent(outfile, students, NUMBER_OF_STUDENTS, highestScore);

	infile.close();
	outfile.close();
	
	return 0;
} //End main

//Reads the input file, and grabs the information line by line
void getStudentData(ifstream& indata, studentType list[], int listSize)
{
	int index;

	for (index = 0; index < listSize; index++)
	{
		indata >> list[index].studentFName >> list[index].studentLName >> list[index].testScore;
	}
} //End assignStudents

//Iterates through the grade members of our studentType structs, assigning letters based on the int values
void assignLetterGrade(ifstream& indata, studentType list[], int listSize)
{
	int index;
	
	for (index = 0; index < listSize; index++)
	{
		if (list[index].testScore >= 90)
		{
			list[index].grade = "A";
		}
		if (list[index].testScore < 90 && list[index].testScore >= 80)
		{
			list[index].grade = "B";
		}
		if (list[index].testScore < 80 && list[index].testScore >= 70)
		{
			list[index].grade = "C";
		}
		if (list[index].testScore < 70 && list[index].testScore >= 60)
		{
			list[index].grade = "D";
		}
		if (list[index].testScore < 60)
		{
			list[index].grade = "F";
		}
	}
}

//Iterates through the grade members of our studentType structs
//Reassigns the global variable with the new highestScore
//Updated consecutively
void findHighestScore(ofstream& outdata, studentType list[], int listSize)
{
	int index;

	for (index = 0; index < listSize; index++)
	{
		if (list[index].testScore > highestScore)
		{
			highestScore = list[index].testScore;
		}
	}
} //End findHighestScore

//Outputs the list of students formatted: studentLName, studentFName, testScore, grade
//Outputs the student with the highest grade found
void printStudent(ofstream& outdata, studentType list[], int listSize, int highestScore)
{
	int index;
	
	outdata << "----------Student List----------" << endl;
	outdata << endl;	
	for (index = 0; index < listSize; index++)
	{
		outdata << list[index].studentLName << ", " << list[index].studentFName << " Score: " << list[index].testScore << " Grade: " << list[index].grade << endl;
	}
	outdata << endl;
	
	for (index = 0; index < listSize; index++)
	{
		if (list[index].testScore == highestScore)
		{
			outdata << "----------Highest Score----------" << endl;
			outdata << endl;
			outdata << "The student with the highest test score was " << list[index].studentFName << " " << list[index].studentLName << " with a score of " << highestScore;
		}
	}
} //End printStudent
