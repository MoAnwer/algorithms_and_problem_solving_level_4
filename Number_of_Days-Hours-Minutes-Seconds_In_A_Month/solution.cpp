#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
    return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    
    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;
    
    short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 1; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month) return 31;
    }

    return 30;
}

short NumberOfHoursInAMonth(short Year, short Month)
{
    return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
    return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
    return NumberOfMinutesInAMonth(Year, Month) * 60;
}

short ReadShortInRange(string Message, short From, short To)
{
    short Number;
    cout << Message;
    cin >> Number;

    while (Number < From || Number > To)
    {
        cout << "\nInvalid number, please enter number between " << From << " to " << To << " : ";
        cin >> Number;
    }
    
    return Number;
}

int main()
{
    short Year = ReadShortInRange("\nPlease enter a year: ", 0, 9999);
    short Month = ReadShortInRange("\n\nPlease enter a month: ", 1, 12);

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month);
    return 0;
}
