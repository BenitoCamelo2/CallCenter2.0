#include <iostream>

#include "AgentMenu.h"
#include "ClientMenu.h"

#ifdef _WIN32
#define CLEAR CLEAR
#elif defined(unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

enum{
    AGENTS = 1,
    CLIENTS,
    EXIT
};

using namespace std;

int mainMenu();

int main() {
    ClientList* clientList = new ClientList();
    AgentList* agentList = new AgentList();
    bool end = false;

    do{
        system(CLEAR);
        switch(mainMenu()){
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



    return 0;
}

int mainMenu(){
    int option;
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Agentes" << endl;
    cout << "2. Clientes" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;
    return option;
}
