#include "AgentList.h"
#include "ListException.h"
#include "AgentMenu.h"
#include "util.h"

bool AgentList::isValidPos(AgentNode *agentNode) {
    AgentNode* temp(header);

    while(temp != nullptr){
        //if agent is found the position is valid
        if(temp == agentNode){
            return true;
        }
        temp = getNextPos(temp);
    }
    //in this case the agent is not in the list
    return false;
}

void AgentList::copyAll(const AgentList &agentList) {

}

AgentNode* AgentList::mergeName(AgentNode *first, AgentNode *second) {
    if(!first){
        return second;
    }

    if(!second){
        return first;
    }

    if(first->getData().getName() < second->getData().getName()){
        first->setNext(mergeName(first->getNext(), second));
        first->getNext()->setPrev(first);
        first->setPrev(nullptr);
        return first;
    } else {
        second->setNext(mergeName(first, second->getNext()));
        second->getNext()->setPrev(second);
        second->setPrev(nullptr);
        return second;
    }
}

AgentNode* AgentList::mergeSpecialty(AgentNode *first, AgentNode *second) {
    //if list is empty
    if(!first){
        return second;
    }

    //if there is only one element
    if(!second){
        return first;
    }

    //chooses which is greater
    if(first->getData().getSpecialty() < second->getData().getSpecialty()){
        first->setNext(mergeSpecialty(first->getNext(), second));
        first->getNext()->setPrev(first);
        first->setPrev(nullptr);
        return first;
    } else {
        second->setNext(mergeSpecialty(first, second->getNext()));
        second->getNext()->setPrev(second);
        second->setPrev(nullptr);
        return second;
    }
}

AgentNode* AgentList::mergeSort(AgentNode *head, int option) {
    if(!head || !head->getNext()){
        return head;
    }
    AgentNode* second = split(head);

    //recursive for left and right halves
    head = mergeSort(head, option);
    second = mergeSort(second, option);

    //return merged halves depending on name sort or specialty sort
    if(option == SORT_NAME){
        return mergeName(head, second);
    } else if (option == SORT_SPECIALTY){
        return mergeSpecialty(head, second);
    } else {
        return nullptr;
    }
}

AgentNode* AgentList::split(AgentNode *head) {
    AgentNode* fast(head);
    AgentNode* slow(head);

    //split list in half and return middle element
    while(fast->getNext() && fast->getNext()->getNext()){
        fast = fast->getNext()->getNext();
        slow = slow->getNext();
    }
    AgentNode* temp(slow->getNext());
    slow->setNext(nullptr);
    return temp;
}

AgentList::AgentList() : header(nullptr){}

AgentList::~AgentList() {
    deleteAll();
    delete header;
}

bool AgentList::isEmpty() {
    return header == nullptr;
}

void AgentList::insertData(AgentNode *agentNode, const Agent &tempAgent) {
    //position is invalid, will try to insert
    if(agentNode != nullptr && !isValidPos(agentNode)){
        throw ListException("Posicion invalida, tratando de insertar");
    }

    //first node to add to the list
    if(agentNode == nullptr){
        agentNode = header;
    }

    //temp node using the agent in the parameter as the data
    AgentNode* newOne(new AgentNode(tempAgent));

    //no more memory
    if(newOne == nullptr){
        throw ListException("Memoria no disponible, tratando de insertar");
    }

    //setters
    newOne->setNext(header);
    newOne->setPrev(nullptr);

    //if header is not the only item in the list
    if(header!=nullptr){
        header->setPrev(newOne);
    }
    header = newOne;
}

