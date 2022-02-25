#include "ClientList.h"
#include "util.h"

//Entregable 4

bool ClientList::isValidPos(ClientNode *clientNode) {
    ClientNode* temp(header);

    while(temp != nullptr){
        if(temp == clientNode){
            return true;
        }
        temp = getNextPos(temp);
    }
    return false;
}

ClientList::ClientList() :header(nullptr) { }

ClientList::~ClientList() {
    delete header;
}

bool ClientList::isEmpty() {
    return header == nullptr;
}

string ClientList::toString() {
    ClientNode* temp(header);
    string result;

    while(temp != nullptr){
        result += temp->getData().toString();
        result += "\n";

        temp = getNextPos(temp);
    }
    return result;
}

void ClientList::insertData(ClientNode *clientNode, const Client &client) {
    if(clientNode != nullptr && !isValidPos(clientNode)){
        throw ListException("Posicion invalida, tratando de insertar");
    }

    ClientNode* newOne(new ClientNode(client));

    if(newOne == nullptr){
        throw ListException("Memoria no disponible, tratando de insertar");
    }

    if(clientNode == nullptr){
        newOne->setNext(header);
        header = newOne;
    } else {
        newOne->setNext(clientNode->getNext());
        clientNode->setNext(newOne);
    }
}

void ClientList::insertOrdered(Client& client){
    ClientNode* aux(header);
    ClientNode* temp(nullptr);

    while(aux != nullptr && client > aux->getData()){
        temp = aux;
        aux = getNextPos(aux);
    }
    insertData(temp, client);
}

//Entregable 5

void ClientList::deleteData(ClientNode *clientNode) {
    ClientNode* temp;
    ClientNode* trail;

    temp = header;
    trail = nullptr;
    if(temp != nullptr && temp == clientNode){
        delete temp;
        header = new ClientNode();
    } else {
        while(temp != nullptr){
            if(temp == clientNode){
                trail->setNext(getNextPos(temp));
                temp = nullptr;
            } else {
                trail = temp;
                temp = getNextPos(temp);
            }
        }
        delete temp;
    }
}

void ClientList::showAllData() {
    ClientNode* temp(header);
    ClientNode* last = getLastPos();
    if(temp == last){
        showData(temp);
    } else {
        while(temp != nullptr){
            showData(temp);
            temp = getNextPos(temp);
        }
    }

}

void ClientList::showData(ClientNode *clientNode) {
    ClientNode* temp;
    ClientNode* last;

    last = getLastPos();
    temp = header;
    if(temp == last){
        if(temp == clientNode){
            cout << "|" << temp->getData().getPhoneNumber();
            cout.width(20 - countDigits(temp->getData().getPhoneNumber()));
            cout << "|" << temp->getData().getCallDate().toString();
            cout.width(20 - temp->getData().getCallDate().toString().length());
            cout << "|" << temp->getData().getCallStart().toString();
            cout.width(23 - temp->getData().getCallStart().toString().length());
            cout << "|" << temp->getData().getCallDuration().toString();
            cout.width(20 - temp->getData().getCallDuration().toString().length());
            cout << "|" << endl;
        }
    } else {
        while(temp != nullptr){
            if(temp == clientNode){
                cout << "|" << temp->getData().getPhoneNumber();
                cout.width(20 - countDigits(temp->getData().getPhoneNumber()));
                cout << "|" << temp->getData().getCallDate().toString();
                cout.width(20 - temp->getData().getCallDate().toString().length());
                cout << "|" << temp->getData().getCallStart().toString();
                cout.width(23 - temp->getData().getCallStart().toString().length());
                cout << "|" << temp->getData().getCallDuration().toString();
                cout.width(20 - temp->getData().getCallDuration().toString().length());
                cout << "|" << endl;
            }
            temp = getNextPos(temp);
        }
    }
}

