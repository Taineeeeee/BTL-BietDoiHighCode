#include "Display.h"

void displayMenuManagement() {
    int choice;
    do {
        system("CLS");
        printf("\t\t   BIET DOI HIGH CODE\t\n");
        printf("====================MENU-MANAGEMENT====================\n");
        printf("==               1. Sender Management                ==\n");
        printf("==               2. Receiver Management              ==\n");
        printf("==               3. Shipment Management              ==\n");
        printf("==               4. Shipper Management               ==\n");
        printf("==               5. Exit                             ==\n");
        printf("=======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            displaySenderMenu();
            break;
        case 2:
            displayReceiverMenu();
            break;
        case 3:
            displayShipmentMenu();
            break;
        case 4:
            displayShipperMenu();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            break;
        }
    } while (choice != 5);
}

void displaySenderMenu() {
    int choice;
    do {
        system("CLS");
        printf("\t\t   BIET DOI HIGH CODE\t\n");
        printf("====================SENDER-MANAGEMENT====================\n");
        printf("==               1. Add Sender                         ==\n");
        printf("==               2. Print Sender List                  ==\n");
        printf("==               3. Delete Sender By ID                ==\n");
        printf("==               4. Update Sender By ID                ==\n");
        printf("==               5. Find Sender By ID                  ==\n");
        printf("==               6. Sort Sender List By ID             ==\n");
        printf("==               7. Export Sender List To File         ==\n");
        printf("==               8. Return To Main Menu                ==\n");
        printf("=========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            addPerson(senders, &sendersCount, "Sender");
            break;
        case 2:
            printAllPersons(senders, sendersCount, "Sender");
            break;
        case 3:
            deletePerson(senders, &sendersCount, "Sender");
            break;
        case 4:
            updatePerson(senders, sendersCount, "Sender");
            break;
        case 5:
            findPerson(senders, sendersCount, "Sender");
            break;
        case 6: {
            system("CLS");
            int personChoice;
            printf("1. Ascending\n2. Descending\n");
            printf("Enter your choice: ");
            scanf("%d", &personChoice);
            getchar();

            if (personChoice == 1) {
                sortPersonById(senders, sendersCount, 1);
                printf("Senders sorted by ID (Ascending)!\n");
            } else if (personChoice == 2) {
                sortPersonById(senders, sendersCount, 0);
                printf("Senders sorted by ID (Descending)!\n");
            } else {
                printf("Invalid choice!\n");
            }
            system("pause");
            break;
        }
        case 7: {
            system("CLS");
            char fname[20];
            printf("Enter the filename: ");
            scanf("%s", fname);
            getchar();

            exportToFile(senders, sendersCount, fname, "Sender");
            printf("Exported File Successfully!\n");
            system("pause");
            break;
        }
        case 8:
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            break;
        }
    } while (choice != 8);
}

void displayReceiverMenu() {
    int choice;
    do {
        system("CLS");
        printf("\t\t   BIET DOI HIGH CODE\t\n");
        printf("====================RECEIVER-MANAGEMENT====================\n");
        printf("==               1. Add Receiver                         ==\n");
        printf("==               2. Print Receiver List                  ==\n");
        printf("==               3. Delete Receiver By ID                ==\n");
        printf("==               4. Update Receiver By ID                ==\n");
        printf("==               5. Find Receiver By ID                  ==\n");
        printf("==               6. Sort Receiver List By ID             ==\n");
        printf("==               7. Export Receiver List To File         ==\n");
        printf("==               8. Return To Main Menu                  ==\n");
        printf("===========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            addPerson(receivers, &receiversCount, "Receiver");
            break;
        case 2:
            printAllPersons(receivers, receiversCount, "Receiver");
            break;
        case 3:
            deletePerson(receivers, &receiversCount, "Receiver");
            break;
        case 4:
            updatePerson(receivers, receiversCount, "Receiver");
            break;
        case 5:
            findPerson(receivers, receiversCount, "Receiver");
            break;
        case 6: {
            system("CLS");
            int personChoice;
            printf("1. Ascending\n2. Descending\n");
            printf("Enter your choice: ");
            scanf("%d", &personChoice);
            getchar();

            if (personChoice == 1) {
                sortPersonById(receivers, receiversCount, 1);
                printf("Receivers sorted by ID (Ascending)!\n");
            } else if (personChoice == 2) {
                sortPersonById(receivers, receiversCount, 0);
                printf("Receivers sorted by ID (Descending)!\n");
            } else {
                printf("Invalid choice!\n");
            }
            system("pause");
            break;
        }
        case 7: {
            system("CLS");
            char fname[20];
            printf("Enter the filename: ");
            scanf("%s", fname);
            getchar();

            exportToFile(receivers, receiversCount, fname, "Receiver");
            printf("Exported File Successfully!\n");
            system("pause");
            break;
        }
        case 8:
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            break;
        }
    } while (choice != 8);
}

