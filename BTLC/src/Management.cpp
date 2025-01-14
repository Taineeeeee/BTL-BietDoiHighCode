#include "Management.h"

Person senders[100];
int sendersCount = 0;

Person receivers[100];
int receiversCount = 0;

Shipment Shipments[100];
int ShipmentsCount = 0;

Shipper shippers[100];
int shippersCount = 0;

void addPerson(Person* list, int* listSize, const char* role)
{
    system("CLS");
    char name[100], address[100], id[100], tel[100];

    printf("Enter %s ID: ", role);
    scanf("%s", id);
    getchar();

    Person* personToAdd = NULL;
    for (int i = 0; i < *listSize; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            personToAdd = &list[i];
            break;
        }
    }

    if (personToAdd) {
        printf("%s with ID %s already exists. Please enter a new ID.\n", role, id);
        system("pause");
        return;
    }

    printf("Enter %s Name: ", role);
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter %s Address: ", role);
    fgets(address, 100, stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("Enter %s Tel: ", role);
    scanf("%s", tel);
    getchar();

    strcpy(list[*listSize].name, name);
    strcpy(list[*listSize].address, address);
    strcpy(list[*listSize].id, id);
    strcpy(list[*listSize].tel, tel);

    (*listSize)++;

    printf("%s added successfully!\n", role);
    system("pause");
}

void printAllPersons(const Person* list, int listSize, const char* role)
{
    system("CLS");
    printf("%-10s %-20s %-20s %-16s %-10s\n", "ID", "Name", "Address", "Tel", "Shipments");
    printf("%s\n", "---------------------------------------------------------------------------------");

    for (int i = 0; i < listSize; ++i) {
        printf("%-10s %-20s %-20s %-16s %-10d\n",
        list[i].id,
        list[i].name,
        list[i].address,
        list[i].tel,
        list[i].shipments);
    }

    system("pause");
}

void deletePerson(Person* list, int* listSize, const char* role)
{
    system("CLS");
    int i;
    char id[100];

    printf("Enter %s ID to delete: ", role);
    scanf("%s", id);
    getchar();

    Person* personToDelete = NULL;
    for (i = 0; i < *listSize; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            personToDelete = &list[i];
            break;
        }
    }

    if (personToDelete) {
        for (; i < *listSize - 1; ++i) {
            list[i] = list[i + 1];
        }
        (*listSize)--;
        printf("%s with ID %s deleted successfully!\n", role, id);
    } else {
        printf("%s with ID %s does not exist.\n", role, id);
        system("pause");
    }
}

void updatePerson(Person* list, int listSize, const char* role)
{
    system("CLS");
    char id[50];
    printf("Enter %s ID to update: ", role);
    scanf("%s", id);
    getchar();

    Person* personToUpdate = NULL;
    for (int i = 0; i < listSize; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            personToUpdate = &list[i];
            break;
        }
    }

    if (personToUpdate) {
        int choice;
        printf("%s found! What do you want to update?\n", role);
        printf("1. Name\n2. Address\n3. Telephone\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: {
            char newName[100];
            printf("Enter new name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            strcpy(personToUpdate->name, newName);
            printf("Name updated successfully!\n");
            system("pause");
            break;
        }
        case 2: {
            char newAddress[200];
            printf("Enter new address: ");
            fgets(newAddress, sizeof(newAddress), stdin);
            newAddress[strcspn(newAddress, "\n")] = '\0';
            strcpy(personToUpdate->address, newAddress);
            printf("Address updated successfully!\n");
            system("pause");
            break;
        }
        case 3: {
            char newTel[15];
            printf("Enter new telephone: ");
            scanf("%s", newTel);
            getchar();
            strcpy(personToUpdate->tel, newTel);
            printf("Telephone updated successfully!\n");
            system("pause");
            break;
        }
        default:
            printf("Invalid choice!\n");
            system("pause");
            break;
        }
    } else {
        printf("%s with ID %s does not exist.\n", role, id);
        system("pause");
    }
}

