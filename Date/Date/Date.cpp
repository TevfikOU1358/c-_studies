#include "Date.h"



int Date::get_month_day()const {
    return this->day_;
}

int Date::get_month()const {
    return this->month_;
}

int Date::get_year()const {
    return this->year_;
}

int Date::get_year_day()const {
    return this->month_ * 30 + this->day_;
}


Date& Date::set_month_day(int day) {
    day_ = day;
    return *this;
}

Date& Date::set_month(int month) {
    month_ = month;
    return *this;
}

Date& Date::set_year(int year) {
    year_ = year;
    return *this;
}

Date& Date::set(int day, int month, int year) {
    day_ = day;
    month_ = month;
    year_ = year;
    return *this;
}

Date::Weekday Date::get_week_day()const {
    return this->wd;
}

bool Date::valid() const {

    if (year_ < 0) return false;
    if (month_ > 12 || month_ < 1) return false;
    if (day_ > 31 || day_ < 1) return false;
    if ((day_ == 31 && (month_ == 2 || month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)))
        return false;
    if (day_ == 30 && month_ == 2) return false;
    if (year_ < 2000) {
        if ((day_ == 29 && month_ == 2) && !((year_ - 1990) % 4 == 0)) return false;
    };
    if (year_ > 2000) {
        if ((day_ == 29 && month_ == 2) && !((year_ - 2000) % 4 == 0)) return false;
    };
    return true;
}





Date& Date::operator+=(int day) {
    if (this->day_ + day <= 30) this->day_ += day;
    else {
        int m_ = (day / 30) + 1;
        int d_ = day % 30;
        this->day_ = this->day_ + d_ - 30;
        if (this->month_ + m_ <= 12) this->month_ += m_;
        else {
            int y_ = (m_ / 12) + 1;
            int month = (m_ % 12);
            this->month_ = this->month_ + month - 12;
            this->year_ += y_;

        }
    }
    return *this;
}


Date Date::operator-(int day) {
    if (this->day_ - day > 0) this->day_ -= day;
    else {
        int m_ = (day / 30) + 1;
        int d_ = day % 30;
        this->day_ = this->day_ - d_ + 30;
        if (this->month_ - m_ > 0) this->month_ -= m_;
        else {
            int y_ = (m_ / 12) + 1;
            int month = (m_ % 12);
            this->month_ = this->month_ - month + 12;
            this->year_ -= y_;
        }
    }
    return *this;
}



Date& Date::operator+=(int day) {
    if (this->day_ + day <= 30) this->day_ += day;
    else {
        int m_ = (day / 30) + 1;
        int d_ = day % 30;
        this->day_ = this->day_ + d_ - 30;
        if (this->month_ + m_ <= 12) this->month_ += m_;
        else {
            int y_ = (m_ / 12) + 1;
            int month = (m_ % 12);
            this->month_ = this->month_ + month - 12;
            this->year_ += y_;

        }
    }
    return *this;
}

Date& Date::operator-=(int day) {
    if (this->day_ - day > 0) this->day_ -= day;
    else {
        int m_ = (day / 30) + 1;
        int d_ = day % 30;
        this->day_ = this->day_ - d_ + 30;
        if (this->month_ - m_ > 0) this->month_ -= m_;
        else {
            int y_ = (m_ / 12) + 1;
            int month = (m_ % 12);
            this->month_ = this->month_ - month + 12;
            this->year_ -= y_;
        }
    }
    return *this;
}

Date& Date::operator++()
{
    this->day_ += 1;
    if (this->day_ > 30) {
        this->day_ = 1;
        if (this->month_ == 12) {
            this->month_ = 1;
            this->year_ += 1;
        }
        else    this->month_ += 1;
    }
    return *this;
}

Date Date::operator++(int)
{
    Date tempDate = *this;
    ++* this;
    return tempDate;
}


Date& Date::operator--()
{
    if (this->day_ - 1 > 0) this->day_ -= 1;
    else {
        this->day_ = 30;
        if (this->month_ - 1 > 0) this->month_ -= 1;
        else {
            this->month_ = 12;
            this->year_ -= 1;
        }
    }
    return *this;
}

Date Date::operator--(int)
{
    Date tempDate = *this;
    --* this;
    return tempDate;
}



