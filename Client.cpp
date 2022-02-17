#include "Client.h"

Client::Client() {
    phoneNumber = 0;
    callStart = Time();
    callDuration = Time();
    callDate = Date();
}

Client::Client(const int &phoneNumber, const Time &callStart, const Time &callDuration, const Date &callDate) {
    this->phoneNumber = phoneNumber;
    this->callStart = callStart;
    this->callDuration = callDuration;
    this->callDate = callDate;
}

int Client::getPhoneNumber() {
    return phoneNumber;
}

Time Client::getCallStart() {
    return callStart;
}

Time Client::getCallDuration() {
    return callDuration;
}

Date Client::getCallDate() {
    return callDate;
}

void Client::setData(const int &phoneNumber, const Time &callStart, const Time &callDuration, const Date &callDate) {
    this->phoneNumber = phoneNumber;
    this->callStart = callStart;
    this->callDuration = callDuration;
    this->callDate = callDate;
}

void Client::setPhoneNumber(const int &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string Client::toString(){
    string result;

    result = phoneNumber;
    result += " | ";
    result += callStart.toString();
    result += " | ";
    result += callDuration.toString();
    result += " | ";
    result += callDate.toString();

    return result;

}

Client &Client::operator = (const Client &client) {
    phoneNumber = client.phoneNumber;
    callStart = client.callStart;
    callDuration = client.callDuration;
    callDate = client.callDate;

    return *this;
}

bool Client::operator == (const Client &client) {
    return phoneNumber == client.phoneNumber;
}

bool Client::operator != (const Client &client) {
    return phoneNumber != client.phoneNumber;
}

bool Client::operator < (const Client &client) {
    return phoneNumber < client.phoneNumber;
}

bool Client::operator <= (const Client &client) {
    return phoneNumber <= client.phoneNumber;
}

bool Client::operator > (const Client &client) {
    return phoneNumber > client.phoneNumber;
}

bool Client::operator >= (const Client &client) {
    return phoneNumber >= client.phoneNumber;
}
