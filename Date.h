#ifndef AIRLINETICKETMANAGEMENTSYSTEM_DATE_H
#define AIRLINETICKETMANAGEMENTSYSTEM_DATE_H

struct Date
{
    int day;
    int month;
    int year;
};

inline Date getDate(std::string date);

inline bool isPastDateValid(Date const &date);

inline bool isFutureDateValid(Date const &date);

inline int numberOfDaysInMonth(int month, int year);

inline bool isDateValid(std::string date);

inline bool isPastTheDate(Date const &date1, Date const &date2);

inline std::string dateToString(Date date);

inline bool areDatesTheSame(Date const &date1, Date const &date2);

#endif //AIRLINETICKETMANAGEMENTSYSTEM_DATE_H
