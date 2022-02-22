#include "ClientMenu.h"

enum{
    ADD_CLIENT = 1,
    DELETE_CLIENT,
    MODIFY_CLIENT,
    SEARCH_CLIENT,
    SHOW_CLIENTS,
    DELETE_ALL_CLIENTS,
    EXIT_CLIENT
};

ClientMenu::ClientMenu(ClientList *clientList): clientListRef(clientList) {
    mainMenu();
}

void ClientMenu::enterToContinue() {
    cout << "Presione enter para continuar..." << endl;
    getchar();
}

void ClientMenu::addClient() {
    Client tempClient;
    int clientPhoneNumber, minute, hour, year, day, month;
    Time clientCallDuration, clientCallStart;
    Date clientCallDate;
    system("cls");
    cout << "AGREGAR CLIENTE" << endl;
    cout << "Numero telefonico: ";
    cin >> clientPhoneNumber;
    cout << "Hora de inicio de llamada: ";
    cin >> hour;
    cout << "Minuto de inicio de llamada: ";
    cin >> minute;
    clientCallStart.setData(hour, minute);
    cout << "Horas de duracion de llamada: ";
    cin >> hour;
    cout << "Minutos de duracion de llamada: ";
    cin >> minute;
    clientCallDuration.setData(hour, minute);
    cout << "Anio de llamada: ";
    cin >> year;
    cout << "Mes de llamada: ";
    cin >> month;
    cout << "Dia de llamada: ";
    cin >> day;
    clientCallDate.setData(year, month, day);
    tempClient.setData(clientPhoneNumber, clientCallStart, clientCallDuration, clientCallDate);
    clientListRef->insertOrdered(tempClient);
}

void ClientMenu::deleteClient() {
    Client tempClient1 = Client();
    ClientNode* tempClientNode;
    int phoneNumber;
    cout << "ELIMINAR CLIENTE" << endl;
    cout << "Phonenumber: ";
    cin >> phoneNumber;
    tempClient1.setPhoneNumber(phoneNumber);
    tempClientNode = clientListRef->retrievePos(tempClient1, 1);
    if(tempClientNode != nullptr){
        char exit = '\0';
        cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
        clientListRef->showData(tempClientNode);
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
    int phoneNumber;
    system("cls");
    cout << "MODIFICAR CLIENTE" << endl;
    cout << "Numero telefonico: ";
    cin >> phoneNumber;
    tempClient1.setPhoneNumber(phoneNumber);
    tempClientNode = clientListRef->retrievePos(tempClient1, 1);
    if(tempClientNode != nullptr){
        int opc;
        system("cls");
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
            case 1: {
                int clientPhoneNumber;
                tempClient1 = tempClientNode->getData();
                cout << "Numero telefonico nuevo: ";
                cin >> clientPhoneNumber;
                tempClient1.setPhoneNumber(clientPhoneNumber);
                tempClientNode->setData(tempClient1);
                break;
            }
            case 2: {
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
                tempClientNode->setData(tempClient1);
                break;
            }
            case 3: {
                Time callStart;
                int hour, minute;
                tempClient1 = tempClientNode->getData();
                cout << "Horas: ";
                cin >> hour;
                cout << "Minutos: ";
                cin >> minute;
                callStart.setData(hour, minute);
                tempClient1.setCallStart(callStart);
                tempClientNode->setData(tempClient1);
                break;
            }
            case 4: {
                Time callDuration;
                int hour, minute;
                tempClient1 = tempClientNode->getData();
                cout << "Horas: ";
                cin >> hour;
                cout << "Minutos: ";
                cin >> minute;
                callDuration.setData(hour, minute);
                tempClient1.setCallDuration(callDuration);
                tempClientNode->setData(tempClient1);
                break;
            }
            default: {
                enterToContinue();
                break;
            }
        }
    } else {
        cout << "Cliente no encontrado" << endl;
        cin.ignore();
        enterToContinue();
    }
}

void ClientMenu::searchClient() {
    system("cls");
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
        case 1: {
            int phoneNumber;
            Client tempClient = Client();
            ClientNode* tempClientNode = new ClientNode();
            cout << "Numero telefonico: ";
            cin >> phoneNumber;
            tempClient.setPhoneNumber(phoneNumber);
            tempClientNode = clientListRef->retrievePos(tempClient, 1);
            if(tempClientNode != nullptr){
                tempClient = clientListRef->findData(tempClientNode);
                cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
                clientListRef->showData(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case 2: {
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
                cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
                clientListRef->showData(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case 3: {
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
                cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
                clientListRef->showData(tempClientNode);
                cin.ignore();
                enterToContinue();
            } else {
                cout << "Cliente no encontrado" << endl;
                cin.ignore();
                enterToContinue();
            }
            break;
        }
        case 4: {
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
                cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
                clientListRef->showData(tempClientNode);
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

void ClientMenu::mainMenu() {
    bool terminate = false;

    do{
        int opc = 0;
        system("cls");
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
                cout << "|Numero Telefonico  |Fecha de llamada   |Hora inicio de llamada|Duracion de llamada|" << endl;
                clientListRef->showAllData();
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
