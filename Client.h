#ifndef PROGRAMA_CLIENT_H
#define PROGRAMA_CLIENT_H

#include <iostream>

#include "Time.h"
#include "Date.h"

using namespace std;

class Client {
private:
    int phoneNumber;
    Time callDuration;
    Time callStart;
    Date callDate;
public:
    Client();
    Client(const int& phoneNumber, const Time& callStart, const Time& callDuration, const Date& callDate);
    int getPhoneNumber();
    Time getCallStart();
    Time getCallDuration();
    Date getCallDate();
    void setData(const int& phoneNumber, const Time& callStart, const Time& callDuration, const Date& callDate);
    void setPhoneNumber(const int& phoneNumber);
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
