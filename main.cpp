#include <iostream>

#include "MainMenu.h"
#include "Name.h"

using namespace std;

Agent createAgent(int n);
AgentNode* deleteAgent(AgentList* agentList);

int main() {
    //ClientList* clientList = new ClientList();
    //ClientMenu clientMenu = ClientMenu(clientList);
    AgentList* agentList = new AgentList();
    bool terminate = false;

    do{
        int option;
        cout << "1. Add agent" << endl;
        cout << "2. List agents" << endl;
        cout << "3. Delete agent" << endl;
        cout << "4. Delete all agents" << endl;
        cout << "Option: ";
        cin >> option;
        switch(option){
            case 1: {
                Agent tempAgent = createAgent(1);
                agentList->insertData(agentList->getFirstPos(), tempAgent);
                //tempAgent = createAgent(2);
                //agentList->insertData(agentList->getFirstPos(), tempAgent);
                //tempAgent = createAgent(3);
                //agentList->insertData(agentList->getFirstPos(), tempAgent);
                break;
            }
            case 2: {
                agentList->showAllData();
                break;
            }
            case 3: {
                AgentNode* agentNode;
                agentNode = deleteAgent(agentList);
                agentList->deleteData(agentNode);
                break;
            }
            case 4: {
                agentList->deleteAll();
                break;
            }
            case 5: {
                terminate = true;
                break;
            }
        }
    }while(!terminate);
    return 0;
}

Agent createAgent(int n){
    Agent tempAgent;
    string code, firstName, lastName;
    Name name;
    Time startTime, endTime;
    int extension, extraHours, specialty, tempHour, tempMinute;

    /*cout << "Code: ";
    cin.ignore();getline(cin, code);
    cout << "First Name: ";
    getline(cin, firstName);
    cout << "Last Name: ";
    getline(cin, lastName);
    name.setData(firstName, lastName);
    cout << "Hour of start time: ";
    cin >> tempHour;
    cout << "Minute of start time: ";
    cin >> tempMinute;
    startTime.setData(tempHour, tempMinute);
    cout << "Hour of end time: ";
    cin >> tempHour;
    cout << "Minute of end time: ";
    cin >> tempMinute;
    endTime.setData(tempHour, tempMinute);
    cout << "Extension: ";
    cin >> extension;
    cout << "Extra Hours: ";
    cin >> extraHours;
    cout << "Specialty (1, 2, 3, 4, 5, 6): ";
    cin >> specialty;*/
    switch(n){
        case 1: {
            code = "777";
            name.setData("Louis", "Day");
            startTime.setData(12, 0);
            endTime.setData(8, 0);
            extension = 777;
            extraHours = 1;
            specialty = 1;

            tempAgent.setData(code, name, startTime, endTime, extension, extraHours, specialty);

            return tempAgent;
        }
        case 2: {
            code = "666";
            name.setData("Isabel", "Avila");
            startTime.setData(9, 0);
            endTime.setData(5, 0);
            extension = 666;
            extraHours = 2;
            specialty = 2;

            tempAgent.setData(code, name, startTime, endTime, extension, extraHours, specialty);

            return tempAgent;
        }
        case 3: {
            code = "555";
            name.setData("Sergio", "Gonzalez");
            startTime.setData(9, 0);
            endTime.setData(5, 0);
            extension = 555;
            extraHours = 3;
            specialty = 3;

            tempAgent.setData(code, name, startTime, endTime, extension, extraHours, specialty);

            return tempAgent;
        }
    }

}

AgentNode* deleteAgent(AgentList* agentList){
    Agent tempAgent;
    AgentNode* agentNode;
    string code;
    bool terminate = false;
    do {
        cout << "Code of agent to delete: ";
        cin.ignore();
        getline(cin, code);

        tempAgent.setCode(code);

        agentNode = agentList->findData(tempAgent);
        if(agentNode == nullptr){
            cout << "Agent doesn't exist" << endl;
        } else {
            terminate = true;
        }
    }while(!terminate);
    return agentNode;

}

