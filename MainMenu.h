#ifndef PROGRAMA_MAINMENU_H
#define PROGRAMA_MAINMENU_H

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

#include <iostream>

#include "AgentMenu.h"
#include "ClientMenu.h"

using namespace std;

class MainMenu {
private:
    AgentList* agentList;
    ClientList* clientList;
public:
    MainMenu();

    void mainMenu();
    int mainMenuOptions();
};

enum{
    AGENTS = 1,
    CLIENTS,
    EXIT
};

#endif //PROGRAMA_MAINMENU_H
