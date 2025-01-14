#include <iostream>
#include <string>
#include <iomanip>
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"
#include "Management.h"
#include "Linkedlist.h"
#include "Management.cpp"

void displayMenuManagement(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-MANAGEMENT===================\n";
        std::cout << "==               1.Sender Management                ==\n";
        std::cout << "==               2.Receiver Management              ==\n";
        std::cout << "==               3.Shipment Management              ==\n";
        std::cout << "==               4.Shipper Management               ==\n";
        std::cout << "==               5.Exit                             ==\n";
        std::cout << "======================================================\n";
        std::cout << " Enter your choice: "; 
        std::cin >> choice;

        switch (choice) {
        case 1:
            displaySenderMenu(manager);
            break;
        case 2:
            displayReceiverMenu(manager);
            break;
        case 3:
            displayShipmentMenu(manager);
            break;
        case 4:
            displayShipperMenu(manager);
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            system("pause");
            break;
        }
    } while (choice != 5);
}

void displaySenderMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SENDER-MANAGEMENT===================\n";
        std::cout << "==               1.Add Sender                         ==\n";
        std::cout << "==               2.Print Sender List                  ==\n";
        std::cout << "==               3.Delete Sender By ID                ==\n";
        std::cout << "==               4.Update Sender By ID                ==\n";
        std::cout << "==               5.Find Sender By ID                  ==\n";
        std::cout << "==               6.Return To Main Menu                ==\n";
        std::cout << "========================================================\n";
        std::cout << " Enter your choice: "; 
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addPerson(manager.getSenders(), "Sender");
            break;
        case 2:
            manager.printAllPersons(manager.getSenders(), "Sender");
            break;
        case 3:
            manager.deletePerson(manager.getSenders(), "Sender");
            break;
        case 4:
            manager.updatePerson(manager.getSenders(), "Sender");
            break;
        case 5:
            manager.findPerson(manager.getSenders(), "Sender");
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            system("pause");
            break;
        }
    } while (choice != 6);
}

void displayReceiverMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================RECEIVER-MANAGEMENT===================\n";
        std::cout << "==               1.Add Receiver                         ==\n";
        std::cout << "==               2.Print Receiver List                  ==\n";
        std::cout << "==               3.Delete Receiver By ID                ==\n";
        std::cout << "==               4.Update Receiver By ID                ==\n";
        std::cout << "==               5.Find Receiver By ID                  ==\n";
        std::cout << "==               6.Return To Main Menu                  ==\n";
        std::cout << "==========================================================\n";
        std::cout << " Enter your choice: "; 
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addPerson(manager.getReceivers(), "Receiver");
            break;
        case 2:
            manager.printAllPersons(manager.getReceivers(), "Receiver");
            break;
        case 3:
            manager.deletePerson(manager.getReceivers(), "Receiver");
            break;
        case 4:
            manager.updatePerson(manager.getReceivers(), "Receiver");
            break;
        case 5:
            manager.findPerson(manager.getReceivers(), "Receiver");
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            system("pause");
            break;
        }
    } while (choice != 6);
}

void displayShipmentMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SHIPMENT-MANAGEMENT===================\n";
        std::cout << "==               1.Add Shipment                         ==\n";
        std::cout << "==               2.Print Shipment List                  ==\n";
        std::cout << "==               3.Delete Shipment By ID                ==\n";
        std::cout << "==               4.Update Shipment By ID                ==\n";
        std::cout << "==               5.Find Shipment By ID                  ==\n";
        std::cout << "==               6.Return To Main Menu                  ==\n";
        std::cout << "==========================================================\n";
        std::cout << " Enter your choice: "; 
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addShipment(manager.getShipments(), manager.getSenders(), manager.getReceivers());
            break;
        case 2:
            manager.printAllShipments(manager.getShipments());
            break;
        case 3:
            manager.deleteShipment(manager.getShipments());
            break;
        case 4:
            manager.updateShipment(manager.getShipments());
            break;
        case 5:
            manager.findShipment(manager.getShipments());
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            system("pause");
            break;
        }
    } while (choice != 6);
}

void displayShipperMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SHIPPER-MANAGEMENT===================\n";
        std::cout << "==               1.Print Shipper List                  ==\n";
        std::cout << "==               2.Return To Main Menu                 ==\n";
        std::cout << "========================================================\n";
        std::cout << " Enter your choice: "; 
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.printAllShippers(manager.getShippers());
            break;
        case 2:
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            system("pause");
            break;
        }
    } while (choice != 2);
}
