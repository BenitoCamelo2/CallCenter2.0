#include "AgentList.h"
#include "ListException.h"

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

AgentList::AgentList() : header(nullptr){}

AgentList::~AgentList() {
    delete header;
}

bool AgentList::isEmpty() {
    return header == nullptr;
}

void AgentList::insertData(AgentNode *agentNode, const Agent &tempAgent) {
    if(agentNode != nullptr && !isValidPos(agentNode)){
        throw ListException("Posicion invalida, tratando de insertar");
    }

    if(agentNode == nullptr){
        agentNode = header;
    }

    AgentNode* newOne(new AgentNode(tempAgent));

    if(newOne == nullptr){
        throw ListException("Memoria no disponible, tratando de insertar");
    }

    newOne->setPrev(agentNode);
    newOne->setNext(agentNode->getNext());

    agentNode->getNext()->setPrev(newOne);
    agentNode->setNext(newOne);
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
    AgentNode* temp(header);
    string result;

    while(temp != nullptr){
        result += temp->getData().toString();
        result += "\n";

        temp = getNextPos(temp);
    }
    return result;
}

void AgentList::deleteAll() {

}

void AgentList::writeToDisk(const string &data) {

}

string AgentList::readFromDisk() {
    return "";
}

/*AgentList &AgentList::operator=(const AgentList &agents) {
    return 0;
}*/
