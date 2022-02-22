#ifndef PROGRAMA_CLIENT_H
#define PROGRAMA_CLIENT_H

#include <iostream>

#include "Time.h"
#include "Date.h"

using namespace std;

class Client {
private:
    long long phoneNumber;
    Time callDuration;
    Time callStart;
    Date callDate;
public:
    Client();
    Client(const long long& phoneNumber, const Time& callStart, const Time& callDuration, const Date& callDate);
    long long getPhoneNumber();
    Time getCallStart();
    Time getCallDuration();
    Date getCallDate();
    void setData(const long long& phoneNumber, const Time& callStart, const Time& callDuration, const Date& callDate);
    void setPhoneNumber(const long long& phoneNumber);
    void setCallStart(const Time& callStart);
    void setCallDuration(const Time& callDuration);
    void setCallDate(const Date& callDate);
    string toString();
    Client& operator = (const Client& client);
    bool operator == (const Client& client);
    bool operator != (const Client& client);
    bool operator < (const Client& client);
    bool operator <= (const Client& client);
    bool operator > (const Client& client);
    bool operator >= (const Client& client);
};


#endif //PROGRAMA_CLIENT_H
