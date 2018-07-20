#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//clockType.h
class clockType
{
public:
    void setTime(int hours, int minutes, int seconds);
    //Sets the time to parameters specified
    //          hr = hours, min = minutes, sec = seconds

    void getTime(int& hours, int& minutes, int& seconds) const;
    //Function to get the time
    //          hours = hr, minutes = min, seconds = sec

    void printTime() const;
    //Outputs the time

    void incrementSeconds();
    //Increase seconds
    //          If the seconds are > 59, change the seconds to 0 and increment minute

    void incrementMinutes();
    //Increase minutes
    //          If the minutes are > 59, change the minutes to 0 and increment hour

    void incrementHours();
    //Increase hours
    //          If the hours are > 23, change the hour to 0

    bool equalTime(const clockType& otherClock) const;
    //Function to check if one clock is equal to another

    clockType(int hours, int minutes, int seconds);
    //Constructor with parameters

    clockType();
    //Default constructor

private:
    int hr; //Stores the hours
    int min; //Stores the minutes
    int sec; //Stores the seconds
};

//clockType.cpp
void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
	    hr = hours;
	else
	    hr = 0;

	if (0 <= minutes && minutes < 60)
	    min = minutes;
	else
	    min = 0;

	if (0 <= seconds && seconds < 60)
	    sec = seconds;
	else
	    sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	   hr = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
	    min = 0;
	    incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
	    sec = 0;
	    incrementMinutes();
	}
}

void clockType::printTime() const
{
	if (hr < 10)
	    cout << "0";
	cout << hr << ":";

	if (min < 10)
	    cout << "0";
	cout << min << ":";

	if (sec < 10)
	   cout << "0";
	cout << sec;
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr
		    && min == otherClock.min
		    && sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

clockType::clockType()  //default constructor
{
    hr = 0;
    min = 0;
    sec = 0;
}

//extClockType.h
class extClockType: public clockType
{
public:
    void printTimeZone();
    //Output the timezone

    extClockType(string timeZone);
    //Constructor with parameters

private:
    string dTimeZone; //Store the timezone
};

//extClockType.cpp
extClockType::extClockType(string timeZone)
{
    dTimeZone = timeZone;
}

void extClockType::printTimeZone()
{
	cout << dTimeZone;
}

//dateType.h
class dateType
{
public:
	void setDate(int month, int day, int year);
	//Set the date to parameters
	//          dMonth = month, dDay = day, dYear = year

	int getDay() const;
	//Return the day

	int getMonth() const;
	//Return the month

	int getYear() const;
	//Return the year

	void printDate() const;
	//Output the date

	bool isLeapYear(int year);
	//Checks if the year is a leap year

	dateType(int month = 1, int day = 1, int year = 1900);
	//Constructor with parameters

	dateType();
	//Default constructor

private:
	int dMonth; //Stores the month
	int dDay; //Stores the day
	int dYear; //Stores the year
};

//dateType.cpp
void dateType::setDate(int month, int day, int year)
{
		if(month > 0 && month < 13) //Checks if the month is valid
	{
		dMonth = month;

		if(isLeapYear(year) && month == 2) //Checks if the year is a leap year, if the month is 2, and if the day is valid
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
		else if(!isLeapYear(year) && month == 2) //Checks if the year is a leap year, if the month is 2, and if the day is valid
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
		else if(month == 1, 3, 5, 7, 8, 10, 12) //Checks if the day is valid for specific months
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
		else if(month == 4, 6, 9, 11) //Checks if the day is  valid for specific months
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
	else if(tempYear == 0 && centuryYear != 0) //If the year is divisible by 4, but not divisible by 100, it is a leap year
	{
		return true;
	}
	else //If none of the above are true, it is not a leap year
	{
		return false;
	}

}

dateType::dateType(int month, int day, int year)
{
	if(month > 0 && month < 13) //Checks if the month is valid
	{
		dMonth = month;

		if(isLeapYear(year) && month == 2) //Checks if the year is a leap year, if the month is 2, and if the day is valid
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
		else if(!isLeapYear(year) && month == 2) //Checks if the year is a leap year, if the month is 2, and if the day is valid
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
		else if(month == 1, 3, 5, 7, 8, 10, 12) //Checks if the day is valid for specific months
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
		else if(month == 4, 6, 9, 11) //Checks if the day is  valid for specific months
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

//dateTime.h
class dateTime
{
public:
    dateTime(dateType date, clockType clock, extClockType extendedClock);
    //Constructor with parameters

    void printDateTime();
    //Output the date, time, and timezone

private:
    dateType dDate; //Store the date
    clockType dTime; //Store the time
    extClockType dTimeZone; //Store the timezone
};
//dateTime.cpp
dateTime::dateTime(dateType date, clockType clock, extClockType extendedClock)
: dDate(date), dTime(clock), dTimeZone(extendedClock)
{
}

void dateTime::printDateTime()
{
    dDate.printDate();
    cout << "\n";
    dTime.printTime();
    cout << " ";
    dTimeZone.printTimeZone();
    cout << "\n\n"; //This is just here to put space between the outputs
}

//main.cpp
int main()
{
    //First set of data
    dateType dateTypeObj(1, 1, 1900);
    clockType clockObj(2, 1, 30);
    extClockType extClockObj("CST");

    //Second set of data
    dateType dateTypeObj2(2, 29, 2004);
    clockType clockObj2(23, 5, 20);
    extClockType extClockObj2("MST");

    //Third set of data
    dateType dateTypeObj3(8, 13, 1990);
    clockType clockObj3(1, 40, 59);
    extClockType extClockObj3("CST");

    //Testing first dataset
    dateTime dateTimeObj(dateTypeObj, clockObj, extClockObj);
    dateTimeObj.printDateTime();

    //Testing second dataset
    dateTime dateTimeObj2(dateTypeObj2, clockObj2, extClockObj2);
    dateTimeObj2.printDateTime();

    //Testing third dataset
    dateTime dateTimeObj3(dateTypeObj3, clockObj3, extClockObj3);
    dateTimeObj3.printDateTime();

    return 0;
}
