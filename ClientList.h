#ifndef PROGRAMA_CLIENTLIST_H
#define PROGRAMA_CLIENTLIST_H

#include <iostream>
#include <string>

#include "ClientNode.h"
#include "ListException.h"

using namespace std;

class ClientList {
private:
    ClientNode* header;
    bool isValidPos(ClientNode* clientNode);
    void copyAll(const ClientList& clientList);
public:
    ClientList();
    ~ClientList();
    bool isEmpty();
    void insertData(ClientNode* clientNode, const Client& client);
    void insertOrdered(Client& client);
    void deleteData(ClientNode* clientNode);
    ClientNode* getFirstPos();
    ClientNode* getLastPos();
    ClientNode* getNextPos();
    ClientNode* findData(const Client& client);
    Client retrievePos(ClientNode* clientNode);
    string toString();
    void deleteAll();
    void writeToDisk(const string data);
    string readFromDisk();
};


#endif //PROGRAMA_CLIENTLIST_H
