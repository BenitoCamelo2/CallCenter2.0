#ifndef PROGRAMA_AGENTLIST_H
#define PROGRAMA_AGENTLIST_H

#include <iostream>
#include "AgentNode.h"

using namespace std;

class AgentList {
private:
    AgentNode* header;
    bool isValidPos(AgentNode* agent);
    void copyAll(const AgentList &agentList);
    void swapPtr(AgentNode* agent1, AgentNode* agent2);
    void sortByName(AgentNode* agent1, AgentNode* agent2);
    void sortBySpecialty(AgentNode* agent1, AgentNode* agent2);
public:
    AgentList();
    ~AgentList();

    bool isEmpty();
    void insertData(AgentNode* agentNode, const Agent& tempAgent);
    void deleteData(AgentNode* agentNode);
    void showData(AgentNode* agentNode);
    void showAllData();
    AgentNode* getFirstPos();
    AgentNode* getLastPos();
    AgentNode* getPrevPos(AgentNode* agentNode);
    AgentNode* getNextPos(AgentNode* agentNode);
    AgentNode* findData(const Agent& agent);
    Agent retrieve(AgentNode* agentNode);
    void sortByName();
    void sortBySpecialty();
    string toString();
    void deleteAll();
    void writeToDisk(const string& data);
    string readFromDisk();
    AgentList& operator = (const AgentList& agents);

};


#endif //PROGRAMA_AGENTLIST_H
