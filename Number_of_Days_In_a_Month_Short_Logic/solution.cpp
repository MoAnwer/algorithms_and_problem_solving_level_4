#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
    return Year % 400 || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2) return IsLeapYear(Year) ? 29 : 28;

    return Month == 4 || Month == 6 || Month == 9 || Month == 11 ? 30 : 31;
}

short DoctorNumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short ReadYear()
{
    short Year; 
    cout << "\nPlease enter a year to check: ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month; 
    cout << "\nPlease enter a month to check: ";
    cin >> Month;
    return Month;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);

    return 0;
}