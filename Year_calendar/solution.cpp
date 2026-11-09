#include <iostream>
#include <iomanip>

using namespace std;

string ShortDaysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

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

bool IsLeapYear(short Year)
{
    return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(const short Year, const short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    return Month == 4 || Month == 6 || Month == 9 || Month == 11 ? 30 : 31;
}

short OrderOfDayInTheWeek(const short Year, const short Month, const short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
}

string DayShortName(const short OrderOfDay)
{
    return ShortDaysNames[OrderOfDay];
}

string MonthShortName(const short Month)
{
    string ShortMonthsNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return ShortMonthsNames[Month - 1];
}

void PrintDaysOfWeekHeader()
{
    for (string &s : ShortDaysNames)
        cout << s << "\t";
    cout << "\n";
}

short FirstDayOfTheMonth(const short Year, const short Month)
{
    return OrderOfDayInTheWeek(Year, Month, 1);
}

void PrintMonthCalendarBody(const short Year, const short Month)
{
    short FirstDay  = FirstDayOfTheMonth(Year, Month);
    short DaysCount = NumberOfDaysInAMonth(Year, Month);

    for (short i = 0; i < FirstDay; i++) // Print spaces before the first day of the month
    {
        cout << "\t";
    }

    for (short i = 1; i <= DaysCount; i++)
    {
        cout << setw(2) << i << "\t";

        if ((i + FirstDay) % 7 == 0) // Start a new line after reaching Saturday (end of week)
        {
            cout << "\n";
        }
    }
}

void PrintMonthCalender(const short Year, const short Month)
{
    cout << "\n________________________" << MonthShortName(Month) << "________________________\n\n";

    PrintDaysOfWeekHeader();

    PrintMonthCalendarBody(Year, Month);

    cout << "\n____________________________________________________\n\n";
}

void PrintYearCalendar(const short Year)
{
    cout << "\n___________________________________________________\n";
    cout << "\n \t\t Calendar - " << Year << "\n";
    cout << "\n___________________________________________________\n\n";

    for (short Month = 1; Month <= 12; Month++)
    {
        PrintMonthCalender(Year, Month);
    }
}

int main()
{
    short Year = ReadYear();

    PrintYearCalendar(Year);

    system("pause");

    return 0;
}