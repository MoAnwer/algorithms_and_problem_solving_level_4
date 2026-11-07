#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
    return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

short ReadYear()
{
    short Year = 0;
    cout << "Please Enter a Year: ";
    cin >> Year;
    return Year;    
}

short NumberOfDaysInAYear(const short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(const short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(const short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(const short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

void PrintResults(const short Year)
{
    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);
}

int main()
{
    short Year = ReadYear();

    PrintResults(Year);

    return 0;
}