void AgentList::deleteData(AgentNode *agentNode) {
    AgentNode* temp(header);

    //if the agent wasn't found
    if(agentNode == nullptr){
        throw ListException("No existe el agente");
        return;
    //no elements in the list
    } else if(temp == nullptr){
        throw ListException("No hay agentes en la lista");
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
    //when the node has a prev and next that are not nullptr, so in between two nodes
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
    return nullptr;
}

AgentNode *AgentList::getPrevPos(AgentNode* agentNode) {
    return agentNode->getPrev();
}

AgentNode *AgentList::getNextPos(AgentNode* agentNode) {
    return agentNode->getNext();
}

AgentNode *AgentList::findData(Agent &agent, int option) {
    AgentNode* temp(header);

    //switch for what attribute to search by
    switch(option){
        //searching by code
        case SEARCH_CODE : {
            //basic way to traverse list
            while(temp != nullptr){
                if(temp->getData() == agent){
                    //if found returns the node in the list
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            //if not found returns nullptr
            return nullptr;
        }
        //searching by name
        case SEARCH_LAST_NAME: {
            //all of the cases use the same search method
            while(temp != nullptr){
                if(temp->getData().getName().getLastName() == agent.getName().getLastName()){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
            return nullptr;
        }
        //search by shift start time
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
        //search by shift end time
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
        //search by extension
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
        //search by specialty, should improve to show all agents with the same specialty
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
        //shouldn't happen, would be unfortunate
        default: {
            ListException("Error al buscar un agente");
            cin.ignore();
            cout << "Ingresa una tecla para continuar..." << endl;
            getchar();
        }
    }
    return nullptr;
}

Agent AgentList::retrieve(AgentNode *agentNode) {
    //searches through the list
    //could use the isValidPos(), but it returns a blank agent if node is not found, so its the same thing
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
    header = mergeSort(getFirstPos(), SORT_NAME);
}

void AgentList::sortBySpecialty() {
    header = mergeSort(getFirstPos(), SORT_SPECIALTY);
}

string AgentList::toString() {
    AgentNode* temp(header);
    AgentNode* last(getLastPos());
    string result;

    while(temp != nullptr){
        result += temp->getData().toString();
        if(temp != last) {
            result += "\n";
        }

        temp = getNextPos(temp);
    }
    return result;
}

void AgentList::deleteAll() {
    //deletes all while going through the list, temp gets the next element and prev deletes the previous element
    AgentNode* temp(header);
    AgentNode* prev;
    while(temp != nullptr){
        prev = temp;
        temp = getNextPos(temp);
        delete prev;
    }
    header = nullptr;
}

void AgentList::writeToDisk(const string &fileName) {
    ofstream file;

    file.open(fileName, ios::out);
    if(!file.is_open()){
        throw ListException("No se pudo abrir el archivo");
    } else {
        file << toString();
        file.close();
        AgentNode* temp(header);

        while(temp != nullptr){
            temp->getData().getClientList()->writeToDisk(temp->getData().getCode() + ".txt");
            temp = temp->getNext();
        }
    }
}

AgentList* AgentList::readFromDisk() {
    AgentList* tempAgentList = new AgentList();
    ClientList* tempClientList = new ClientList();

    string fileName = AGENT_FILE_NAME;
    string tempLine;
    char c;
    ifstream file(fileName);

    int i=0, j=0;

    if(!file.is_open()){
        ofstream fileOpen(fileName, ios::out);
        file.close();
        return nullptr;
    }

    while(!file.eof()){
        Agent tempAgent;

        string code;
        string firstName, lastName;
        string hourStartStr, minuteStartStr, hourEndStr, minuteEndStr;
        string extensionStr;
        string extraHoursStr;
        string specialtyStr;

        Name name;

        int hourStartInt, minuteStartInt, hourEndInt, minuteEndInt;
        Time timeStart, timeEnd;

        int extensionInt;
        int extraHoursInt;
        int specialtyInt;

        int nameCounter = 0;
        int timeStartCounter = 0;
        int timeEndCounter = 0;

        j=0;

        getline(file, tempLine);
        for(i = 0; i < tempLine.length(); i++){
            c = tempLine[i];
            if(c == '|'){
                if(j == READ_SPECIALTY){
                    break;
                }
                i++;
                j++;
                c = tempLine[i];
            }
            switch(j){
                case READ_CODE: {
                    code += c;
                    break;
                }
                case READ_NAME: {
                    if(c == ' '){
                        if(nameCounter == READ_LAST_NAME){
                            break;
                        }
                        i++;
                        nameCounter++;
                        c = tempLine[i];
                    }
                    switch(nameCounter){
                        case READ_FIRST_NAME: {
                            firstName += c;
                            break;
                        }
                        case READ_LAST_NAME: {
                            lastName += c;
                            break;
                        }
                        default: {
                            throw ListException("Error al leer nombre de un agente");
                        }
                    }
                    break;
                }
                case READ_TIME_START: {
                    if(c == ':'){
                        if(timeStartCounter == READ_MINUTE_AGENT){
                            break;
                        }
                        i++;
                        timeStartCounter++;
                        c = tempLine[i];
                    }
                    switch(timeStartCounter){
                        case READ_HOUR_AGENT: {
                            hourStartStr += c;
                            break;
                        }
                        case READ_MINUTE_AGENT: {
                            minuteStartStr += c;
                            break;
                        }
                        default: {
                            throw ListException("Error al leer tiempo de un agente");
                        }
                    }
                    break;
                }
                case READ_TIME_END: {
                    if(c == ':'){
                        if(timeEndCounter == READ_MINUTE_AGENT){
                            break;
                        }
                        i++;
                        timeEndCounter++;
                        c = tempLine[i];
                    }
                    switch(timeEndCounter){
                        case READ_HOUR_AGENT: {
                            hourEndStr += c;
                            break;
                        }
                        case READ_MINUTE_AGENT: {
                            minuteEndStr += c;
                            break;
                        }
                        default: {
                            throw ListException("Error al leer tiempo de un agente");
                        }
                    }
                    break;
                }
                case READ_EXTENSION: {
                    extensionStr += c;
                    break;
                }
                case READ_EXTRA_HOURS: {
                    extraHoursStr += c;
                    break;
                }
                case READ_SPECIALTY: {
                    specialtyStr += c;
                    break;
                }
                default: {
                    throw ListException("Error al leer un agente");
                }
            }
        }

        name.setData(firstName, lastName);

        hourStartInt = atoi(hourStartStr.data());
        minuteStartInt = atoi(minuteStartStr.data());
        timeStart.setData(hourStartInt, minuteStartInt);

        hourEndInt = atoi(hourEndStr.data());
        minuteEndInt = atoi(minuteEndStr.data());
        timeEnd.setData(hourEndInt, minuteEndInt);

        extensionInt = atoi(extensionStr.data());

        extraHoursInt = atoi(extraHoursStr.data());

        specialtyInt = atoi(specialtyStr.data());

        tempAgent.setData(code, name, timeStart, timeEnd, extensionInt, extraHoursInt, specialtyInt);
        tempClientList = tempClientList->readFromDisk(code + ".txt");
        if(tempClientList == nullptr){
            tempClientList = new ClientList();
        }
        tempAgent.setClientList(tempClientList);

        tempAgentList->insertData(tempAgentList->getFirstPos(), tempAgent);
    }
    return tempAgentList;
}
