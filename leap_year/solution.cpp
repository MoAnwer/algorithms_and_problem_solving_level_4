#include <iostream>

using namespace std;

bool IsLeapYear(short year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// take space as you need (short Not int)
short ReadYear()
{
    short year = 0;
    cout << "Enter a year: ";
    cin >> year;
    return year;
}

int main()
{
    short Year = ReadYear();

    if(IsLeapYear(Year))
        cout << "Yes, " << Year << " is a leap year";
    else
        cout << "No, " << Year << " is NOT a leap year";
    return 0;
}
