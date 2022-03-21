#include "ClientMenu.h"
#include "AgentMenu.h"
#include "util.h"

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

ClientMenu::ClientMenu(ClientList *clientList): clientListRef(clientList) {
    //inicializes main menu
    mainClientMenu();
}

void ClientMenu::enterToContinue() {
    cout << "Presione enter para continuar..." << endl;
    getchar();
}

void ClientMenu::addClient() {
    //temp data to incorporate into a client to add to the list
    Client tempClient;
    int minute, hour, year, day, month;
    string clientPhoneNumber;
    Time clientCallDuration, clientCallStart;
    Date clientCallDate;

    system(CLEAR);
    cout << "AGREGAR CLIENTE" << endl;
    cout << "Numero telefonico: ";
    cin.ignore();getline(cin, clientPhoneNumber);
    while(clientPhoneNumber.length() < 10){
        cout << "Ingresa de nuevo: ";
        getline(cin, clientPhoneNumber);
    }
    cout << "Hora de inicio de llamada: ";
    cin >> hour;
    while(!verifyINT(0,23,hour)){
        cout << "Ingresa de nuevo: ";
        cin >> hour;
    }
    cout << "Minuto de inicio de llamada: ";
    cin >> minute;
    while(!verifyINT(0, 59, minute)){
        cout << "Ingresa de nuevo: ";
        cin >> minute;
    }
    clientCallStart.setData(hour, minute);
    cout << "Horas de duracion de llamada: ";
    cin >> hour;
    while(!verifyINT(0,23,hour)){
        cout << "Ingresa de nuevo: ";
        cin >> hour;
    }
    cout << "Minutos de duracion de llamada: ";
    cin >> minute;
    while(!verifyINT(0, 59, minute)){
        cout << "Ingresa de nuevo: ";
        cin >> minute;
    }
    clientCallDuration.setData(hour, minute);
    cout << "Anio de llamada: ";
    cin >> year;
    cout << "Mes de llamada: ";
    cin >> month;
    cout << "Dia de llamada: ";
    cin >> day;
    while(!clientCallDate.setData(year, month, day)){
        cout << "Ingresa de nuevo" << endl;
        cout << "Anio de llamada: ";
        cin >> year;
        cout << "Mes de llamada: ";
        cin >> month;
        cout << "Dia de llamada: ";
        cin >> day;
    }

    tempClient.setData(clientPhoneNumber, clientCallStart, clientCallDuration, clientCallDate);
    clientListRef->insertOrdered(tempClient);
}

void ClientMenu::deleteClient() {
    Client tempClient1 = Client();
    ClientNode* tempClientNode;
    string phoneNumber;
    cout << "ELIMINAR CLIENTE" << endl;
    printClients();
    cout << "Numero telefonico: ";
    cin.ignore();getline(cin, phoneNumber);
    tempClient1.setPhoneNumber(phoneNumber);
    tempClientNode = clientListRef->retrievePos(tempClient1, 1);
    if(tempClientNode != nullptr){
        char exit = '\0';
        clientListHeader();
        printClient(tempClientNode);
        cout << "Esta seguro que quiere eliminar el cliente? (N/S): ";
        cin >> exit;
        cin.ignore();
        if(exit == 'S' || exit == 's'){
            clientListRef->deleteData(tempClientNode);
        } else {
            enterToContinue();
        }
    } else {
        cout << "Cliente no encontrado" << endl;
        cin.ignore();
        enterToContinue();
    }
}