void ClientList::copyAll(const ClientList &clientList) {
    ClientNode* temp1;
    ClientNode* temp2;
    temp1 = clientList.header;
    header = temp1;
    if(!isEmpty()){
        temp2 = header;
        while(temp1 != nullptr){
            temp1 = getNextPos(temp1);
            temp2->setNext(temp1);
            temp2 = getNextPos(temp2);
        }
    } else {
        delete header;
    }
}

ClientNode *ClientList::getFirstPos() {
    if(!isEmpty()){
        return header;
    }
}

ClientNode *ClientList::getLastPos() {
    ClientNode* temp;
    temp = header;
    if(!isEmpty()){
        if(getNextPos(temp) == nullptr){
            return temp;
        } else {
            while(temp != nullptr){
                if(getNextPos(temp) == nullptr){
                    return temp;
                } else {
                    temp = getNextPos(temp);
                }
            }
        }
    }
}

ClientNode *ClientList::getNextPos(ClientNode* clientNode) {
    return clientNode->getNext();
}

ClientNode *ClientList::retrievePos(Client& client, int searchBy) {
    ClientNode* temp;
    ClientNode* last;

    last = getLastPos();
    temp = header;
    switch(searchBy){
        case 1:{
            if(temp == last){
                if(temp->getData().getPhoneNumber() == client.getPhoneNumber()){
                    return temp;
                } else {
                    return nullptr;
                }
            } else {
                do{
                    if(temp->getData().getPhoneNumber() == client.getPhoneNumber()){
                        return temp;
                    }
                    temp = getNextPos(temp);
                }while(temp != nullptr);
            }
            return nullptr;
        }
        case 2:{
            Date tempDate = client.getCallDate();
            if(temp == last){
                if(temp->getData().getCallDate().operator==(tempDate)){
                    return temp;
                } else {
                    return nullptr;
                }
            } else {
                do{
                    if(temp->getData().getCallDate().operator==(tempDate)){
                        return temp;
                    }
                    temp = getNextPos(temp);
                }while(temp != nullptr);
            }
            return nullptr;
        }
        case 3:{
            Time callStart = client.getCallStart();
            if(temp == last){
                if(temp->getData().getCallStart().operator==(callStart)){
                    return temp;
                } else {
                    return nullptr;
                }
            } else {
                do{
                    if(temp->getData().getCallStart().operator==(callStart)){
                        return temp;
                    }
                    temp = getNextPos(temp);
                }while(temp != nullptr);
            }
            return nullptr;
        }
        case 4:{
            Time callDuration = client.getCallDuration();
            if(temp == last){
                if(temp->getData().getCallDuration().operator==(callDuration)){
                    return temp;
                } else {
                    return nullptr;
                }
            } else {
                do{
                    if(temp->getData().getCallDuration().operator==(callDuration)){
                        return temp;
                    }
                    temp = getNextPos(temp);
                }while(temp != nullptr);
            }
            return nullptr;
        }
        default: {
            cout << "Presiona enter para continuar..." << endl;
            getchar();
            break;
        }
    }

}

Client ClientList::findData(ClientNode *clientNode) {
    ClientNode* temp;
    ClientNode* last;

    last = getLastPos();
    temp = header;

    Client tempClient = Client();
    tempClient.setPhoneNumber(0);

    if(temp == last){
        if(temp == clientNode){
            return temp->getData();
        } else {
            return tempClient;
        }
    } else {
        while(temp != nullptr){
            if(temp == clientNode){
                return temp->getData();
            }
            temp = getNextPos(temp);
        }
    }
    return tempClient;
}

void ClientList::deleteAll() {
    ClientNode* temp;
    ClientNode* trail;
    ClientNode* last;

    last = getLastPos();
    temp = header;
    trail = nullptr;
    if(temp == last){
        delete temp;
        header = new ClientNode();
    } else {
        while(temp != nullptr){
            trail = temp;
            temp = getNextPos(temp);
            delete trail;
        }
        delete temp;
    }
}

void ClientList::writeToDisk(const string data) {
}

string ClientList::readFromDisk() {
    return 0;
}
