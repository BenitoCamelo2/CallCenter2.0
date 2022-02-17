#include <iostream>

#include "MainMenu.h"

using namespace std;

Client createClient();
void searchClient(ClientList *clientList);

int main() {
    ClientList* clientList = new ClientList();
    bool terminate = false;

    do{
        int opc = 0;
        system("cls");
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Delete all" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cout << "Option: ";
        cin >> opc;
        switch(opc){
            case 1: {
                Client tempClient;
                tempClient = createClient();
                clientList->insertOrdered(tempClient);
                break;
            }
            case 2: {
                clientList->deleteData(clientList->getFirstPos());
                break;
            }
            case 3: {
                clientList->deleteAll();
                break;
            }
            case 4: {
                searchClient(clientList);
                break;
            }
            case 5: {
                terminate = true;
                break;
            }
            default: {
                cout << "xd" << endl;
            }
        }
    }while(!terminate);

    createClient();
    return 0;
}

Client createClient(){
    Client tempClient;
    int clientPhoneNumber, minute, hour, year, day, month;
    Time clientCallDuration, clientCallStart;
    Date clientCallDate;
    cout << "Phone Number: ";
    cin >> clientPhoneNumber;
    cout << "Minute start: ";
    cin >> minute;
    cout << "Hour start: ";
    cin >> hour;
    clientCallStart.setData(hour, minute);
    cout << "Hour duration: ";
    cin >> hour;
    cout << "Minute duration: ";
    cin >> minute;
    clientCallDuration.setData(hour, minute);
    cout << "Year: ";
    cin >> year;
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    clientCallDate.setData(year, month, day);
    tempClient.setData(clientPhoneNumber, clientCallStart, clientCallDuration, clientCallDate);
    return tempClient;
}

void searchClient(ClientList* clientList){
    Client tempClient1 = Client();
    Client tempClient2 = Client();
    ClientNode* tempClientNode = new ClientNode();
    int phoneNumber;
    cout << "Phonenumber: ";
    cin >> phoneNumber;
    tempClient1.setPhoneNumber(phoneNumber);
    tempClientNode = clientList->retrievePos(tempClient1);
    if(tempClientNode != nullptr){
        cout << "Data found" << endl;
        tempClient2 = clientList->findData(tempClientNode);
        cout << "Phonenumber: " << tempClient2.getPhoneNumber() << endl;
    } else {
        cout << "Data not found" << endl;
    }
}

