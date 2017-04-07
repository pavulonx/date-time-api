//
// Created by rozen on 02.01.17.
//

#include <iostream>
#include <sstream>
#include "DateTime.h"
#include "DateConstants.h"


int Date::getYear() const {
    return year;

}

void Date::setYear(int year) {
    this->year = year;
}

unsigned int Date::getMonth() const {
    return month;
}

void Date::setMonth(unsigned int month) {
    if (day >= 0 && day <= 12)
        this->month = month;
}

unsigned int Date::getDay() const {
    return day;
}

void Date::setDay(unsigned int day) {
    if (day > 0 && day < (getDaysInMonth(month) + 1))
        this->day = day;
}

void Date::nextDay() {
    int daysInMonth;
    day++;
    switch (month) {
        case 4 :
        case 6 :
        case 9 :
        case 11:
            daysInMonth = 30;
            break;
        case 2 :
            if (isLapYear())
                daysInMonth = 29;
            else daysInMonth = 28;
            break;
        default:
            daysInMonth = 31;
    }
    if (day > daysInMonth) {
        day = 1;
        nextMonth();
    }
}


bool Date::isLapYear() {
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else return 0;
}

Date::Date() {
    year = 1900;
    day = month = 1;
};

Date::Date(int newYears, unsigned int newMonths = 1, unsigned int newDays = 1) {
    if (newDays != 0 && newMonths != 0 && newYears != 0) {
        year = day = month = 0;
        addDays(newDays);
        addMonths(newMonths);
        newYears > 0 ? addYears((unsigned int) newYears) : subYears((unsigned int) ((-1) * newYears));
    } else Date();
}

void Date::nextMonth() {
    if (month == 12) {
        nextYear();
        month = 1;
    } else month++;
}

void Date::nextYear() {
    if (year == -1)
        year = 1;
    else year++;
}

void Date::addDays(unsigned int daysToAdd) {
    while (daysToAdd--)
        nextDay();

}

void Date::addYears(unsigned int yearsToAdd) {
    year += yearsToAdd;
}

void Date::addMonths(unsigned int monthsToAdd) {
    while (monthsToAdd--)
        nextMonth();
}

int Date::getDaysInMonth(int monthToCheck) {
    switch (monthToCheck) {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12:
            return 31;
        case 4 :
        case 6 :
        case 9 :
        case 11:
            return 30;
        case 2 :
            if (isLapYear())
                return 29;
            else return 28;
        default:
            return -1;
    }
}

void Date::prevDay() {
    if (day == 1) {
        prevMonth();
        switch (month) {
            case 4 :
            case 6 :
            case 9 :
            case 11:
                day = 30;
                break;
            case 2 :
                if (isLapYear())
                    day = 29;
                else day = 28;
                break;
            default:
                day = 31;
        }
    } else day--;
}

void Date::prevMonth() {
    if (month == 1) {
        month = 12;
        prevYear();
    } else
        month--;
}

void Date::prevYear() {
    if (year == 1)
        year = -1;
    else year--;

}

void Date::subDays(unsigned int daysToSubtract) {
    while (daysToSubtract--)
        prevDay();
}

void Date::subMonths(unsigned int monthsToSubtract) {
    while (monthsToSubtract--)
        prevMonth();
}

void Date::subYears(unsigned int yearsToSubtract) {
    while (yearsToSubtract--)
        prevYear();
}

void Date::print() {
//    std::cout << "" << year << "-" << month << "-" << day << std::endl;
    printf("%d-%.2d-%.2d\n", year, month, day);

}

std::string Date::str() {
    char buff[11];
    snprintf(buff, 11, "%d-%.2d-%.2d", year, month, day);
    std::string toReturn(buff);
    return toReturn;
//
//    std::stringstream ss;
//    ss << "" << year << "-" << month << "-" << day;
//    return ss.str();
}

bool Date::operator==(Date otherDate) {
    return otherDate.year == year && otherDate.month == month && otherDate.day == day;
}

