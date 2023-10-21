//
// Created by user on 9/27/2023.
//

#include "Date.h"

Date::Date()
{

}

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

int Date::getDay() const
{
    return day;
}

void Date::setDay(int day)
{
    Date::day = day;
}

int Date::getMonth() const
{
    return month;
}

void Date::setMonth(int month)
{
    Date::month = month;
}

int Date::getYear() const
{
    return year;
}

void Date::setYear(int year)
{
    Date::year = year;
}