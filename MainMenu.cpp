#include "MainMenu.h"

MainMenu::MainMenu() {
    agentList = new AgentList();
    clientList = new ClientList();
    mainMenu();
}

void MainMenu::mainMenu() {
    bool end = false;

    do{
        system(CLEAR);
        switch(mainMenuOptions()){
            case AGENTS: {
                AgentMenu agentMenu = AgentMenu(agentList);
                agentList = agentMenu.getAgentList();
                break;
            }
            case CLIENTS: {
                ClientMenu clientMenu = ClientMenu(clientList);
                clientList = clientMenu.getClientList();
                break;
            }
            case EXIT: {
                end = true;
            }
        }

    }while(!end);
}

int MainMenu::mainMenuOptions() {
    int option;
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Agentes" << endl;
    cout << "2. Clientes" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;
    return option;
}
