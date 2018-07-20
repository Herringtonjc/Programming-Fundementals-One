//romanType.h, the specification file for the class romanType
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class romanType
{
public:
	void getNumerals(ifstream& indata);
	//Get roman numerals from a file

	int values(char roman);
	//Return the values of all possible roman numerals

	int convert();
	//Convert the roman numerals into integers

	void printNumerals(ofstream& outdata);
	//Output the roman numerals to a file

	void printIntegers(ofstream& outdata);
	//Output the positive integers to a file

private:
	string romanNumeral; //Stores the roman numeral
	int romanInteger; //Stores the integer value
};


/////////////////////////////////////////////////////////////////////
//Implementation file for the class romanType

void romanType::getNumerals(ifstream& indata)
{
	indata >> romanNumeral;
}

int romanType::values(char roman)
{
	switch(roman)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0; //If no numeral is found, value is 0
	}
}

int romanType::convert()
{
	int i, n, ans = 0, p = 0;
	n = romanNumeral.length() - 1;
	
	for(i = n; i >= 0; i--)
	{
		if(values(romanNumeral[i]) >= p)
			ans += values(romanNumeral[i]);
			
		else
		ans -= values(romanNumeral[i]);
		
	p = values(romanNumeral[i]);
	}
	romanInteger = ans;
	return romanInteger;
}

void romanType::printNumerals(ofstream& outdata)
{
	outdata << romanNumeral;
}

void romanType::printIntegers(ofstream& outdata)
{
	outdata << romanInteger;
}


/////////////////////////////////////////////////////////////////////
//User program using the class romanType
int main()
{
	int userAnswer;
	
	ifstream infile;
	infile.open("RomanInput.txt");
	
	ofstream outfile;	
	ofstream outfile2;

	romanType romanObject;
	romanObject.getNumerals(infile);
	romanObject.convert();
	
	//List of choices
	cout << "You may print out: \n" <<
	"1) Roman Numeral \n" <<
	"2) Positive Integers" << endl;
	cin >> userAnswer;
	
	if(userAnswer == 1)
	{
		outfile.open("RomanOutputNumerals.txt");
		romanObject.printNumerals(outfile);
		cout << "The roman numeral has been printed to RomanOutputNumerals.txt" << endl;
	}
	else if(userAnswer == 2)
	{
		outfile2.open("RomanOutputIntegers.txt");
		romanObject.printIntegers(outfile2);
		cout << "The positive integer has been printed to RomanOutputIntegers.txt" << endl;
	}
	else
	{
		cout << "I'm sorry, that is not a valid choice." << endl;
	}
	
	infile.close();
	outfile.close();
	outfile2.close();

	return 0;
}
