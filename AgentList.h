#ifndef PROGRAMA_AGENTLIST_H
#define PROGRAMA_AGENTLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "AgentNode.h"

using namespace std;

class AgentList {
private:
    AgentNode* header;
    bool isValidPos(AgentNode* agent);
    void copyAll(const AgentList &agentList);
    AgentNode* mergeName(AgentNode* first, AgentNode* second);
    AgentNode* mergeSpecialty(AgentNode* first, AgentNode* second);
    AgentNode* mergeSort(AgentNode* head, int option);
    AgentNode* split(AgentNode* head);
public:
    //CONSTRUCTORS
    AgentList();
    ~AgentList();

    //returns if the list is empty or not
    bool isEmpty();
    //inserts data, not ordered
    void insertData(AgentNode* agentNode, const Agent& tempAgent);
    //delets data
    void deleteData(AgentNode* agentNode);
    //returns the header
    AgentNode* getFirstPos();
    //returns the last node in the list
    AgentNode* getLastPos();
    //returns the previous position in the list
    AgentNode* getPrevPos(AgentNode* agentNode);
    //returns the next position in the list
    AgentNode* getNextPos(AgentNode* agentNode);
    //finds the position of an agent, based on a search option
    AgentNode* findData(Agent& agent, int option);
    //gets the agend data based off of a position
    Agent retrieve(AgentNode* agentNode);
    //sorts
    void sortByName();
    void sortBySpecialty();
    //returns the list in string form
    string toString();
    //delets all agents
    void deleteAll();
    //read-write to disk
    void writeToDisk(const string& fileName);
    AgentList* readFromDisk();
};

enum{
    READ_CODE = 0,
    READ_NAME,
    READ_TIME_START,
    READ_TIME_END,
    READ_EXTENSION,
    READ_EXTRA_HOURS,
    READ_SPECIALTY
};

enum{
    READ_FIRST_NAME = 0,
    READ_LAST_NAME
};

enum{
    READ_HOUR_AGENT = 0,
    READ_MINUTE_AGENT
};


#endif //PROGRAMA_AGENTLIST_H
