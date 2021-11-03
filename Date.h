#ifndef AIRLINETICKETMANAGEMENTSYSTEM_DATE_H
#define AIRLINETICKETMANAGEMENTSYSTEM_DATE_H

struct Date
{
    int day;
    int month;
    int year;
};

inline  Date getDate(std::string date);

inline bool isPastDateValid(Date date);

inline bool isFutureDateValid(Date date);

inline int numberOfDaysInMonth(int const &month, int const &year);

inline bool isDateValid(std::string date);

inline bool isPastTheDate(Date date1, Date date2);

#endif //AIRLINETICKETMANAGEMENTSYSTEM_DATE_H
