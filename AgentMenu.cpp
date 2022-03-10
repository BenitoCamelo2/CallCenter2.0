#include "AgentMenu.h"
#include "util.h"



AgentMenu::AgentMenu(AgentList* agentList): agentListRef(agentList) {
    mainAgentMenu();
}


void AgentMenu::enterToContinue() {
    cout << "Presione enter para continuar..." << endl;
    getchar();
}

void AgentMenu::addAgent() {
    Agent tempAgent;
    string codeSTR, firstName, lastName;
    Name name;
    Time startTime, endTime;
    int extension, extraHours, specialty, tempHour, tempMinute, codeINT;

    system("cls");
    cout << "AGREGAR AGENTE" << endl;

    //code, verify as int then assign to str
    cout << "Codigo: ";
    cin >> codeINT;
    while(!verifyINT(1, -1, codeINT)){
        cout << "Ingresa un numero mayor a 0: ";
        cin >> codeINT;
    }
    codeSTR = to_string(codeINT);

    //first name
    cout << "Primer nombre: ";
    cin.ignore();getline(cin, firstName);

    //last name
    cout << "Apellido: ";
    getline(cin, lastName);
    name.setData(firstName, lastName);

    //hour of when shift starts
    cout << "Hora de inicio de horario: ";
    cin >> tempHour;
    while(!verifyINT(0, 23, tempHour)){
        cout << "Ingresa de nuevo: ";
        cin >> tempHour;
    }

    //minute of when shift starts
    cout << "Minuto de  de horario: ";
    cin >> tempMinute;
    while(!verifyINT(0, 59, tempMinute)){
        cout << "Ingresa de nuevo: ";
        cin >> tempMinute;
    }
    startTime.setData(tempHour, tempMinute);


    //hour of when shift ends
    cout << "Hora de fin de horario: ";
    cin >> tempHour;
    while(!verifyINT(0, 23, tempHour)){
        cout << "Ingresa de nuevo: ";
        cin >> tempHour;
    }

    //minute of when shift ends
    cout << "Minuto de fin de horario: ";
    cin >> tempMinute;
    while(!verifyINT(0, 59, tempMinute)){
        cout << "Ingresa de nuevo: ";
        cin >> tempMinute;
    }
    endTime.setData(tempHour, tempMinute);

    //extension
    cout << "Extension: ";
    cin >> extension;
    while(!verifyINT(1, -1, extension)){
        cout << "Ingresa de nuevo mayor o igual a 1: ";
        cin >> extension;
    }

    //extra hours
    cout << "Horas extras: ";
    cin >> extraHours;
    while(!verifyINT(1, -1, extraHours)){
        cout << "Ingresa de nuevo mayor o igual a 1: ";
        cin >> extraHours;
    }

    //specialty
    cout << "Especialidad (1, 2, 3, 4, 5, 6): ";
    cin >> specialty;
    while(!verifyINT(1, 6, specialty)){
        cout << "Ingresa un valor de 1 a 6: ";
        cin >> specialty;
    }

    tempAgent.setData(codeSTR, name, startTime, endTime, extension, extraHours, specialty);
    agentListRef->insertData(agentListRef->getFirstPos(), tempAgent);
}

void AgentMenu::deleteAgent() {
    Agent tempAgent;
    AgentNode* agentNode;
    string code;
    bool terminate = false;

    system("cls");
    cout << "ELIMINAR AGENTE" << endl << endl;

    showAgents();
    cout << "Ingresa el codigo del agente que desea eliminar: ";
    cin.ignore();getline(cin, code);
    do {
        tempAgent.setCode(code);

        agentNode = agentListRef->findData(tempAgent, SEARCH_CODE);
        if (agentNode == nullptr) {
            cout << "Ingresa de nuevo porfavor (0 para cancelar): " << endl;
            getline(cin, code);
            if(code == "0"){
                return;
            }
        } else {
            terminate = true;
        }
    }while(!terminate);

    agentListRef->deleteData(agentNode);
}

void AgentMenu::modifyAgent() {

}

