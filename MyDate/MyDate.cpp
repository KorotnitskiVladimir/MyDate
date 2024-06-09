#include "MyDate.h"
#include <iostream>
using namespace std;

MyDate::MyDate(int a, int b, int c)
{
    year = a;
    month = b;
    date = c;
}

bool MyDate::isLeap()
{
    if (year%4!=0 || (year%100==0 && year%400!=0))
        return false;
    else
        return true;
}

int* MyDate::days()
{
    int leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nonleap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->isLeap()==true)
        return leap;
    else
        return nonleap;
}

MyDate& MyDate::normalize()
{
    if (month>12)
    {
        while (month>12)
        {
            year++;
            month-=12;
        }
    }
    if (month<=0)
    {
        while (month<=0)
        {
            year--;
            month = 12-month;
        }
    }
    if (date>(days()[month-1]))
    {
        while (date>days()[month-1])
        {
            date-=days()[month-1];
            month++;
        }
    }
    if (date<=0)
    {
        while (date<=0)
        {
            month--;
            date=days()[month-1]-date;
        }
    }
    return *this;
}

void MyDate::print() const
{
    cout << date << " - " << month << " - " << year << endl; 
}

void MyDate::setYear(int a)
{
    if (a>0 && a<10000)
        year = a;
    else
        cout << "incorrect year format" << endl;
}

void MyDate::setMonth(int a)
{
    if (a>0 && a<13)
        month = a;
    else
        cout << "incorrect month format" << endl;
}

void MyDate::setDate(int a)
{
    if (a>0 && a<=days()[month-1])
        date = a;
    else
        cout << "incorrect date format" << endl;
}

int MyDate::getYear() const
{
    return year;
}

int MyDate::getMonth() const
{
    return month;
}

int MyDate::getDate() const
{
    return date;
}

MyDate& MyDate::operator++()
{
    date++;
    if (date>days()[month-1])
        normalize();
    return *this;
}

MyDate MyDate::operator++(int)
{
    MyDate t(year, month, date);
    date++;
    if (date>days()[month-1])
        normalize();
    return t;
}

MyDate& MyDate::operator--()
{
    date--;
    if (date<=0)
        normalize();
    return *this;
}

MyDate MyDate::operator--(int)
{
    MyDate t(year, month, date);
    date--;
    if (date<=0)
        normalize();
    return t;
}

MyDate& MyDate::operator+(int a)
{
    date+=a;
    if (date>days()[month-1])
        normalize();
    return *this;
}

MyDate& MyDate::operator-(int a)
{
    date-=a;
    if (date<=0)
        normalize();
    return *this;
}

MyDate& MyDate::operator+=(int a)
{
    date+=a;
    if (date>=days()[month-1])
        normalize();
    return *this;
}

MyDate& MyDate::operator-=(int a)
{
    date-=a;
    if (date<=0)
        normalize();
    return *this;
}


bool MyDate::operator>(MyDate obj)
{
    if (this->year > obj.year)
        return true;
    else if (this->year == obj.year)
    {
        if (this->month > obj.month)
            return true;
        else if (this->month == obj.month)
        {
            if (this->date > obj.date)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}


bool MyDate::operator<(MyDate& obj)
{
    if (this->year < obj.year)
        return true;
    else if (this->year == obj.year && this->month < obj.month)
        return true;
    else if (this->year == obj.year && this->month == obj.month && this->date < obj.date)
        return true;
    else
        return false;
}

bool MyDate::operator>=(MyDate& obj)
{
    if (this->year > obj.year)
        return true;
    else if (this->year == obj.year)
    {
        if (this->month > obj.month)
            return true;
        else if (this->month == obj.month)
        {
            if (this->date > obj.date)
                return true;
            else if (this->date == obj.date)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool MyDate::operator<=(MyDate& obj)
{
    if (this->year < obj.year)
        return true;
    else if (this->year == obj.year)
    {
        if (this->month < obj.month)
            return true;
        else if (this->month == obj.month)
        {
            if (this->date < obj.date)
                return true;
            else if (this->date == obj.date)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool MyDate::operator==(MyDate& obj)
{
    if ((this->year == obj.year) && (this->month == obj.month) && (this->date == obj.date))
        return true;
    else
        return false;
}

bool MyDate::operator!=(MyDate& obj)
{
    if ((this->year != obj.year) || (this->month != obj.month) || (this->date != obj.date))
        return true;
    else
        return false;
}



