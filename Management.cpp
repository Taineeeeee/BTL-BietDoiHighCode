#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"
#include "Management.h"

void Management::addPerson(LinkedList& list, const std::string& role) {
    system("CLS");
    std::string name, address, id, tel;

    std::cout << "Enter " << role << " ID: ";
    std::cin >> id;
    std::cin.ignore();

    auto found = list.find([id](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == id;
    });

    if (found) {
        std::cout << role << " with ID " << id << " already exists. Please enter a new ID.\n";
        system("pause");
        return;
    }

    std::cout << "Enter " << role << " Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter " << role << " Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter " << role << " Tel: ";
    std::cin >> tel;
    std::cin.ignore();

    list.push_back(new Person(name, address, id, tel, 0));
    std::cout << role << " added successfully!\n";
    system("pause");
}

void Management::printAllPersons(const LinkedList& list, const std::string& role) const {
    system("CLS");
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(20) << "Address"
              << std::setw(16) << "Tel"
              << std::setw(10) << "Shipments" << std::endl;
    std::cout << std::string(81, '-') << "\n";

    list.for_each([](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        if (p) p->displayPerson();
    });
    system("pause");
}

void Management::deletePerson(LinkedList& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to delete: ";
    std::cin >> id;

    bool removed = list.remove([id](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == id;
    });

    if (removed) {
        std::cout << role << " with ID " << id << " deleted successfully!\n";
    } else {
        std::cout << role << " with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::findPerson(const LinkedList& list, const std::string& role) const {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to find: ";
    std::cin >> id;

    auto found = list.find([id](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == id;
    });

    if (found) {
        const Person* person = dynamic_cast<const Person*>(found);
        person->displayPerson();
    } else {
        std::cout << role << " with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::updatePerson(LinkedList& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to update: ";
    std::cin >> id;

    auto found = list.find([id](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == id;
    });

    if (found) {
        Person* person = dynamic_cast<Person*>(found);
        int choice;
        std::cout << "What do you want to update?\n";
        std::cout << "1. Name\n2. Address\n3. Telephone\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string newName;
            std::cout << "Enter new name: ";
            std::getline(std::cin, newName);
            person->updateDetails(newName, person->getAddress(), person->getTel());
            std::cout << "Name updated successfully!\n";
            break;
        }
        case 2: {
            std::string newAddress;
            std::cout << "Enter new address: ";
            std::getline(std::cin, newAddress);
            person->updateDetails(person->getName(), newAddress, person->getTel());
            std::cout << "Address updated successfully!\n";
            break;
        }
        case 3: {
            std::string newTel;
            std::cout << "Enter new telephone: ";
            std::cin >> newTel;
            person->updateDetails(person->getName(), person->getAddress(), newTel);
            std::cout << "Telephone updated successfully!\n";
            break;
        }
        default:
            std::cout << "Invalid choice!\n";
        }
    } else {
        std::cout << role << " with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::addShipment(LinkedList& list, LinkedList& senders, LinkedList& receivers) {
    system("CLS");
    int status, pstatus;
    std::string goods, ShipmentId, senderId, receiverId;
    Date sDate, rDate;

    std::cout << "Enter the Sender ID: ";
    std::cin >> senderId;

    Person* sender = nullptr;
    auto foundSender = senders.find([senderId](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == senderId;
    });

    if (!foundSender) {
        std::cerr << "Sender with ID " << senderId << " not found.\n";
        system("pause");
        return;
    }
    sender = dynamic_cast<Person*>(foundSender);

    std::cout << "Enter the Receiver ID: ";
    std::cin >> receiverId;

    Person* receiver = nullptr;
    auto foundReceiver = receivers.find([receiverId](const ListElement* elem) {
        const Person* p = dynamic_cast<const Person*>(elem);
        return p && p->getId() == receiverId;
    });

    if (!foundReceiver) {
        std::cerr << "Receiver with ID " << receiverId << " not found.\n";
        system("pause");
        return;
    }
    receiver = dynamic_cast<Person*>(foundReceiver);

    std::cout << "Enter the Shipment ID: ";
    std::cin >> ShipmentId;

    auto foundShipment = list.find([ShipmentId](const ListElement* elem) {
        const Shipment* s = dynamic_cast<const Shipment*>(elem);
        return s && s->getShipmentId() == ShipmentId;
    });

    if (foundShipment) {
        std::cerr << "Shipment with ID " << ShipmentId << " already exists.\n";
        system("pause");
        return;
    }

    std::cout << "Send Date (day month year): "; std::cin >> sDate.day >> sDate.month >> sDate.year;
    std::cout << "Receive Date (day month year): "; std::cin >> rDate.day >> rDate.month >> rDate.year;
    std::cin.ignore();
    std::cout << "Goods information: "; std::getline(std::cin, goods);
    std::cout << "Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): "; std::cin >> status;
    std::cout << "Payment Status: Unpaid (0) / Paid (1): "; std::cin >> pstatus;

    list.push_back(new Shipment(ShipmentId, sDate, rDate, *sender, *receiver, goods, static_cast<ShipmentStatus>(status), static_cast<PaymentStatus>(pstatus)));

    sender->incrementShipments();
    receiver->incrementShipments();

    std::cout << "Shipment added successfully!\n";
    system("pause");
}

void Management::printAllShipments(const LinkedList& list) const {
    system("CLS");
    std::cout << "All Shipments:\n";
    list.for_each([](const ListElement* elem) {
        const Shipment* s = dynamic_cast<const Shipment*>(elem);
        if (s) s->displayShipment();
    });
    system("pause");
}

void Management::deleteShipment(LinkedList& list) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to delete: ";
    std::cin >> id;

    bool removed = list.remove([id](const ListElement* elem) {
        const Shipment* s = dynamic_cast<const Shipment*>(elem);
        return s && s->getShipmentId() == id;
    });

    if (removed) {
        std::cout << "Shipment with ID " << id << " deleted successfully!\n";
    } else {
        std::cout << "Shipment with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::findShipment(const LinkedList& list) const {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to find: ";
    std::cin >> id;

    auto found = list.find([id](const ListElement* elem) {
        const Shipment* s = dynamic_cast<const Shipment*>(elem);
        return s && s->getShipmentId() == id;
    });

    if (found) {
        const Shipment* shipment = dynamic_cast<const Shipment*>(found);
        shipment->displayShipment();
    } else {
        std::cout << "Shipment with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::updateShipment(LinkedList& list) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to update: ";
    std::cin >> id;

    auto found = list.find([id](const ListElement* elem) {
        const Shipment* s = dynamic_cast<const Shipment*>(elem);
        return s && s->getShipmentId() == id;
    });

    if (found) {
        Shipment* shipment = dynamic_cast<Shipment*>(found);
        int choice;
        bool updateAgain = true;

        while (updateAgain) {
            system("CLS");
            std::cout << "What do you want to update for Shipment with ID " << id << "?\n";
            std::cout << "1. Send Date\n2. Receive Date\n3. Status\n4. Payment Status\n5. Goods Info\n6. Exit\nEnter your choice: ";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
            case 1: {
                Date newSendDate;
                std::cout << "Enter new Send Date (day month year): ";
                std::cin >> newSendDate.day >> newSendDate.month >> newSendDate.year;
                shipment->setSendDate(newSendDate);
                std::cout << "Send Date updated successfully!\n";
                break;
            }
            case 2: {
                Date newReceiveDate;
                std::cout << "Enter new Receive Date (day month year): ";
                std::cin >> newReceiveDate.day >> newReceiveDate.month >> newReceiveDate.year;
                shipment->setReceiveDate(newReceiveDate);
                std::cout << "Receive Date updated successfully!\n";
                break;
            }
            case 3: {
                int newStatus;
                std::cout << "Enter new Status (0 = Pending, 1 = InTransit, 2 = Delivered, 3 = Returned): ";
                std::cin >> newStatus;
                shipment->setStatus(static_cast<ShipmentStatus>(newStatus));
                std::cout << "Status updated successfully!\n";
                break;
            }
            case 4: {
                int newPaymentStatus;
                std::cout << "Enter new Payment Status (0 = Unpaid, 1 = Paid): ";
                std::cin >> newPaymentStatus;
                shipment->setPaymentStatus(static_cast<PaymentStatus>(newPaymentStatus));
                std::cout << "Payment Status updated successfully!\n";
                break;
            }
            case 5: {
                std::string newGoodsInfo;
                std::cout << "Enter new Goods Info: ";
                std::getline(std::cin, newGoodsInfo);
                shipment->setGoodsInfo(newGoodsInfo);
                std::cout << "Goods Info updated successfully!\n";
                break;
            }
            case 6:
                updateAgain = false;
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
        }
    } else {
        std::cout << "Shipment with ID " << id << " does not exist.\n";
    }
    system("pause");
}

void Management::addShipper(LinkedList& list) {
    system("CLS");
    std::string name, id, tel;
    int status;

    std::cout << "Enter Shipper ID: ";
    std::cin >> id;
    std::cin.ignore();

    auto found = list.find([id](const ListElement* elem) {
        const Shipper* s = dynamic_cast<const Shipper*>(elem);
        return s && s->getId() == id;
    });

    if (found) {
        std::cout << "Shipper with ID " << id << " already exists.\n";
        system("pause");
        return;
    }

    std::cout << "Enter Shipper Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Shipper Tel: ";
    std::cin >> tel;
    std::cout << "Enter Shipper Status (0 = ReadyToDeliver, 1 = Delivering): ";
    std::cin >> status;

    list.push_back(new Shipper(name, id, tel, static_cast<ShipperStatus>(status)));
    std::cout << "Shipper added successfully!\n";
    system("pause");
}

void Management::printAllShippers(const LinkedList& list) const {
    system("CLS");
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(16) << "Tel"
              << std::setw(20) << "Status" << std::endl;
    std::cout << std::string(81, '-') << "\n";

    list.for_each([](const ListElement* elem) {
        const Shipper* s = dynamic_cast<const Shipper*>(elem);
        if (s) s->displayShipper();
    });
    system("pause");
}