void AgentMenu::searchAgent() {
    bool terminate = false;

    do{
        int option = 0;
        system("cls");
        cout << "BUSCAR AGENTE" << endl;
        cout << "Buscar por: " << endl;
        cout << "1. Codigo" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Hora de inicio de horario" << endl;
        cout << "4. Hora de fin de horario" << endl;
        cout << "5. Extension" << endl;
        cout << "6. Especialidad" << endl;
        cout << "7. Regresar" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch(option){
            case SEARCH_CODE: {
                int codeINT;
                string codeSTR;
                Agent tempAgent;

                cout << "Ingresa un codigo: ";
                cin >> codeINT;
                while(!verifyINT(1,-1,codeINT)){
                    cout << "Ingresa de nuevo: ";
                    cin >> codeINT;
                }
                codeSTR = to_string(codeINT);
                tempAgent.setCode(codeSTR);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_CODE));
                cin.ignore();enterToContinue();
                break;
            }
            case SEARCH_LAST_NAME: {
                string lastName, firstName = "";
                Name name;
                Agent tempAgent;

                cout << "Ingresa el apellido: ";
                cin.ignore();getline(cin, lastName);
                name.setData(firstName, lastName);
                tempAgent.setName(name);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_LAST_NAME));
                enterToContinue();
                break;
            }
            case SEARCH_HOUR_START: {
                int hour, minute=0;
                Time time;
                Agent tempAgent;

                cout << "Ingresa la hora de inicio: ";
                cin >> hour;
                time.setData(hour, minute);
                tempAgent.setStartTime(time);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_HOUR_START));
                cin.ignore();enterToContinue();
                break;
            }
            case SEARCH_HOUR_END: {
                int hour, minute=0;
                Time time;
                Agent tempAgent;

                cout << "Ingresa la hora de fin: ";
                cin >> hour;
                time.setData(hour, minute);
                tempAgent.setEndTime(time);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_HOUR_END));
                cin.ignore();enterToContinue();
                break;
            }
            case SEARCH_EXTENSION: {
                int extension;
                Agent tempAgent;

                cout << "Ingresa la extension: ";
                cin >> extension;
                while(!verifyINT(0, -1, extension)){
                    cout << "Ingresa de nuevo: ";
                    cin >> extension;
                }
                tempAgent.setExtension(extension);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_EXTENSION));
                cin.ignore();enterToContinue();
                break;
            }
            case SEARCH_SPECIALTY: {
                int specialty;
                Agent tempAgent;

                cout << "Ingresa la especialidad: ";
                cin >> specialty;
                while(!verifyINT(1, 6, specialty)){
                    cout << "Ingresa de nuevo: ";
                    cin >> specialty;
                }

                tempAgent.setSpecialty(specialty);

                cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
                agentListRef->showData(agentListRef->findData(tempAgent, SEARCH_SPECIALTY));
                cin.ignore();enterToContinue();
                break;
            }
            case EXIT_SEARCH: {
                terminate = true;
                break;
            }
            default: {
                cout << "Seleccione una opcion valida" << endl;
                cin.ignore();
                enterToContinue();
            }
        }
    }while(!terminate);
}

void AgentMenu::showAgents() {

}

void AgentMenu::sortAgents() {

}

void AgentMenu::mainAgentMenu() {
    bool terminate = false;

    do{
        int option = 0;
        system("cls");
        cout << "MENU DE AGENTES" << endl;
        cout << "1. Agregar agente" << endl;
        cout << "2. Eliminar agente" << endl;
        cout << "3. Modificar agente" << endl;
        cout << "4. Buscar agente" << endl;
        cout << "5. Organizar agentes" << endl;
        cout << "6. Mostrar los agentes" << endl;
        cout << "7. Eliminar TODOS los agentes" << endl;
        cout << "8. Regresar" << endl;
        cout << "Option: ";
        cin >> option;
        switch(option){
            case ADD_AGENT: {
                addAgent();
                break;
            }
            case DELETE_AGENT: {
                deleteAgent();
                break;
            }
            case MODIFY_AGENT: {
                modifyAgent();
                break;
            }
            case SEARCH_AGENT: {
                searchAgent();
                break;
            }
            case SORT_AGENTS: {
                sortAgents();
                break;
            }
            case SHOW_AGENTS: {
                showAgents();
                break;
            }
            case DELETE_ALL_AGENTS: {
                char deleteAgents = '\0';
                cout << "Esta seguro? (S/N): ";
                cin >> deleteAgents;
                if(deleteAgents == 's' || deleteAgents == 'S'){
                    agentListRef->deleteAll();
                    cin.ignore();
                    enterToContinue();
                }
                break;
            }
            case EXIT_AGENT: {
                terminate = true;
                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                enterToContinue();
            }
        }
    }while(!terminate);
}
