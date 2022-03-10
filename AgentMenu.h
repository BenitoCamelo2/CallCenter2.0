#ifndef PROGRAMA_AGENTMENU_H
#define PROGRAMA_AGENTMENU_H

#include <iostream>

#include "AgentList.h"

using namespace std;

class AgentMenu {
private:
    AgentList* agentListRef;
    static void enterToContinue();
    void addAgent();
    void deleteAgent();
    void modifyAgent();
    void searchAgent();
    void showAgents();
    void sortAgents();
    void mainAgentMenu();
public:
    explicit AgentMenu(AgentList* agentList);
};

enum{
    SEARCH_CODE = 1,
    SEARCH_LAST_NAME,
    SEARCH_HOUR_START,
    SEARCH_HOUR_END,
    SEARCH_EXTENSION,
    SEARCH_SPECIALTY,
    EXIT_SEARCH
};

enum{
    ADD_AGENT = 1,
    DELETE_AGENT,
    MODIFY_AGENT,
    SEARCH_AGENT,
    SORT_AGENTS,
    SHOW_AGENTS,
    DELETE_ALL_AGENTS,
    EXIT_AGENT
};



#endif //PROGRAMA_AGENTMENU_H
