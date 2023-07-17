#include <iostream>
using namespace std;

//KY258 ÈÕÆÚÀÛ¼Ó
bool isleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else return false;
}
int dayofmonth[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
                           {0,31,29,31,30,31,30,31,31,30,31,30,31} };

int main()
{
    int m;
    int year, month, day, n;
    cin >> m;
    while (m--)
    {
        cin >> year >> month >> day >> n;
        n += day;
        day = 0;
        while (n >= dayofmonth[isleapyear(year)][month])
        {
            n -= dayofmonth[isleapyear(year)][month];
            if (month == 12)
            {
                month = 1;
                year++;
            }
            else
            {
                month++;
            }
        }
        day += n;
        if (day == 0)
        {
            month--;
            day = dayofmonth[isleapyear(year)][month];
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
