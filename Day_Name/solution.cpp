#include <iostream>
#include <cmath>

using namespace std;

short OrderOfDayInTheWeek(const short Year, const short Month, const short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m  = Month + (12 * a) - 2;
    return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))) % 7;
}

string DayShortName(const short OrderOfDay)
{
    string ShortDaysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Stu"};
    return ShortDaysNames[OrderOfDay];
}

string FormattedData(const short Year, const short Month, const short Day, const string Diem = "/")
{
    return to_string(Day) + Diem + to_string(Month) + Diem + to_string(Year);
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
    short Year  = ReadYear();
    short Month = ReadMonth();
    short Day   = ReadDay();

    short OrderOfDay = OrderOfDayInTheWeek(Year, Month, Day);

    cout << "\n\nDate      : " << FormattedData(Year, Month, Day, "/") << endl;
    cout << "Day order : " << OrderOfDay << endl;
    cout << "Day name  : " << DayShortName(OrderOfDay) << endl;
    return 0;
}