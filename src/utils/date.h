#pragma once

#include <iostream>

class Date
{
public:
    // Date(int y = 2024, int m = 6, int d = 9)
    // {
    //     this->year = y;
    //     this->month = m;
    //     this->day = d;
    // }

    Date(int y = 2024, int m = 6, int d = 9) : year(y), month(m), day(d)
    {
    }

    Date(Date &d)
    {
        this->year = d.year;
        this->month = d.month;
        this->day = d.day;
    }

    ~Date()
    {
        std::cout << "~Date()" << std::endl;
    }

    void ShowDate()
    {
        std::cout << "year : " << this->year << std::endl;
        std::cout << "month : " << this->month << std::endl;
        std::cout << "day : " << this->day << std::endl;
    }

public:
    // 运算符重载
    bool operator<(Date &d)
    {
        if (this->year != d.year)
        {
            return this->year < d.year;
        }
        else if (this->month != d.month)
        {
            return this->month < d.month;
        }
        else
        {
            return this->day < d.day;
        }
    }

    bool operator>(Date &d)
    {
        if (this->year != d.year)
        {
            return this->year > d.year;
        }
        else if (this->month != d.month)
        {
            return this->month > d.month;
        }
        else
        {
            return this->day > d.day;
        }
    }

private:
    int year;
    int month;
    int day;
};