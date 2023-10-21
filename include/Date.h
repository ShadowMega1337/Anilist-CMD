//
// Created by user on 9/27/2023.
//

#ifndef M323_LB3_DATE_H
#define M323_LB3_DATE_H


class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();

    Date(int day, int month, int year);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);
};


#endif //M323_LB3_DATE_H
