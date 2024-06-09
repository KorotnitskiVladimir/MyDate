#pragma once

class MyDate
{
private:
    int year;
    int month;
    int date;
public:
    MyDate(): year(0), month(0), date(0) {}
    explicit MyDate(int a, int b, int c);
    bool isLeap();
    int* days();
    MyDate& normalize();
    void print() const;
    void setYear(int a);
    void setMonth(int a);
    void setDate(int a);
    int getYear() const;
    int getMonth() const;
    int getDate() const;
    MyDate& operator++ ();
    MyDate operator++ (int);
    MyDate& operator-- ();
    MyDate operator-- (int);
    MyDate& operator+ (int a);
    MyDate& operator- (int a);
    MyDate& operator+= (int a);
    MyDate& operator-= (int a);
    bool operator> (MyDate obj);
    bool operator< (MyDate &obj);
    bool operator>= (MyDate &obj);
    bool operator<= (MyDate &obj);
    bool operator== (MyDate &obj);
    bool operator!= (MyDate &obj);
};