void ClientMenu::modifyClient() {
    Client tempClient1 = Client();
    ClientNode* tempClientNode;
    string phoneNumber;
    system(CLEAR);
    cout << "MODIFICAR CLIENTE" << endl << endl;
    clientListHeader();
    printClients();
    cout << "Numero telefonico: ";
    cin.ignore();getline(cin, phoneNumber);
    tempClient1.setPhoneNumber(phoneNumber);
    tempClientNode = clientListRef->retrievePos(tempClient1, 1);
    if(tempClientNode != nullptr){
        int opc;
        system(CLEAR);
        cout << "MODIFICAR " << tempClientNode->getData().getPhoneNumber() << endl;
        cout << "Seleccionar una opcion para modificar: " << endl;
        cout << "1. Numero telefonico" << endl;
        cout << "2. Fecha de la llamada" << endl;
        cout << "3. Hora inicio de la llamada" << endl;
        cout << "4. Duracion de la llamada" << endl;
        cout << "0. Cancelar" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch(opc){
            case MODIFY_PHONE: {
                string clientPhoneNumber;
                tempClient1 = tempClientNode->getData();
                cout << "Numero telefonico nuevo: ";
                cin.ignore();getline(cin, clientPhoneNumber);
                while(clientPhoneNumber.length() > 10){
                    cout << "Ingresa de nuevo: ";
                    getline(cin, clientPhoneNumber);
                }
                tempClient1.setPhoneNumber(clientPhoneNumber);
                break;
            }
            case MODIFY_CALL_DATE: {
                Date callDate;
                int year, month, day;
                tempClient1 = tempClientNode->getData();
                cout << "Anio: ";
                cin >> year;
                cout << "Mes: ";
                cin >> month;
                cout << "Dia: ";
                cin >> day;
                callDate.setData(year, month, day);
                tempClient1.setCallDate(callDate);
                break;
            }
            case MODIFY_CALL_START: {
                Time callStart;
                int hour, minute;
                tempClient1 = tempClientNode->getData();
                cout << "Horas: ";
                cin >> hour;
                cout << "Minutos: ";
                cin >> minute;
                callStart.setData(hour, minute);
                tempClient1.setCallStart(callStart);
                break;
            }
            case MODIFY_CALL_DURATION: {
                Time callDuration;
                int hour, minute;
                tempClient1 = tempClientNode->getData();
                cout << "Horas: ";
                cin >> hour;
                cout << "Minutos: ";
                cin >> minute;
                callDuration.setData(hour, minute);
                tempClient1.setCallDuration(callDuration);
                break;
            }
            default: {
                enterToContinue();
                break;
            }
        }
        tempClientNode->setData(tempClient1);
    } else {
        cout << "Cliente no encontrado" << endl;
        cin.ignore();
        enterToContinue();
    }
}