bool Date::operator!=(Date otherDate) {
    return !(otherDate.year == year && otherDate.month == month && otherDate.day == day);
}

bool Date::operator>=(Date otherDate) {
    if (year == otherDate.year) {
        if (month == otherDate.month) {
            return day >= otherDate.day;
        } else return month > otherDate.month;
    } else {
        return year > otherDate.year;
    }
}

bool Date::operator<=(Date otherDate) {
    if (year == otherDate.year) {
        if (month == otherDate.month) {
            return day <= otherDate.day;
        } else return month < otherDate.month;
    } else {
        return year < otherDate.year;
    }
}

bool Date::operator>(Date otherDate) {
    if (year == otherDate.year) {
        if (month == otherDate.month) {
            return day > otherDate.day;
        } else return month > otherDate.month;
    } else {
        return year > otherDate.year;
    }
}

bool Date::operator<(Date otherDate) {
    if (year == otherDate.year) {
        if (month == otherDate.month) {
            return day < otherDate.day;
        } else return month < otherDate.month;
    } else {
        return year < otherDate.year;
    }
}

Date Date::getNewDateFrom(int distanceInDays) {
    Date toReturn(*this);
    if (distanceInDays > 0)
        toReturn.addDays((unsigned int) distanceInDays);
    else
        toReturn.subDays((unsigned int) (-distanceInDays));
    return toReturn;
}

//Date Date::operator-(Date otherDate) {
//    int amountOfDays = getAmountOfDays() - otherDate.getRepresentationInDays();
//    Date tmp(1,1,1);
//    return tmp.getNewDateFrom(amountOfDays);
//}
//
//Date Date::operator+(Date otherDate) {
//    int amountOfDays = getAmountOfDays() + otherDate.getRepresentationInDays();
//    Date tmp(1,1,1);
//    return tmp.getNewDateFrom(amountOfDays);
//}

int Date::daysBetween(Date otherDate) {
    return getRepresentationInDays() - otherDate.getRepresentationInDays();
}

int Date::getRepresentationInDays() {
    Date tmp(*this);
    Date firstDayInAC(1, 1, 1);
    int toReturn = 0;
    if (tmp.year > 0)
        while (!tmp.isFirstDayInAC()) {
            tmp.prevDay();
            toReturn++;
        }
    else
        while (!tmp.isFirstDayInAC()) {
            tmp.nextDay();
            toReturn--;
        }
    return toReturn;
}

long Date::operator-(Date otherDate) {
    return getRepresentationInDays() - otherDate.getRepresentationInDays();
}

long Date::operator+(Date otherDate) {
    return getRepresentationInDays() + otherDate.getRepresentationInDays();
}

bool Date::isFirstDayInAC() {
    return (year == 1 && month == 1 && day == 1);
}


TimeStamp::TimeStamp(int newYears, unsigned int newMonths, unsigned int newDays, unsigned int newHours,
                     unsigned int newMinutes)
        : Date::Date(newYears, newMonths, newDays) {
    hour = minute = 0;
    addMinutes(newMinutes);
    addHours(newHours);
}

TimeStamp::TimeStamp() : Date::Date() {
    hour = minute = 0;
}

void TimeStamp::addMinutes(unsigned int minutesToAdd) {
    while (minutesToAdd--)
        nextMinute();
}

void TimeStamp::addHours(unsigned int minutesToAdd) {
    while (minutesToAdd--)
        nextHour();
}

void TimeStamp::subMinutes(unsigned int minutesToAdd) {
    while (minutesToAdd--)
        prevMinute();
}

void TimeStamp::subHours(unsigned int minutesToAdd) {
    while (minutesToAdd--)
        prevHour();
}

void TimeStamp::nextMinute() {
    if (minute < 59)
        minute++;
    else {
        nextHour();
        minute = 0;
    }
}

