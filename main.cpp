#include <iostream>

#include "AgentMenu.h"
#include "ClientMenu.h"



using namespace std;

int main() {
    //ClientList* clientList = new ClientList();
    //ClientMenu clientMenu = ClientMenu(clientList);
    AgentList* agentList = new AgentList();
    AgentMenu agentMenu = AgentMenu(agentList);


    return 0;
}