void ClientMenu::searchClient() {
    system(CLEAR);
    int opc;
    cout << "BUSCAR CLIENTE" << endl;
    cout << "Buscar por: " << endl;
    cout << "1. Numero telefonico" << endl;
    cout << "2. Fecha" << endl;
    cout << "3. Hora de inicio" << endl;
    cout << "4. Duracion de llamada" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opc;

    switch(opc){
        case SEARCH_BY_PHONENUMBER: {
            string phoneNumber;
            Client tempClient = Client();
            ClientNode* tempClientNode = new ClientNode();
            cout << "Numero telefonico: ";
            cin.ignore();getline(cin, phoneNumber);
            tempClient.setPhoneNumber(phoneNumber);
            tempClientNode = clientListRef->retrievePos(tempClient, 1);
            if(tempClientNode != nullptr){
                tempClient = clientListRef->findData(tempClientNode);
                clientListHeader();
                printClient(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case SEARCH_BY_CALLDATE: {
            int year, month, day;
            Date callDate;
            Client tempClient = Client();
            ClientNode* tempClientNode = new ClientNode();
            cout << "Anio: ";
            cin >> year;
            cout << "Mes: ";
            cin >> month;
            cout << "Dia: ";
            cin >> day;
            callDate.setData(year, month, day);
            tempClient.setCallDate(callDate);
            tempClientNode = clientListRef->retrievePos(tempClient, 2);
            if(tempClientNode != nullptr){
                tempClient = clientListRef->findData(tempClientNode);
                clientListHeader();
                printClient(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case SEARCH_BY_CALLSTART: {
            int hour, minute;
            Time callStart;
            Client tempClient = Client();
            ClientNode* tempClientNode = new ClientNode();
            cout << "Hora: ";
            cin >> hour;
            cout << "Minuto: ";
            cin >> minute;
            callStart.setData(hour, minute);
            tempClient.setCallStart(callStart);
            tempClientNode = clientListRef->retrievePos(tempClient, 3);
            if(tempClientNode != nullptr){
                tempClient = clientListRef->findData(tempClientNode);
                clientListHeader();
                printClient(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case SEARCH_BY_CALLDURATION: {
            int hour, minute;
            Time callDuration;
            Client tempClient = Client();
            ClientNode* tempClientNode = new ClientNode();
            cout << "Hora: ";
            cin >> hour;
            cout << "Minuto: ";
            cin >> minute;
            callDuration.setData(hour, minute);
            tempClient.setCallDuration(callDuration);
            tempClientNode = clientListRef->retrievePos(tempClient, 4);
            if(tempClientNode != nullptr){
                tempClient = clientListRef->findData(tempClientNode);
                clientListHeader();
                printClient(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        default: {
            cin.ignore();
            enterToContinue();
        }
    }
}

void ClientMenu::printClient(ClientNode *clientNode) {
    //prints data in this structure:
    //|PhoneNumber|CallDate|CallStart|CallDuration|
    //can always build it some day to calculate when the call ended
    cout << "|" << clientNode->getData().getPhoneNumber();
    cout.width(20 - clientNode->getData().getPhoneNumber().length());
    cout << "|" << clientNode->getData().getCallDate().toString();
    cout.width(20 - clientNode->getData().getCallDate().toString().length());
    cout << "|" << clientNode->getData().getCallStart().toString();
    cout.width(23 - clientNode->getData().getCallStart().toString().length());
    cout << "|" << clientNode->getData().getCallDuration().toString();
    cout.width(20 - clientNode->getData().getCallDuration().toString().length());
    cout << "|" << endl;
}

void ClientMenu::printClients() {
    ClientNode* temp(clientListRef->getFirstPos());
    ClientNode* last(clientListRef->getLastPos());

    //makes sure there are nodes in the list
    if(temp != nullptr) {
        //this is when there is only one client in the list
        if (temp == last) {
            printClient(temp);
            //multiple clients in the list
        } else {
            while (temp != nullptr) {
                printClient(temp);
                temp = temp->getNext();
            }
        }
    } else {
        cout << "No hay clientes en la lista" << endl;
    }
}

void ClientMenu::mainClientMenu() {
    bool terminate = false;

    do{
        int opc = 0;
        system(CLEAR);
        cout << "MENU DE CLIENTES" << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Eliminar cliente" << endl;
        cout << "3. Modificar cliente" << endl;
        cout << "4. Buscar cliente" << endl;
        cout << "5. Mostrar los clientes" << endl;
        cout << "6. Eliminar TODOS los clientes" << endl;
        cout << "7. Regresar" << endl;
        cout << "Option: ";
        cin >> opc;
        switch(opc){
            case ADD_CLIENT: {
                addClient();
                break;
            }
            case DELETE_CLIENT: {
                deleteClient();
                break;
            }
            case MODIFY_CLIENT: {
                modifyClient();
                break;
            }
            case SEARCH_CLIENT: {
                searchClient();
                break;
            }
            case SHOW_CLIENTS: {
                system(CLEAR);
                cout << "MOSTRAR CLIENTES" << endl;
                clientListHeader();
                printClients();
                cin.ignore();
                enterToContinue();
                break;
            }
            case DELETE_ALL_CLIENTS: {
                clientListRef->deleteAll();
                cin.ignore();
                enterToContinue();
                break;
            }
            case EXIT_CLIENT: {
                terminate = true;
                break;
            }
            default: {
                cout << "xd" << endl;
            }
        }
    }while(!terminate);
}