void TimeStamp::nextHour() {
    if (hour < 23)
        hour++;
    else {
        nextDay();
        hour = 0;
    }
}

void TimeStamp::prevMinute() {
    if (minute > 0)
        minute--;
    else {
        prevHour();
        minute = 59;
    }
}

void TimeStamp::prevHour() {
    if (hour > 0)
        hour--;
    else {
        prevDay();
        hour = 23;
    }
}

long TimeStamp::minutesBetween(TimeStamp otherTimeStamp) {
    return getRepresentationInMinutes() - otherTimeStamp.getRepresentationInMinutes();
}

long TimeStamp::getRepresentationInMinutes() {
    long toReturn = getRepresentationInDays();
    toReturn *= 60 * 24;
    toReturn += 60 * hour + minute;
    return toReturn;
}

long TimeStamp::operator-(TimeStamp otherTimeStamp) {
    return getRepresentationInMinutes() - otherTimeStamp.getRepresentationInMinutes();
}

long TimeStamp::operator+(TimeStamp otherTimeStamp) {
    return getRepresentationInMinutes() + otherTimeStamp.getRepresentationInMinutes();
}

bool TimeStamp::operator==(TimeStamp otherTimeStamp) {
    return otherTimeStamp.year == year && otherTimeStamp.month == month && otherTimeStamp.day == day
           && otherTimeStamp.hour == hour && otherTimeStamp.minute == minute;
}

bool TimeStamp::operator!=(TimeStamp otherTimeStamp) {
    return !(otherTimeStamp.year == year && otherTimeStamp.month == month && otherTimeStamp.day == day
             && otherTimeStamp.hour == hour && otherTimeStamp.minute == minute);
}

bool TimeStamp::operator>=(TimeStamp otherTimeStamp) {
    if (year == otherTimeStamp.year) {
        if (month == otherTimeStamp.month) {
            if (day == otherTimeStamp.day) {
                if (hour == otherTimeStamp.hour) {
                    return minute >= otherTimeStamp.minute;
                } else return hour > otherTimeStamp.hour;
            } else return day > otherTimeStamp.day;
        } else return month > otherTimeStamp.month;
    } else {
        return year > otherTimeStamp.year;
    }
}

bool TimeStamp::operator<=(TimeStamp otherTimeStamp) {
    if (year == otherTimeStamp.year) {
        if (month == otherTimeStamp.month) {
            if (day == otherTimeStamp.day) {
                if (hour == otherTimeStamp.hour) {
                    return minute <= otherTimeStamp.minute;
                } else return hour < otherTimeStamp.hour;
            } else return day < otherTimeStamp.day;
        } else return month < otherTimeStamp.month;
    } else {
        return year < otherTimeStamp.year;
    }
}

bool TimeStamp::operator>(TimeStamp otherTimeStamp) {
    if (year == otherTimeStamp.year) {
        if (month == otherTimeStamp.month) {
            if (day == otherTimeStamp.day) {
                if (hour == otherTimeStamp.hour) {
                    return minute > otherTimeStamp.minute;
                } else return hour > otherTimeStamp.hour;
            } else return day > otherTimeStamp.day;
        } else return month > otherTimeStamp.month;
    } else {
        return year > otherTimeStamp.year;
    }
}

bool TimeStamp::operator<(TimeStamp otherTimeStamp) {
    if (year == otherTimeStamp.year) {
        if (month == otherTimeStamp.month) {
            if (day == otherTimeStamp.day) {
                if (hour == otherTimeStamp.hour) {
                    return minute < otherTimeStamp.minute;
                } else return hour < otherTimeStamp.hour;
            } else return day < otherTimeStamp.day;
        } else return month < otherTimeStamp.month;
    } else {
        return year < otherTimeStamp.year;
    }
}

void TimeStamp::print() {
    printf("%d-%.2d-%.2d|%.2d:%.2d\n", year, month, day, hour, minute);
}

