#ifndef PROGRAMA_CLIENTMENU_H
#define PROGRAMA_CLIENTMENU_H

#include <iostream>

#include "ClientList.h"

using namespace std;

class ClientMenu {
private:
    ClientList* clientListRef;
    static void enterToContinue();
    void addClient();
    void deleteClient();
    void modifyClient();
    void searchClient();
    void mainMenu();
public:
    ClientMenu(ClientList* clientList);
};


#endif //PROGRAMA_CLIENTMENU_H