void displayShipmentMenu() {
    int choice;
    do {
        system("CLS");
        printf("\t\t   BIET DOI HIGH CODE\t\n");
        printf("====================SHIPMENT-MANAGEMENT====================\n");
        printf("==               1. Add Shipment                         ==\n");
        printf("==               2. Print Shipment List                  ==\n");
        printf("==               3. Delete Shipment By ID                ==\n");
        printf("==               4. Update Shipment By ID                ==\n");
        printf("==               5. Find Shipment By ID                  ==\n");
        printf("==               6. Sort Shipment List By ID             ==\n");
        printf("==               7. Sort Shipment List By Date           ==\n");
        printf("==               8. Export Shipment List To File         ==\n");
        printf("==               9. Return To Main Menu                  ==\n");
        printf("===========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            addShipment();
            break;
        case 2:
            printAllShipments();
            break;
        case 3:
            deleteShipment();
            break;
        case 4:
            updateShipment();
            break;
        case 5:
            findShipment();
            break;
        case 6: {
            system("CLS");
            int shipmentChoice;
            printf("1. Ascending\n2. Descending\n");
            printf("Enter your choice: ");
            scanf("%d", &shipmentChoice);
            getchar();

            if (shipmentChoice == 1) {
                sortShipmentsById(1);
                printf("Shipments sorted by ID (Ascending)!\n");
            } else if (shipmentChoice == 2) {
                sortShipmentsById(0);
                printf("Shipments sorted by ID (Descending)!\n");
            } else {
                printf("Invalid choice!\n");
            }
            system("pause");
            break;
        }
        case 7: {
            system("CLS");
            int dateChoice;
            printf("1. Ascending\n2. Descending\n");
            printf("Enter your choice: ");
            scanf("%d", &dateChoice);
            getchar();

            if (dateChoice == 1) {
                sortShipmentsByDate(1);
                printf("Shipments sorted by Date (Ascending)!\n");
            } else if (dateChoice == 2) {
                sortShipmentsByDate(0);
                printf("Shipments sorted by Date (Descending)!\n");
            } else {
                printf("Invalid choice!\n");
            }
            system("pause");
            break;
        }
        case 8: {
            system("CLS");
            char fname[20];
            printf("Enter the filename: ");
            scanf("%s", fname);
            getchar();

            exportToFileShipment(fname);
            printf("Exported File Successfully!\n");
            system("pause");
            break;
        }
        case 9:
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            break;
        }
    } while (choice != 9);
}

void displayShipperMenu() {
    int choice;
    do {
        system("CLS");
        printf("\t\t   BIET DOI HIGH CODE\t\n");
        printf("====================SHIPPER-MANAGEMENT====================\n");
        printf("==               1. Print Shipper List                  ==\n");
        printf("==               2. Set Shipper Status                  ==\n");
        printf("==               3. Export Shipper List To File         ==\n");
        printf("==               4. Return To Main Menu                 ==\n");
        printf("==========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printAllShippers();
            break;
        case 2:
            setShipperStatus();
            break;
        case 3: {
            system("CLS");
            char fname[20];
            printf("Enter the filename: ");
            scanf("%s", fname);
            getchar();

            exportToFileShipper(fname);
            printf("Exported File Successfully!\n");
            system("pause");
            break;
        }
        case 4:
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            break;
        }
    } while (choice != 4);
}
