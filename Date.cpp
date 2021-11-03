#include <vector>
#include <ctime>
#include <algorithm>
#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

Date getDate(std::string date)
{
    unsigned int hyphenIndex;
    std::string reducedDate;
    std::vector<int> dateArray;

    while (true)
    {
        hyphenIndex = date.find('-');
        if (hyphenIndex != std::string::npos)
        {
            reducedDate = date.substr(0, hyphenIndex);
            date = date.erase(0, reducedDate.length() + 1);
            dateArray.push_back(std::stoi(reducedDate));
            if (date.length() == 0)
                break;
        }
        else
        {
            dateArray.push_back(std::stoi(date));
            break;
        }
    }

    Date dateInfo{.day=dateArray[0], .month=dateArray[1], .year=dateArray[2]};
    return dateInfo;
}

bool isPastDateValid(Date date)
{
    time_t t = time(nullptr);
    tm *const currentTime = localtime(&t);

    const int currentYear = 1900 + currentTime->tm_year;
    const int currentDay = currentTime->tm_mday;
    const int currentMonth = currentTime->tm_mon + 1;

    const int pastDateDay = date.day;
    const int pastDateMonth = date.month;
    const int pastDateYear = date.year;

    if (pastDateYear < currentYear)
    {
        return true;
    }
    else if (pastDateYear == currentYear)
    {
        if (pastDateMonth < currentMonth)
        {
            return true;
        }
        else if (pastDateMonth == currentMonth)
        {
            if (pastDateDay < currentDay)
            {
                return true;
            }
        }
    }
    return false;
}

bool isFutureDateValid(Date date)
{
    const int futureDateDay = date.day;
    const int futureDateMonth = date.month;
    const int futureDateYear = date.year;

    time_t t = time(nullptr);
    tm *const currentTime = localtime(&t);

    const int currentYear = 1900 + currentTime->tm_year;
    const int currentDay = currentTime->tm_mday;
    const int currentMonth = currentTime->tm_mon + 1;

    if (futureDateYear > currentYear)
    {
        return true;
    }
    else if (futureDateYear == currentYear)
    {
        if (futureDateMonth == currentMonth)
        {
            if (futureDateDay > currentDay)
            {
                return true;
            }
        }
        else if (futureDateMonth > currentMonth)
        {
            return true;
        }
    }
    return false;
}

int numberOfDaysInMonth(int const &month, int const &year)
{
    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

bool isDateValid(std::string date)
{
    std::string day, month, year;
    std::vector<std::string> dateArray;
    std::string reducedDate;
    unsigned int hyphenIndex;

    while (true)
    {
        hyphenIndex = date.find('-');
        if (hyphenIndex != std::string::npos)
        {
            reducedDate = date.substr(0, hyphenIndex);
            date = date.erase(0, reducedDate.length() + 1);
            dateArray.push_back(reducedDate);
            if (date.length() == 0)
                break;
        }
        else
        {
            dateArray.push_back(date);
            break;
        }
    }

    if (dateArray.size() != 3)
        return false;

    day = dateArray[0];
    month = dateArray[1];
    year = dateArray[2];

    if (std::all_of(day.begin(), day.end(), ::isdigit) &&
        std::all_of(month.begin(), month.end(), ::isdigit) &&
        std::all_of(year.begin(), year.end(), ::isdigit))
    {
        const int dayInt = std::stoi(day);
        const int monthInt = std::stoi(month);
        const int yearInt = std::stoi(year);

        const int daysInMonth = numberOfDaysInMonth(monthInt, yearInt);
        const int numberOfMonths = 12;

        if (daysInMonth >= dayInt && dayInt >= 1)
        {
            if (numberOfMonths >= monthInt && monthInt >= 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool isAfterTheDate(Date date1, Date date2)
{
    if (date1.year > date2.year)
    {
        return true;
    }
    if (date1.year == date2.year && date1.month > date2.month)
    {
        return true;
    }
    if (date1.year == date2.year && date1.month == date2.month && date1.month > date2.month)
    {
        return true;
    }
    return false;
}
