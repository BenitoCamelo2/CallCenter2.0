#ifndef PROGRAMA_CLIENTMENU_H
#define PROGRAMA_CLIENTMENU_H

#include <iostream>

#include "ClientList.h"

using namespace std;

class ClientMenu {
private:
    ClientList* clientListRef;
    //pause, click a key to unpause
    static void enterToContinue();
    //adds a client to the list
    void addClient();
    //deletes a client from the list
    void deleteClient();
    //modifies any attribute to a defined client in the list
    void modifyClient();
    //searches clients using any attribute
    void searchClient();
    //prints one client
    static void printClient(ClientNode* clientNode);
    //prints all the clients in the list
    void printClients();
    //main menu
    void mainClientMenu();
public:
    explicit ClientMenu(ClientList* clientList);
    ClientList* getClientList();
};


#endif //PROGRAMA_CLIENTMENU_H
