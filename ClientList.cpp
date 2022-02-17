#include "ClientList.h"

//Entregable 4

bool ClientList::isValidPos(ClientNode *clientNode) {
    ClientNode* temp(header);

    while(temp != nullptr){
        if(temp == clientNode){
            return true;
        }
        temp = temp->getNext();
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

        temp = temp->getNext();
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
        aux = aux->getNext();
    }
    insertData(temp, client);
}

//-------------------

void ClientList::deleteData(ClientNode *clientNode) {
    ClientNode* temp;
    ClientNode* trail;

    temp = header;
    trail = nullptr;
    if(temp->getNext() == nullptr){
        if(temp == clientNode){
            delete temp;
            header = new ClientNode();
        }
    } else {
        while(temp != nullptr && temp != clientNode){
            trail = temp;
            temp = temp->getNext();
        }
        if(temp != nullptr){
            trail = temp->getNext();
            delete temp;
        }
    }
}

void ClientList::copyAll(const ClientList &clientList) {
//
}

ClientNode *ClientList::getFirstPos() {
    return header;
}

ClientNode *ClientList::getLastPos() {
    return nullptr;
}

ClientNode *ClientList::getNextPos() {
    return nullptr;
}

ClientNode *ClientList::retrievePos(Client& client) {
    ClientNode* temp;

    temp = header;

    if(temp->getNext() == nullptr){
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
            temp = temp->getNext();
        }while(temp != nullptr);
    }
    return nullptr;
}

Client ClientList::findData(ClientNode *clientNode) {
    ClientNode* temp;
    Client tempClient = Client();

    tempClient.setPhoneNumber(0);

    temp = header;

    if(temp->getNext() == nullptr){
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
            temp = temp->getNext();
        }
    }
    return tempClient;
}



void ClientList::deleteAll() {
    ClientNode* temp;
    ClientNode* trail;

    temp = header;
    trail = nullptr;
    if(temp->getNext() == nullptr){
        delete temp;
        header = new ClientNode();
    } else {
        while(temp != nullptr){
            trail = temp;
            temp = temp->getNext();
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
