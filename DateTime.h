//
// Created by rozen on 02.01.17.
//

#ifndef ZMPODATETIME_DATE_H
#define ZMPODATETIME_DATE_H

#include <string>

class Date {

    //long days;
protected:
    int year;
    unsigned int month, day;

public:
    int getYear() const;
    void setYear(int year);
    unsigned int getMonth() const;
    void setMonth(unsigned int month);
    unsigned int getDay() const;
    void setDay(unsigned int day);

    Date(int newYears, unsigned int newMonths, unsigned int newDays);
    Date();

    Date getNewDateFrom(int distanceInDays);

    long operator-(Date otherDate);
    long operator+(Date otherDate);
    int daysBetween(Date otherDate);

    void nextDay();
    void nextMonth();
    void nextYear();

    void prevDay();
    void prevMonth();
    void prevYear();

    void addDays(unsigned int daysToAdd);
    void addMonths(unsigned int monthsToAdd);
    void addYears(unsigned int yearsToAdd);

    void subDays(unsigned int daysToSubtract);
    void subMonths(unsigned int monthsToSubtract);
    void subYears(unsigned int yearsToSubtract);

    void print();
    std::string str();

    bool operator ==(Date otherDate);
    bool operator >=(Date otherDate);
    bool operator <=(Date otherDate);
    bool operator <(Date otherDate);
    bool operator >(Date otherDate);
    bool operator !=(Date otherDate);

private:
    int getDaysInMonth(int monthToCheck);
    bool isLapYear();
    bool isFirstDayInAC();

public:
    int getRepresentationInDays();

};

class TimeStamp : public Date{

    unsigned int minute, hour;
public:
    unsigned int getMinute() const;
    void setMinute(unsigned int newMinute);
    unsigned int getHour() const;
    void setHour(unsigned int newHour);

public:
    TimeStamp(int newYears, unsigned int newMonths, unsigned int newDays, unsigned int newHours, unsigned int newMinutes);
    TimeStamp();

    void addMinutes(unsigned int minutesToAdd);;
    void addHours(unsigned int minutesToAdd);

    void subMinutes(unsigned int minutesToAdd);
    void subHours(unsigned int minutesToAdd);

    bool operator ==(TimeStamp otherTimeStamp);
    bool operator !=(TimeStamp otherTimeStamp);
    bool operator >=(TimeStamp otherTimeStamp);
    bool operator <=(TimeStamp otherTimeStamp);
    bool operator <(TimeStamp otherTimeStamp);
    bool operator >(TimeStamp otherTimeStamp);

    void nextMinute();
    void nextHour();

    void prevMinute();
    void prevHour();

    long minutesBetween(TimeStamp otherTimeStamp);
    long getRepresentationInMinutes();

    long operator-(TimeStamp otherTimeStamp);
    long operator+(TimeStamp otherTimeStamp);

    TimeStamp getNewTimeStampFrom(int distanceInMinutes);

    void print();
    std::string str();

    std::string toString(std::string formatting);


};


#endif //ZMPODATETIME_DATE_H