bool operator<(Date& d1, Date& d2) {
    if (!d1.valid()) return false;
    if (!d2.valid()) return false;
    if (d1.year_ < d2.year_) return true;
    else if (d1.year_ > d2.year_) return false;
    else {
        if (d1.month_ < d2.month_) return true;
        else if (d1.month_ > d2.month_) return false;
        else {
            if (d1.day_ < d2.day_) return true;
            else  return false;
        }
    }
}


bool operator<=(Date& d1, Date& d2) {
    if (!d1.valid()) return false;
    if (!d2.valid()) return false;
    if (d1.year_ < d2.year_) return true;
    else if (d1.year_ > d2.year_) return false;
    else {
        if (d1.month_ < d2.month_) return true;
        else if (d1.month_ > d2.month_) return false;
        else {
            if (d1.day_ <= d2.day_) return true;
            else  return false;
        }
    }
}


bool operator>(Date& d1, Date& d2) {
    if (!d1.valid()) return false;
    if (!d2.valid()) return false;
    if (d1.year_ < d2.year_) return false;
    else if (d1.year_ > d2.year_) return true;
    else {
        if (d1.month_ < d2.month_) return false;
        else if (d1.month_ > d2.month_) return true;
        else {
            if (d1.day_ <= d2.day_) return false;
            else  return true;
        }
    }
}

bool operator>=(Date& d1, Date& d2) {
    if (!d1.valid()) return false;
    if (!d2.valid()) return false;
    if (d1.year_ < d2.year_) return false;
    else if (d1.year_ > d2.year_) return true;
    else {
        if (d1.month_ < d2.month_) return false;
        else if (d1.month_ > d2.month_) return true;
        else {
            if (d1.day_ < d2.day_) return false;
            else  return true;
        }
    }
}

bool operator==(Date& d1, Date& d2) {
    if (!d1.valid()) return false;
    if (!d2.valid()) return false;
    if ((d1.day_ == d2.day_) && (d1.month_ == d2.month_) && (d1.year_ == d2.year_)) return true;
    else return false;
}


bool operator!=(Date& d1, Date& d2) {

    return !(d1 == d2);
}

int operator-(const Date& d1, const Date& d2) {
    return ((d1.year_ -1990) * 365 + (d1.month_ * 30) + d1.day_) - ((d2.year_ - 1990) * 365 + (d2.month_ * 30) + d2.day_);
}

Date operator+(int n, const Date& d)
{
    Date d1;
    int number_of_day = ((d.year_ - 1990) * 365 + ((d.month_ - 1) * 30) + d1.day_ + n);
    d1.year_ = 1990 + number_of_day / 365;
    d1.month_ = ((number_of_day - ((d1.year_ - 1990) * 365)) / 30) + 1;
    d1.day_ = number_of_day % 30;
    return d1;
}

Date operator+(const Date& d, int n)
{
    Date d1;
    int number_of_day = ((d.year_ - 1990) * 365 + (d.month_ * 30) + d1.day_ + n);
    d1.year_ = 1990 + number_of_day / 365;
    d1.month_ = (number_of_day - ((d1.year_ - 1990) * 365)) / 30;
    d1.day_ = number_of_day % 30;
    return d1;
}


Date::Weekday& operator++(Date::Weekday& r)
{
    if (r == Date::Weekday::Sunday) return r = Date::Weekday::Monday;
    else    return  r = static_cast<Date::Weekday>(static_cast<int>(r) + 1);
}

Date::Weekday operator++(Date::Weekday& r, int)
{
    Date::Weekday& temp_wd = r;
    ++r;
    return temp_wd;
}

Date::Weekday& operator--(Date::Weekday& r)
{
    if (r == Date::Weekday::Monday) return r = Date::Weekday::Sunday;
    else    return  r = static_cast<Date::Weekday>(static_cast<int>(r) - 1);
}

Date::Weekday operator--(Date::Weekday& r, int)
{
    Date::Weekday& temp_wd = r;
    --r;
    return temp_wd;
}

std::ostream& operator<<(std::ostream& out, Date& date) {
    out << "Date:" << date.day_ << "/" << date.month_ << "/" << date.year_ << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Date& date) {
    cout << "Day:";
    in >> date.day_;
    cout << "Month:";
    in >> date.month_;
    cout << "Year:";
    in >> date.year_;

    return in;
}