void findPerson(const Person* list, int listSize, const char* role)
{
    system("CLS");
    char id[100];

    printf("Enter %s ID to find: ", role);
    scanf("%s", id);
    getchar();

    int found = 0;
    for (int i = 0; i < listSize; ++i) {
        if (strcmp(list[i].id, id) == 0) {
            printf("%-10s %-20s %-20s %-16s %-10d\n",
            list[i].id,
            list[i].name,
            list[i].address,
            list[i].tel,
            list[i].shipments);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%s with ID %s does not exist. Returning to main menu.\n", role, id);
    }
    system("pause");
}

int compareAscending(const void* a, const void* b)
{
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return strcmp(personA->id, personB->id);
}

int compareDescending(const void* a, const void* b)
{
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return strcmp(personB->id, personA->id);
}

void sortPersonById(Person* list, int listSize, int ascending)
{
    if (ascending) {
        qsort(list, listSize, sizeof(Person), compareAscending);
    } else {
        qsort(list, listSize, sizeof(Person), compareDescending);
    }
}

void exportToFile(const Person* list, int listSize, const char* filename, const char* role)
{
    FILE* outFile = fopen(filename, "w");
    if (!outFile) {
        fprintf(stderr, "Could not open the file!\n");
        return;
    }

    fprintf(outFile, "%s:\n", role);
    fprintf(outFile, "==============================\n");
    for (int i = 0; i < listSize; ++i) {
        fprintf(outFile, "Name: %s\n", list[i].name);
        fprintf(outFile, "Address: %s\n", list[i].address);
        fprintf(outFile, "Telephone: %s\n", list[i].tel);
        fprintf(outFile, "ID: %s\n", list[i].id);
        fprintf(outFile, "-----------------------------\n");
    }
    fclose(outFile);
}

int findShipmentById(const char* id)
{
    for (int i = 0; i < ShipmentsCount; ++i) {
        if (strcmp(Shipments[i].ShipmentId, id) == 0) {
            return 1;
        }
    }
    return 0;
}

void addShipment()
{
    system("CLS");
    int status, pstatus;
    char goods[100], shipmentId[100], senderId[100], receiverId[100];
    Date sDate, rDate;

    printf("Enter the information for new Shipment\n");

    printf("Enter the Sender ID: ");
    scanf("%s", senderId);

    Person* sender = NULL;
    for (int i = 0; i < sendersCount; ++i) {
        if (strcmp(senders[i].id, senderId) == 0) {
            sender = &senders[i];
            break;
        }
    }

    if (sender == NULL) {
        printf("Person with ID %s not found.\n", senderId);
        system("pause");
        return;
    }

    printf("Enter the Receiver ID: ");
    scanf("%s", receiverId);

    Person* receiver = NULL;
    for (int i = 0; i < receiversCount; ++i) {
        if (strcmp(receivers[i].id, receiverId) == 0) {
            receiver = &receivers[i];
            break;
        }
    }

    if (receiver == NULL) {
        printf("Person with ID %s not found.\n", receiverId);
        system("pause");
        return;
    }

    printf("Enter the Shipment ID: ");
    fflush(stdin);
    scanf("%s", shipmentId);

    if (findShipmentById(shipmentId)) {
        printf("Shipment with ID %s already exists.\n", shipmentId);
        system("pause");
        return;
    }

    printf("Send Date (day month year): ");
    fflush(stdin);
    scanf("%d %d %d", &sDate.day, &sDate.month, &sDate.year);
    printf("Receive Date (day month year): ");
    fflush(stdin);
    scanf("%d %d %d", &rDate.day, &rDate.month, &rDate.year);
    getchar();
    printf("Goods information: ");
    fgets(goods, 100, stdin);
    goods[strcspn(goods, "\n")] = 0;
    printf("Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): ");
    scanf("%d", &status);
    printf("Payment Status: Unpaid (0) / Paid (1): ");
    scanf("%d", &pstatus);

    Shipment newShipment;
    strcpy(newShipment.ShipmentId, shipmentId);
    newShipment.sendDate = sDate;
    newShipment.receiveDate = rDate;
    newShipment.sender = *sender;
    newShipment.receiver = *receiver;
    strcpy(newShipment.goodsInfo, goods);
    newShipment.status = (ShipmentStatus)status;
    newShipment.paymentStatus = (PaymentStatus)pstatus;

    Shipments[ShipmentsCount] = newShipment;
    ShipmentsCount++;

    printf("Shipment added successfully!\n");
    system("pause");
}

void displayPersonForShipment(const Person* person)
{
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
}

char* dateToString(const Date date) {
    char* buffer = (char*)malloc(11 * sizeof(char));
    sprintf(buffer, "%02d/%02d/%04d", date.day, date.month, date.year);
    return buffer;
}

void displayShipment(const Shipment* shipment)
{
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "ID", "Send Date", "Receive Date", "Goods Info", "Status", "Payment Status");
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n",
           shipment->ShipmentId,
           dateToString(shipment->sendDate),
           dateToString(shipment->receiveDate),
           shipment->goodsInfo,
           shipment->status == Pending ? "Pending" :
           shipment->status == InTransit ? "In Transit" :
           shipment->status == Delivered ? "Delivered" : "Returned",
           shipment->paymentStatus == Unpaid ? "Unpaid" : "Paid");

    printf("-----Sender information:\n");
    displayPersonForShipment(&shipment->sender);

    printf("-----Receiver information:\n");
    displayPersonForShipment(&shipment->receiver);

    for (int i = 0; i < 100; i++) {
        putchar('-');
    }
    printf("\n");
}

