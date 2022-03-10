#include "AgentList.h"
#include "ListException.h"
#include "AgentMenu.h"
#include "util.h"

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

    newOne->setNext(header);
    newOne->setPrev(nullptr);

    if((header)!=nullptr){
        header->setPrev(newOne);
    }
    header = newOne;
}

void AgentList::deleteData(AgentNode *agentNode) {
    AgentNode* temp(header);

    //if the agent wasn't found
    if(agentNode == nullptr){
        cout << "No existe el agente" << endl;
        return;
    //no elements in the list
    } else if(temp == nullptr){
        cout << "No hay agentes en la lista" << endl;
        return;
    }
    //if the element is the header
    if(temp == agentNode){
        header = header->getNext();
        free(agentNode);
        return;
    }
    //if the element is the last in the list
    if(agentNode == getLastPos()){
        temp = agentNode;
        temp = temp->getPrev();
        temp->setNext(nullptr);
        free(agentNode);
        return;
    }
    //while can be removed here probably, but if the node is corrupt it will mess up the list
    if(agentNode != header && agentNode != getLastPos()) {
        while (temp != agentNode) {
            temp = getNextPos(temp);
        }
        if (temp == agentNode) {
            temp->getNext()->setPrev(temp->getPrev());
            temp->getPrev()->setNext(temp->getNext());
            free(agentNode);
        }
    }


}

void AgentList::showData(AgentNode *agentNode) {
    AgentNode* temp;
    AgentNode* last;

    last = getLastPos();
    temp = header;
    //makes sure there are elements in the list, if not it doesn't print anything, because it can crash
    //if there aren't any elements
    if(temp == nullptr){
        return;
    }
    //one element in the list
    if(temp == last){
        if(temp == agentNode){
            cout << "|" << temp->getData().getName().toString();
            cout.width(20 - temp->getData().getName().toString().size());
            cout << "|" << temp->getData().getCode();
            cout.width(20 - temp->getData().getCode().size());
            cout << "|" << temp->getData().getSpecialty();
            cout.width(20 - countDigits(temp->getData().getSpecialty()));
            cout << "|" << temp->getData().getStartTime().toString();
            cout << " - " << temp->getData().getEndTime().toString();
            cout.width(20 - temp->getData().getStartTime().toString().size() + temp->getData().getEndTime().toString().size());
            cout << "|" << temp->getData().getExtraHours();
            cout.width(20 - countDigits(temp->getData().getExtraHours()));
            cout << "|" << endl;
        }
    //multiple elements in the list
    } else {
        while(temp != nullptr){
            if(temp == agentNode){
                cout << "|" << temp->getData().getName().toString();
                cout.width(20 - temp->getData().getName().toString().size());
                cout << "|" << temp->getData().getCode();
                cout.width(20 - temp->getData().getCode().size());
                cout << "|" << temp->getData().getSpecialty();
                cout.width(20 - countDigits(temp->getData().getSpecialty()));
                cout << "|" << temp->getData().getStartTime().toString();
                cout << " - " << temp->getData().getEndTime().toString();
                cout << "|" << temp->getData().getExtraHours();
                cout.width(13 - countDigits(temp->getData().getExtraHours()));
                cout << "|" << endl;
            }
            temp = getNextPos(temp);
        }
    }
}

void AgentList::showAllData() {
    AgentNode* temp(header);
    AgentNode* last(getLastPos());

    cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
    if(temp == last){
        showData(temp);
    } else {
        //quite inneficient, i could always just duplicate the code in show data, but it loops in a while
        //it is inefficient because im looping here
        while(temp != nullptr){
            showData(temp);
            temp = getNextPos(temp);
        }
    }
}

AgentNode *AgentList::getFirstPos() {
    if(!isEmpty()){
        return header;
    } else {
        return nullptr;
    }
}

AgentNode *AgentList::getLastPos() {
    if(!isEmpty()) {
        AgentNode *temp;
        temp = header;
        while (temp != nullptr) {
            if(getNextPos(temp) == nullptr){
                return temp;
            } else {
                temp = getNextPos(temp);
            }
        }

    } else {
        return nullptr;
    }
}

AgentNode *AgentList::getPrevPos(AgentNode* agentNode) {
    return agentNode->getPrev();
}

AgentNode *AgentList::getNextPos(AgentNode* agentNode) {
    return agentNode->getNext();
}

AgentNode *AgentList::findData(Agent &agent, int option) {
    AgentNode* temp(header);

    switch(option){
        case SEARCH_CODE : {
            while(temp != nullptr){
                if(temp->getData() == agent){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        case SEARCH_LAST_NAME: {
            while(temp != nullptr){
                if(temp->getData().getName().getLastName() == agent.getName().getLastName()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        case SEARCH_HOUR_START: {
            while(temp != nullptr){
                if(temp->getData().getStartTime().getHour() == agent.getStartTime().getHour()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        case SEARCH_HOUR_END: {
            while(temp != nullptr){
                if(temp->getData().getEndTime().getHour() == agent.getEndTime().getHour()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        case SEARCH_EXTENSION: {
            while(temp != nullptr){
                if(temp->getData().getExtension() == agent.getExtension()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        case SEARCH_SPECIALTY: {
            while(temp != nullptr){
                if(temp->getData().getSpecialty() == agent.getSpecialty()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        default: {
            cout << "Error al buscar agente" << endl;
            cin.ignore();
            cout << "Ingresa una tecla para continuar..." << endl;
            getchar();
        }
    }

}

Agent AgentList::retrieve(AgentNode *agentNode) {
    AgentNode* temp(header);
    while(temp != nullptr){
        if(temp == agentNode){
            return temp->getData();
        } else {
            temp = getNextPos(temp);
        }
    }
    return {};
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
    AgentNode* temp(header);
    AgentNode* prev;
    while(temp != nullptr){
        prev = temp;
        temp = getNextPos(temp);
        delete prev;
    }
}

void AgentList::writeToDisk(const string &data) {

}

string AgentList::readFromDisk() {
    return "";
}

/*AgentList &AgentList::operator=(const AgentList &agents) {
    return 0;
}*/
