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

enum {
    MODIFY_CODE = 1,
    MODIFY_NAME,
    MODIFY_START_TIME,
    MODIFY_END_TIME,
    MODIFY_EXTENSION,
    MODIFY_EXTRA_HOURS,
    MODIFY_SPECIALTY,
    EXIT_MODIFY
};


#endif //PROGRAMA_AGENTMENU_H
