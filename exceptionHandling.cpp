#include <iostream>
#include <fstream>
using namespace std;

//Main loop
int main()
{
    int feet, inches; //Variables for user input
    double centimeters; //Returned variable

    string errorString = "The stream is in a failure state."; //Failure in the event of incorrect input
    bool done = false; //Keeps the loop running to change input

    //Setting file input and output
    ifstream infile;
    infile.open("inputDataFeet.txt");
    ifstream infile2;
    infile2.open("inputDataInches.txt");
    ofstream outfile;
    outfile.open("outputData.txt");

    do
    {
        try
        {
            infile >> feet; //Read in feet
            infile2 >> inches; //Read in inches

            if(feet < 0) //No negative feet
                throw feet;
            else if(inches < 0) //No negative inches
                throw inches;
            else if(!cin) //Only integer inputs
                throw errorString;

            done = true;

            centimeters = ((feet * 12) + inches) * 2.54; //Conversion algorithm

            outfile << "You entered " << feet << " feet and " << inches << " inches. \n";
            outfile << "The centimeter equivalent is: " << centimeters;

        }

        catch(int x)
        {
            outfile << "You cannot have " << x << " as a dimension!" << endl;
            cin.clear(); //Clear the error flag
            cin.ignore(100, '\n'); //Flush the character buffer
        }
        catch(string s)
        {
            cout << s << endl;
            cout << "Restoring the stream." << endl;
            cin.clear(); //Clear error flag
            cin.ignore(100, '\n'); //Flush character buffer
        }
    } while(!done); //Keep looping until input is valid
}