void printAllShipments()
{
    system("CLS");
    printf("All Shipments:\n");
    for (int i = 0; i < ShipmentsCount; ++i) {
        displayShipment(&Shipments[i]);
    }
    system("pause");
}

void deleteShipment()
{
    system("CLS");
    int i;
    char id[100];
    printf("Enter Shipment ID to delete: ");
    scanf("%s", id);

    Shipment* shipmentToDelete = NULL;
    for (i = 0; i < ShipmentsCount; ++i) {
        if (strcmp(Shipments[i].ShipmentId, id) == 0) {
            shipmentToDelete = &Shipments[i];
            break;
        }
    }

    if (shipmentToDelete) {
        for (; i < ShipmentsCount - 1; ++i) {
            Shipments[i] = Shipments[i + 1];
        }
        ShipmentsCount--;
        printf("Shipment with ID %s deleted successfully!\n", id);
        system("pause");
    } else {
        printf("Shipment with ID %s does not exist.\n", id);
        system("pause");
    }
}

void updateShipment()
{
    system("CLS");
    char id[50];
    printf("Enter Shipment ID to update: ");
    scanf("%s", id);
    getchar();

    Shipment* shipmentToUpdate = NULL;
    for (int i = 0; i < ShipmentsCount; ++i) {
        if (strcmp(Shipments[i].ShipmentId, id) == 0) {
            shipmentToUpdate = &Shipments[i];
            break;
        }
    }

    if (shipmentToUpdate) {
        int choice;
        int updateAgain = 1;

        while (updateAgain) {
            system("CLS");
            printf("\nSelect field to update for Shipment ID %s:\n", id);
            printf("1. Send Date\n");
            printf("2. Receive Date\n");
            printf("3. Status\n");
            printf("4. Payment Status\n");
            printf("5. Goods Info\n");
            printf("6. Exit update\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice) {
            case 1: {
                Date newSendDate;
                printf("Enter new Send Date (day month year): ");
                scanf("%d %d %d", &newSendDate.day, &newSendDate.month, &newSendDate.year);
                shipmentToUpdate->sendDate = newSendDate;
                printf("Shipment with ID %s's Send Date updated successfully!\n", id);
                system("pause");
                break;
            }
            case 2: {
                Date newReceiveDate;
                printf("Enter new Receive Date (day month year): ");
                scanf("%d %d %d", &newReceiveDate.day, &newReceiveDate.month, &newReceiveDate.year);
                shipmentToUpdate->receiveDate = newReceiveDate;
                printf("Shipment with ID %s's Receive Date updated successfully!\n", id);
                system("pause");
                break;
            }
            case 3: {
                printf("Enter new Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): ");
                int statusChoice;
                scanf("%d", &statusChoice);
                shipmentToUpdate->status = (ShipmentStatus)statusChoice;
                printf("Shipment with ID %s's Status updated successfully!\n", id);
                system("pause");
                break;
            }
            case 4: {
                printf("Enter new Payment Status: Unpaid (0) / Paid (1): ");
                int pstatusChoice;
                scanf("%d", &pstatusChoice);
                shipmentToUpdate->paymentStatus = (PaymentStatus)pstatusChoice;
                printf("Shipment with ID %s's Payment Status updated successfully!\n", id);
                system("pause");
                break;
            }
            case 5: {
                char newGoodsInfo[100];
                printf("Enter new Goods Info: ");
                getchar();
                fgets(newGoodsInfo, sizeof(newGoodsInfo), stdin);
                newGoodsInfo[strcspn(newGoodsInfo, "\n")] = '\0';
                strncpy(shipmentToUpdate->goodsInfo, newGoodsInfo, 100);
                printf("Shipment with ID %s's Goods Info updated successfully!\n", id);
                system("pause");
                break;
            }
            case 6:
                updateAgain = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        printf("Shipment with ID %s updated successfully!\n", id);
    } else {
        printf("Shipment with ID %s not found!\n", id);
        system("pause");
    }
}

void findShipment()
{
    system("CLS");
    char id[100];

    printf("Enter Shipment ID to find: ");
    scanf("%s", id);
    getchar();

    int found = 0;
    for (int i = 0; i < ShipmentsCount; ++i) {
        if (strcmp(Shipments[i].ShipmentId, id) == 0) {
            displayShipment(&Shipments[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Shipment with ID %s does not exist. Returning to main menu.\n", id);
    }
    system("pause");
}

int compareDescendingShipment(const void* a, const void* b)
{
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    return strcmp(shipmentA->ShipmentId, shipmentB->ShipmentId);
}

int compareAscendingShipment(const void* a, const void* b)
{
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    return strcmp(shipmentB->ShipmentId, shipmentA->ShipmentId);
}

void sortShipmentsById(int ascending)
{
    if (ascending) {
        qsort(Shipments, ShipmentsCount, sizeof(Shipment), compareAscendingShipment);
    } else {
        qsort(Shipments, ShipmentsCount, sizeof(Shipment), compareDescendingShipment);
    }
}

int compareAscendingShipmentDate(const void* a, const void* b)
{
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    if(shipmentA->sendDate.year != shipmentB->sendDate.year)
        return shipmentA->sendDate.year < shipmentB->sendDate.year;
    if(shipmentA->sendDate.month != shipmentB->sendDate.month)
        return shipmentA->sendDate.month < shipmentB->sendDate.month;
    return shipmentA->sendDate.day < shipmentB->sendDate.day;
}

int compareDescendingShipmentDate(const void* a, const void* b)
{
    Shipment* shipmentA = (Shipment*)a;
    Shipment* shipmentB = (Shipment*)b;
    if(shipmentA->sendDate.year != shipmentB->sendDate.year)
        return shipmentA->sendDate.year > shipmentB->sendDate.year;
    if(shipmentA->sendDate.month != shipmentB->sendDate.month)
        return shipmentA->sendDate.month > shipmentB->sendDate.month;
    return shipmentA->sendDate.day > shipmentB->sendDate.day;
}

void sortShipmentsByDate(int ascending)
{
    if (ascending) {
        qsort(Shipments, ShipmentsCount, sizeof(Shipment), compareAscendingShipmentDate);
    } else {
        qsort(Shipments, ShipmentsCount, sizeof(Shipment), compareDescendingShipmentDate);
    }
}

void exportToFileShipment(const char* filename)
{
    FILE* outFile = fopen(filename, "w");
    if (!outFile) {
        fprintf(stderr, "Could not open the file!\n");
        return;
    }

    fprintf(outFile, "Shipments:\n");
    fprintf(outFile, "==============================\n");
    for (int i = 0; i < ShipmentsCount; ++i) {
        fprintf(outFile, "Shipment ID: %d\n", Shipments[i].ShipmentId);
        fprintf(outFile, "Goods Info: %s\n", Shipments[i].goodsInfo);
        fprintf(outFile, "Send Date: %s\n", dateToString(Shipments[i].sendDate));
        fprintf(outFile, "Receice Date: %s\n", dateToString(Shipments[i].receiveDate));
        fprintf(outFile, "Id Sender: %s\n", Shipments[i].sender.id);
        fprintf(outFile, "Name Sender: %s\n", Shipments[i].sender.name);
        fprintf(outFile, "Address Sender: %s\n", Shipments[i].sender.address);
        fprintf(outFile, "Tel Sender: %s\n", Shipments[i].sender.tel);
        fprintf(outFile, "Id Receiver: %s\n", Shipments[i].receiver.id);
        fprintf(outFile, "Name Receiver: %s\n", Shipments[i].receiver.name);
        fprintf(outFile, "Address Receiver: %s\n", Shipments[i].receiver.address);
        fprintf(outFile, "Tel Receiver: %s\n", Shipments[i].receiver.tel);
        fprintf(outFile, "-----------------------------\n");
    }

    fclose(outFile);
}

void setShipperStatus()
{
    system("CLS");
    char id[50];
    printf("Enter Shipper ID to update status: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < shippersCount; i++) {
        if (strcmp(shippers[i].shipperId, id) == 0) {
            printf("Enter new Shipper Status: ReadyToDeliver (0) / Delivering (1): ");
            int newStatus;
            scanf("%d", &newStatus);
            shippers[i].shipperStatus = (ShipperStatus)newStatus;
            printf("Shipper with ID %s's status updated successfully!\n", id);
            system("pause");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Shipper with ID %s not found!\n", id);
        system("pause");
    }
}

void exportToFileShipper(const char* filename)
{
    FILE* outFile = fopen(filename, "w");
    if (!outFile) {
        fprintf(stderr, "Could not open the file!\n");
        return;
    }

    fprintf(outFile, "SHIPPER\n");
    fprintf(outFile, "=================================\n");
    for (int i = 0; i < shippersCount; ++i) {
        fprintf(outFile, "Shipper ID: %s\n", shippers[i].shipperId);
        fprintf(outFile, "Shipper Name: %s\n", shippers[i].name);
        fprintf(outFile, "Shipper Status: %d\n", shippers[i].shipperStatus);
        fprintf(outFile, "-----------------------------\n");
    }

    fclose(outFile);
}

void printAllShippers()
{
    system("CLS");
    printf("%-10s %-20s %-16s\n", "ID", "Name", "Tel");
    printf("%s\n", "---------------------------------------------------------------------------------");

    for (int i = 0; i < shippersCount; ++i) {
        printf("%-10s %-20s %-16s\n",
        shippers[i].shipperId,
        shippers[i].name,
        shippers[i].tel);
    }
    system("pause");
}

void addSenders() {
    if (sendersCount < 100) senders[sendersCount++] = (Person){"John Smith", "Hometown", "002", "0123456789", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Emily Johnson", "Springfield", "003", "0987654321", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Michael Brown", "Lakeview", "004", "0765432109", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Sarah Davis", "Meadow Hills", "005", "0456789123", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Daniel Wilson", "Pine Grove", "006", "0543219876", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Jessica Martinez", "Sunset Valley", "007", "0678912345", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Christopher Garcia", "Riverbend", "008", "0890123456", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Amanda Rodriguez", "Clearwater", "009", "0987654321", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"James Miller", "Cedar Ridge", "010", "0102030405", 0};
    if (sendersCount < 100) senders[sendersCount++] = (Person){"Ashley Jackson", "Oakwood", "011", "0112233445", 0};
}

void addReceivers() {
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Matthew White", "Green Acres", "012", "0123245678", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Elizabeth Lopez", "Golden Heights", "013", "0133456789", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Joshua Hill", "Willow Creek", "014", "0144567890", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Lauren Scott", "Silver Springs", "015", "0155678901", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Andrew King", "Maple Grove", "016", "0166789012", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Olivia Young", "Peachtree", "017", "0177890123", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Ryan Clark", "Hillcrest", "018", "0188901234", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Sophia Lewis", "Birchwood", "019", "0199012345", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"David Walker", "Lakeside", "020", "0200123456", 0};
    if (receiversCount < 100) receivers[receiversCount++] = (Person){"Grace Hall", "Valley View", "021", "0211234567", 0};
}

void addShippers() {
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Nguyen Viet Anh", "01", "0866986596", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Phung Thanh Thuy", "02", "0123888888", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Tran Cong Tai", "03", "0234999999", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Nguyen Thi Tu", "04", "0345777777", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Phung Anh Tai", "05", "0456111111", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Tran Viet Tu", "06", "0567222222", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Nguyen Cong Thanh", "07", "0678333333", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Phung Viet Thuy", "08", "0789444444", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Tran Thi Anh", "09", "0866555555", ReadyToDeliver};
    if (shippersCount < 100) shippers[shippersCount++] = (Shipper){"Nguyen Thanh Tu", "10", "9999999999", ReadyToDeliver};
}
