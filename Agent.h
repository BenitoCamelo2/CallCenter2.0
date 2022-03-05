#ifndef PROGRAMA_AGENT_H
#define PROGRAMA_AGENT_H

#include <iostream>

#include "Name.h"
#include "Time.h"
#include "Date.h"

using namespace std;

class Agent {
private:
    string code;
    Name name;
    Time startTime;
    Time endTime;
    int extension;
    int extraHours;
    int specialty;
public:
    Agent();
    Agent(const Agent& agent);
    string getCode();
    Name getName();
    Time getStartTime();
    Time getEndTime();
    int getExtension();
    int getExtraHours();
    int getSpecialty();
    void setData(string& code, const Name& name, const Time& startTime, const Time& endTime,
                 int& extension, int& extraHours, int& specialty);
    void addExtraHours(int& extraHours);
    Agent& operator = (const Agent& agent);
    bool operator == (const Agent& agent);
    bool operator != (const Agent& agent);
    bool operator < (const Agent& agent);
    bool operator <= (const Agent& agent);
    bool operator > (const Agent& agent);
    bool operator >= (const Agent& agent);
};


#endif //PROGRAMA_AGENT_H
