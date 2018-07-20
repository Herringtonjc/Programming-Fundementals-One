#include <iostream>
using namespace std;

//rectangleType.h
class rectangleType
{
public:
    void setDimension(double l, double w);
    //Function to set the dimensions of a rectangle

    double getLength() const;
    //Function to return the length

	double getWidth() const;
    //Function to return the width

	double area() const;
    //Function to calculate the area

	double perimeter() const;
	//Function to calculate the perimeter

	void print() const;
	//Function to output the dimensions

    //Overloading the arithmetic operators
    rectangleType operator-(const rectangleType&) const;

    //Overloading the relational operators
    bool operator==(const rectangleType&) const;
    bool operator!=(const rectangleType&) const;
    bool operator<=(const rectangleType&) const;
    bool operator>=(const rectangleType&) const;

    //Overloading the increment operators
    rectangleType operator++();
    rectangleType operator++(int);

    //Overloading the decrement operators
    rectangleType operator--();
    rectangleType operator--(int);

    //Constructors
    rectangleType();
    rectangleType(double l, double w);

protected:
    double length; //Store the length
    double width; //Store the width
};

//rectangleType.cpp
void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0;

    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength() const
{
    return length;
}

double rectangleType::getWidth()const
{
    return width;
}

double rectangleType::area() const
{
    return length * width;
}

double rectangleType::perimeter() const
{
    return 2 * (length + width);
}

void rectangleType::print() const
{
    cout << "Length = "  << length
         << "; Width = " << width << "\n\n";
}

rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w);
}

rectangleType::rectangleType()
{
    length = 0;
    width = 0;
}

rectangleType rectangleType::operator-(const rectangleType& rectangle) const
{
    rectangleType tempRect;

    if(length - rectangle.length < 0 || width - rectangle.width < 0)
    {
        cout << "The dimensions cannot be negative.\n\n";
    }
    else
    {
        tempRect.length = length - rectangle.length;
        tempRect.width = width - rectangle.width;
    }
    return tempRect;
}

bool rectangleType::operator==
                      (const rectangleType& rectangle) const
{
    return (area() == rectangle.area());
}

bool rectangleType::operator!=
                       (const rectangleType& rectangle) const
{
    return (area() != rectangle.area());
}


bool rectangleType::operator<=(const rectangleType& rectangle) const
{
    return(area() <= rectangle.area());
}

bool rectangleType::operator>=(const rectangleType& rectangle) const
{
    return(area() >= rectangle.area());
}

rectangleType rectangleType::operator++()
{
    ++length;
    ++width;

    return *this;
}

rectangleType rectangleType::operator++(int a)
{
    rectangleType temp = *this;

    length++;
    width++;

    return temp;
}

rectangleType rectangleType::operator--()
{
    --length;
    --width;

    if(length < 0 || width < 0)
    {
        cout << "The dimensions cannot be negative.\n\n";
    }

    return *this;
}

rectangleType rectangleType::operator--(int a)
{
    rectangleType temp = *this;

    length--;
    width--;

    if(length < 0 || width < 0)
    {
        cout << "The dimensions cannot be negative. \n";
    }

    return temp;
}
//main.cpp
int main()
{

    rectangleType smallRect(2, 2); //Construct a rectangle of 2, 2
    rectangleType bigRect(5, 5); //Construct a rectangle of 5, 5

    smallRect - bigRect;
    //The Dimensions cannot be negative

    if(smallRect == bigRect) //False
    {
        cout << "The rectangles are equal. \n\n";
    }

    if(smallRect != bigRect) //True
    {
        cout << "The rectangles are not equal. \n\n";
    }

    if(smallRect <= bigRect) //True
    {
        cout << "smallRect is less than or equal to bigRect. \n\n";
    }

    if(bigRect >= smallRect) //True
    {
        cout << "bigRect is greater than or equal to smallRect. \n\n";
    }

    smallRect.print(); //smallRect is 2, 2
    smallRect++;
    smallRect.print(); //smallRect is 3, 3

    smallRect.print(); //smallRect is 3, 3
    ++smallRect;
    smallRect.print(); //smallRect is 4, 4

    smallRect.print(); //smallRect is 4, 4
    smallRect--;
    smallRect.print(); //smallRect is 3, 3

    smallRect.print(); //smallRect is 3, 3
    --smallRect;
    smallRect.print(); //smallRect is 2, 2


	return 0;
};
