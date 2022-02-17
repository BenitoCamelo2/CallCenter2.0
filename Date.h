#ifndef PROGRAMA_DATE_H
#define PROGRAMA_DATE_H

#include <iostream>
#include <chrono>

using namespace std;

class Date {
private:
    int year, month, day;
    bool isValid(const int& y, const int& m, const int& d);
    int toInt();
public:
    Date();
    Date(const int& y, const int& m, const int& d);
    int getYear();
    int getMonth();
    int getDay();
    bool setData(const int& y, const int& m, const int& d);
    string toString();
    Date& operator = (const Date& date);
    bool operator == (Date& date);
    bool operator != (Date& date);
    bool operator < (Date& date);
    bool operator <= (Date& date);
    bool operator > (Date& date);
    bool operator >= (Date& date);
};


#endif //PROGRAMA_DATE_H
