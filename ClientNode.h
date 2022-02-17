#ifndef PROGRAMA_CLIENTNODE_H
#define PROGRAMA_CLIENTNODE_H

#include <iostream>

#include "Client.h"

class ClientNode {
private:
    Client data;
    ClientNode* next;
public:
    ClientNode();
    ClientNode(const Client& client);
    Client getData();
    ClientNode* getNext();
    void setData(const Client& client);
    void setNext(ClientNode* clientNode);
};


#endif //PROGRAMA_CLIENTNODE_H
