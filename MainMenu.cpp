#include "MainMenu.h"

MainMenu::MainMenu() {
    agentList = new AgentList();
    splashScreen();
    AgentMenu(new AgentList);
}

void MainMenu::splashScreen() {
    cout << "INICIO" << endl;
    cout << "Administracion del call center" << endl << endl;
    cout << "Ingresa una tecla para continuar..." << endl;
    getchar();
}
