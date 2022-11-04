#pragma once
#include <iostream>
using namespace std;

class Date {
public:
    enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    Date() : day_{ 1 }, month_{ 1 }, year_{ 1990 } {

    }

    Date(const int d, const int m, const int y) : day_{ d }, month_{ m }, year_{ y } {

    }

    int get_month_day()const; //9
    int get_month()const; //10
    int get_year()const; //11
    int get_year_day()const; //12
    Weekday get_week_day()const; //13


    Date& set_month_day(int day); //14
    Date& set_month(int month); //15
    Date& set_year(int year); //16
    Date& set(int day, int mon, int year); //17
    Date operator-(int day); //18
    Date& operator+=(int day); //19
    Date& operator-=(int day); //20
    Date& operator++(); //21
    Date operator++(int); //22
    Date& operator--(); //23
    Date operator--(int); //24
    bool valid() const;

    //  Date::Weekday operator++(Date::Weekday &r, int); //30
      //Date::Weekday& operator--(Date::Weekday &r); //30
      //Date::Weekday operator--(Date::Weekday &r, int); //30}
    friend std::ostream& operator<<(std::ostream& out, Date& date); //31
    friend std::istream& operator>>(std::istream& is, Date& date);  //32

    friend bool operator==(Date& d1, Date& d2);
    friend bool operator!=(Date& d1, Date& d2);
    friend bool operator<(Date& d1, Date& d2);
    friend bool operator<=(Date& d1, Date& d2);
    friend bool operator>(Date& d1, Date& d2);
    friend bool operator>=(Date& d1, Date& d2);
    friend int operator-(const Date& d1, const Date& d2); //28
    friend Date operator+(const Date& date, int n); //29
    friend Date operator+(int n, const Date&); //29
protected:
    int day_;
    int month_;
    int year_;
public:
    Weekday wd = Weekday::Monday;

};


Date::Weekday& operator++(Date::Weekday& r); //30
Date::Weekday operator++(Date::Weekday& r, int); //30
Date::Weekday& operator--(Date::Weekday& r); //30
Date::Weekday operator--(Date::Weekday& r, int); //30}