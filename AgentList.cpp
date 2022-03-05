#include "AgentList.h"

bool AgentList::isValidPos(AgentNode *agentNode) {
    AgentNode* temp(header);

    while(temp != nullptr){
        if(temp == agentNode){
            return true;
        }
        temp = getNextPos(temp);
    }
    return false;
}

void AgentList::copyAll(const AgentList &agentList) {

}

void AgentList::swapPtr(AgentNode *agent1, AgentNode *agent2) {

}

void AgentList::sortByName(AgentNode *agent1, AgentNode *agent2) {

}

void AgentList::sortBySpecialty(AgentNode *agent1, AgentNode *agent2) {

}

AgentList::AgentList() {

}

AgentList::~AgentList() {

}

bool AgentList::isEmpty() {
    return false;
}

void AgentList::insertData(AgentNode *agentNode, const Agent &tempAgent) {

}

void AgentList::deleteData(AgentNode *agentNode) {

}

AgentNode *AgentList::getFirstPos() {
    return nullptr;
}

AgentNode *AgentList::getLastPos() {
    return nullptr;
}

AgentNode *AgentList::getPrevPos() {
    return nullptr;
}

AgentNode *AgentList::getNextPos(AgentNode* agentNode) {
    return agentNode->getNext();
}

AgentNode *AgentList::findData(const Agent &agent) {
    return nullptr;
}

Agent AgentList::retrieve(AgentNode *agentNode) {
    return Agent();
}

void AgentList::sortByName() {

}

void AgentList::sortBySpecialty() {

}

string AgentList::toString() {
    return std::__cxx11::string();
}

void AgentList::deleteAll() {

}

void AgentList::writeToDisk(const string &data) {

}

string AgentList::readFromDisk() {
    return std::__cxx11::string();
}

/*AgentList &AgentList::operator=(const AgentList &agents) {
    return 0;
}*/
