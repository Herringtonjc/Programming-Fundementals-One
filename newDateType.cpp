//Header File dateType.h
#include <iostream>

class dateType
{
public:
	void setDate(int month, int day, int year);
	//Function to set the date.
	//The member variables dMonth, dDay, and dYear are set 
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day;
	//               dYear = year

	int getDay() const;
	//Function to return the day.
	//Postcondition: The value of dDay is returned.

	int getMonth() const;
	//Function to return the month.  
	//Postcondition: The value of dMonth is returned.

	int getYear() const;
	//Function to return the year.     
	//Postcondition: The value of dYear is returned.

	void printDate() const;
	//Function to output the date in the form mm-dd-yyyy.

	dateType(int month = 1, int day = 1, int year = 1900);
	//Constructor to set the date
	//The member variables dMonth, dDay, and dYear are set 
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day; dYear = year;
	//               If no values are specified, the default 
	//               values are used to initialize the member
	//               variables.
	
	bool isLeapYear(int year);
	//Function to check the year and determine if it
	//is a leap year.

private:
	int dMonth; //variable to store the month
	int dDay;   //variable to store the day
	int dYear;  //variable to store the year
};

//Implementation File impDateType.cpp
using namespace std;

void dateType::setDate(int month, int day, int year)
{
		if(month > 0 && month < 13)
	{
		dMonth = month;
		
		if(isLeapYear(year) && month == 2)
		{
			if(day < 1 || day > 29)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(!isLeapYear(year) && month == 2)
		{
			if(day < 1 || day > 28)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(month == 1, 3, 5, 7, 8, 10, 12)
		{
			if(day < 1 || day > 31)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(month == 4, 6, 9, 11)
		{
			if(day < 1 || day > 30)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else
		{
			dDay = 0;
		}
	}
	else
	{
		cout << "That is not a valid month. \n";
		dMonth = 0;
	}
	dYear = year;
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeapYear(int year)
{
	int tempYear = year % 4;
	int centuryYear = year % 100;
	int centuryLeapYear = year % 400;
	
	if(tempYear == 0 && centuryYear == 0 && centuryLeapYear == 0) //If the year is divisible by 4, by 100, and by 400, it is a leap year
	{
		return true;
	}
	else if(tempYear == 0 && centuryYear == 0 && centuryLeapYear != 0) //If the year is divisible by 4, by 100, but not by 400, it is not a leap year
	{
		return false;
	}
	else if(tempYear == 0 && centuryYear != 0) //If the year is divisible by 4, but not divisble by 100, it is a leap year
	{
		return true;
	}
	else //If none of the above are true, it is not a leap year
	{
		return false;
	}
	
}

//Constructor with parameters
dateType::dateType(int month, int day, int year)
{
	if(month > 0 && month < 13)
	{
		dMonth = month;
		
		if(isLeapYear(year) && month == 2)
		{
			if(day < 1 || day > 29)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(!isLeapYear(year) && month == 2)
		{
			if(day < 1 || day > 28)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(month == 1, 3, 5, 7, 8, 10, 12)
		{
			if(day < 1 || day > 31)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else if(month == 4, 6, 9, 11)
		{
			if(day < 1 || day > 30)
			{
				cout << "That is not a valid day. \n";
				dDay = 0;
			}
			else
			{
				dDay = day;
			}
		}
		else
		{
			dDay = 0;
		}
	}
	else
	{
		cout << "That is not a valid month. \n";
		dMonth = 0;
	}
	dYear = year;
}

//Test File for dateType.cpp
int main()
{
	cout << "dateTypeObject1 \n";
	cout << "Using the date 2-29-1900 \n";
	cout << "--------------------\n";
	dateType dateTypeObject1(2, 29, 1900); //This test should fail, because 1900 is not a leap year
	dateTypeObject1.printDate();
	cout << "\n\n";
	
	cout << "dateTypeObject2 \n";
	cout << "Using the date 2-29-2004 \n";
	cout << "--------------------\n";
	dateType dateTypeObject2(2, 29, 2004); //This test should pass because 2004 is a leap year
	dateTypeObject2.printDate();
	cout << "\n\n";
	
	cout << "dateTypeObject3 \n";
	cout << "Using the date 2-29-2000 \n";
	cout << "--------------------\n";
	dateType dateTypeObject3(2, 29, 2000); //This test should pass because 2000 is a leap year, even though it is also a century year
	dateTypeObject3.printDate();
	cout << "\n\n";
	
	system("PAUSE");


	return 0;
}