std::string TimeStamp::str() {
    char buff[17];
    snprintf(buff, 17, "%d-%.2d-%.2d|%.2d:%.2d", year, month, day, hour, minute);
    std::string toReturn(buff);
    return toReturn;
//
//    std::stringstream ss;
//    ss << "" << year << "-" << month << "-" << day <<"|" << hour<< ":" << minute;
//    return ss.str();
}

TimeStamp TimeStamp::getNewTimeStampFrom(int distanceInMinutes) {
    TimeStamp toReturn(*this);
    if (distanceInMinutes > 0)
        toReturn.addMinutes((unsigned int) distanceInMinutes);
    else
        toReturn.subMinutes((unsigned int) (-distanceInMinutes));
    return toReturn;
}

unsigned int TimeStamp::getMinute() const {
    return minute;
}

void TimeStamp::setMinute(unsigned int newMinute) {
    if (0 <= newMinute && newMinute <= 59)
        TimeStamp::minute = newMinute;
}

unsigned int TimeStamp::getHour() const {
    return hour;
}

void TimeStamp::setHour(unsigned int newHour) {
    if (0 <= newHour && newHour <= 23)
        TimeStamp::hour = newHour;
}

std::string TimeStamp::toString(std::string formatting) {
    for (int i = 0; i < formatting.length(); ++i) {
        char currentChar = formatting[i];
        if (currentChar == 'Y' || currentChar == 'y') {
            int j = i + 1;
            bool isGoodChar = true;
            while (j < i + 4 && j < formatting.length() && isGoodChar) {
                char tmpChar = formatting[j];
                isGoodChar = (currentChar == tmpChar);
                j++;
            }
            if (j==i+4){
                char buff[5];
                snprintf(buff, 5, "%.4d", year);
                for (int l = 0; l < 4; ++l) {
                    formatting[l+i] = buff[l];
                }
                i+=4;
            }
        }
        if (currentChar == 'M') {
            int j = i + 1;
            bool isGoodChar = true;
            while (j < i + 2 && j < formatting.length() && isGoodChar) {
                char tmpChar = formatting[j];
                isGoodChar = (currentChar == tmpChar);
                j++;
            }
            if (j==i+2){
                char buff[3];
                snprintf(buff, 3, "%.2d", month);
                for (int l = 0; l < 2; ++l) {
                    formatting[l+i] = buff[l];
                }
                i+=2;
            }
        }
        if (currentChar == 'H') {
            int j = i + 1;
            bool isGoodChar = true;
            while (j < i + 2 && j < formatting.length() && isGoodChar) {
                char tmpChar = formatting[j];
                isGoodChar = (currentChar == tmpChar);
                j++;
            }
            if (j==i+2){
                char buff[3];
                snprintf(buff, 3, "%.2d", hour);
                for (int l = 0; l < 2; ++l) {
                    formatting[l+i] = buff[l];
                }
                i+=2;
            }
        }
        if (currentChar == 'h') {
            int j = i + 1;
            bool isGoodChar = true;
            while (j < i + 2 && j < formatting.length() && isGoodChar) {
                char tmpChar = formatting[j];
                isGoodChar = (currentChar == tmpChar);
                j++;
            }
            if (j==i+2){
                char buff[3];
                snprintf(buff, 3, "%.2d", hour%12);
                for (int l = 0; l < 2; ++l) {
                    formatting[l+i] = buff[l];
                }
                i+=2;
            }
        }
        if (currentChar == 'm') {
            int j = i + 1;
            bool isGoodChar = true;
            while (j < i + 2 && j < formatting.length() && isGoodChar) {
                char tmpChar = formatting[j];
                isGoodChar = (currentChar == tmpChar);
                j++;
            }
            if (j==i+2){
                char buff[3];
                snprintf(buff, 3, "%.2d", minute);
                for (int l = 0; l < 2; ++l) {
                    formatting[l+i] = buff[l];
                }
                i+=2;
            }
        }
    }
    return formatting;
}
