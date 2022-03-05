#include <iostream>

#include "MainMenu.h"

using namespace std;

int main() {
    ClientList* clientList = new ClientList();
    ClientMenu clientMenu = ClientMenu(clientList);
    return 0;
}

