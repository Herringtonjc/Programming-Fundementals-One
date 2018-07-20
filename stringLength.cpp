#include <fstream>
#include <iostream>
using namespace std;

//Professor, you may ignore this code. I was using this little program to read the length of the string I was using for the array.

int main()
{
    ifstream infile("arrayInput.txt");
    string strSize;

    infile >> strSize;
    cout << strSize.length();
}
