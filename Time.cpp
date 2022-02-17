#include "Time.h"

bool Time::isValid(const int &h, const int &m) {
    return h < 24 && h >= 0 && m < 60 && m >= 0;
}

int Time::toInt() const {
    return hour * 100 + minute;
}

Time::Time() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
}

Time::Time(const int &h, const int &m) :Time(){
    if(isValid(h, m)) {
        hour = h;
        minute = m;
    }
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

void Time::setData(const int &h, const int &m) {
    hour = h;
    minute = m;
}

string Time::toString() {
    return to_string(hour * 100 + minute);
}

Time &Time::operator = (const Time &t) {
    hour = t.hour;
    minute = t.minute;

    return *this;
}

bool Time::operator == (const Time &t) const {
    return toInt() == t.toInt();
}

bool Time::operator != (const Time &t) const {
    return toInt() != t.toInt();
}

bool Time::operator < (const Time &t) const {
    return toInt() < t.toInt();
}

bool Time::operator <= (const Time &t) const {
    return toInt() <= t.toInt();
}

bool Time::operator > (const Time &t) const {
    return toInt() > t.toInt();
}

bool Time::operator >= (const Time &t) const {
    return toInt() >= t.toInt();
}
