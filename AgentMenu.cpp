#include "AgentMenu.h"
#include "util.h"

#ifdef _WIN32
#define CLEAR CLEAR
#elif defined(unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

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

    system(CLEAR);
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

    system(CLEAR);
    cout << "ELIMINAR AGENTE" << endl << endl;

    agentListRef->showAllData();
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
    bool terminate = false;
    AgentNode* temp;
    string agentCode;
    Agent tempAgent;

    system(CLEAR);
    cout << "MODIFICAR AGENTE" << endl;

    agentListRef->showAllData();
    cout << "Ingresa el codigo: ";
    cin.ignore();getline(cin, agentCode);

    tempAgent.setCode(agentCode);

    while(!terminate){
        temp = agentListRef->findData(tempAgent, 1);
        if(temp == nullptr){
            cout << "Ingresa de nuevo: ";
            getline(cin, agentCode);
            tempAgent.setCode(agentCode);
        } else {
            terminate = true;
        }
    }

    tempAgent = agentListRef->retrieve(temp);

    terminate = false;
    do{
        system(CLEAR);
        cout << "MODIFICANDO " << tempAgent.getName().getFirstName() << endl;
        int option = 0;
        cout << "Modificar: " << endl;
        cout << "1. Codigo" << endl;
        cout << "2. Nombre" << endl;
        cout << "3. Hora de inicio de jornada" << endl;
        cout << "4. Hora de fin de jornada" << endl;
        cout << "5. Extension" << endl;
        cout << "6. Horas extras" << endl;
        cout << "7. Especialidad" << endl;
        cout << "8. Regresar" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch(option){
            case MODIFY_CODE: {
                int codeINT;
                string codeSTR;

                cout << "Ingresa el codigo nuevo: ";
                cin >> codeINT;

                while (!verifyINT(1, -1, codeINT)) {
                    cout << "Ingresa de nuevo: ";
                    cin >> codeINT;
                }
                codeSTR = to_string(codeINT);
                tempAgent.setCode(codeSTR);
                break;
            }
            case MODIFY_NAME: {
                string firstName, lastName;
                Name name;

                cout << "Ingresa el primero nombre: ";
                cin.ignore();getline(cin, firstName);
                cout << "Ingresa su apellido: ";
                getline(cin, lastName);
                name.setData(firstName, lastName);

                tempAgent.setName(name);
                break;
            }
            case MODIFY_START_TIME: {
                int hour, minute;
                Time startTime;

                cout << "Ingresa la hora: ";
                cin >> hour;
                cout << "Ingresa el minuto: ";
                cin >> minute;
                startTime.setData(hour, minute);

                tempAgent.setStartTime(startTime);
                break;
            }
            case MODIFY_END_TIME: {
                int hour, minute;
                Time endTime;

                cout << "Ingresa la hora: ";
                cin >> hour;
                cout << "Ingresa el minuto: ";
                cin >> minute;
                endTime.setData(hour, minute);

                tempAgent.setEndTime(endTime);
                break;
            }
            case MODIFY_EXTENSION: {
                int extension;

                cout << "Ingresa la extension: ";
                cin >> extension;
                while(!verifyINT(1,-1,extension)){
                    cout << "Ingresa de nuevo: ";
                    cin >> extension;
                }

                tempAgent.setExtension(extension);
                break;
            }
            case MODIFY_EXTRA_HOURS: {
                int extraHours;

                cout << "Ingresa las horas extras a sumar: ";
                cin >> extraHours;
                while(!verifyINT(0,-1,extraHours)){
                    cout << "Ingresa de nuevo: ";
                    cin >> extraHours;
                }

                tempAgent.addExtraHours(extraHours);
                break;
            }
            case MODIFY_SPECIALTY: {
                int specialty;

                cout << "Ingresa la especialidad: ";
                cin >> specialty;
                while(!verifyINT(1,6,specialty)){
                    cout << "Ingresa de nuevo: ";
                    cin >> specialty;
                }
                tempAgent.setSpecialty(specialty);
                break;
            }
            case EXIT_MODIFY: {
                temp->setData(tempAgent);
                terminate = true;
                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                cin.ignore();
                enterToContinue();
            }
        }
    }while(!terminate);
}

void AgentMenu::searchAgent() {
    bool terminate = false;

    do{
        int option = 0;
        system(CLEAR);
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

                listHeader();
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

                listHeader();
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

                listHeader();
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

                listHeader();
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

                listHeader();
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

                listHeader();
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

void AgentMenu::sortAgents() {

}

void AgentMenu::mainAgentMenu() {
    bool terminate = false;

    do{
        int option = 0;
        system(CLEAR);
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
                agentListRef->showAllData();
                cin.ignore();
                enterToContinue();
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

AgentList* AgentMenu::getAgentList() {
    return agentListRef;
}
