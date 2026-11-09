#include <iostream>

using namespace std;

bool IsLeapYear(const short Year)
{
    return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(const short Month, const short Year)
{
    if (Month < 1 || Month > 12)
        return 0;
    
    if (Month == 2) return IsLeapYear(Year) ? 29 : 28;

    return Month == 4 || Month == 6 || Month == 9 || Month == 11 ? 30 : 31;
}


short NumberOfDaysFromBeginningOfTheYear(const short Day, const short Month, const short Year)
{
    if (Day == 0) return 0;

    short NumberOfDays = Day;

    for (short i = 1; i < Month; i++)
        NumberOfDays += NumberOfDaysInAMonth(i, Year);
    
    return NumberOfDays;
}

short ReadDay()
{
    short day; 
    cout << "\nPlease enter a day: ";
    cin >> day;
    return day;
}

short ReadYear()
{
    short Year; 
    cout << "\nPlease enter a year: ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month; 
    cout << "\nPlease enter a month: ";
    cin >> Month;
    return Month;
}

int main()
{
    short Day   = ReadDay();
    short Month = ReadMonth();
    short Year  = ReadYear();

    cout << "Number of Days from th beginning of the year is: " << NumberOfDaysFromBeginningOfTheYear(Day, Month, Year);

    return 0;
}