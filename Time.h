#ifndef PROGRAMA_TIME_H
#define PROGRAMA_TIME_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Time {
private:
    int hour, minute;
    bool isValid(const int& h, const int& m);
public:
    Time();
    Time(const int& h, const int& m);
    int toInt() const;
    int getHour();
    int getMinute();
    void setData(const int& hour, const int& minute);
    string toString();
    Time& operator = (const Time& t);
    bool operator == (const Time& t) const;
    bool operator != (const Time& t) const;
    bool operator < (const Time& t) const;
    bool operator <= (const Time& t) const;
    bool operator > (const Time& t) const;
    bool operator >= (const Time& t) const;
};


#endif //PROGRAMA_TIME_H
