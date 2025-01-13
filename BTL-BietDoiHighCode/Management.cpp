#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Management.h"

void Management::addPerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string name, address, id, tel;

    std::cout << "Enter " << role << " ID: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::find_if(list.begin(), list.end(), [id](const Person& p) {
        return p.id == id;
        });

    if (it != list.end()) {
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

    list.emplace_back(name, address, id, tel);
    std::cout << role << " added successfully!\n";
    system("pause");
}

void Management::printAllPersons(const LinkedList<Person>& list, const std::string& role) const {
    system("CLS");
    std::cout << std::left
        << std::setw(10) << "ID"
        << std::setw(20) << "Name"
        << std::setw(20) << "Address"
        << std::setw(16) << "Tel"
        << std::setw(10) << "Shipments" << std::endl;

    std::cout << std::string(81, '-');
    std::cout << "\n";
    for (const auto& person : list) {
        person.displayPerson();
    }
    system("pause");
}

void Management::deletePerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to delete: ";
    std::cin >> id;

    Node<Person>* current = list.find([id](const Person& p) {
        return p.getId() == id;
        });

    if (current) {
        list.remove(current->data);
        std::cout << role << " with ID " << id << " deleted successfully!\n";
        system("pause");
    }
    else {
        std::cout << role << " with ID " << id << " does not exist.\n";
        system("pause");
    }
}

void Management::updatePerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to update: ";
    std::cin >> id;

    auto it = std::find_if(list.begin(), list.end(), [id](const Person& p) {
        return p.id == id;
        });

    if (it != list.end()) {
        Person& personToUpdate = *it;
        int choice;
        std::cout << role << " found! What do you want to update?\n";
        std::cout << "1. Name\n2. Address\n3. Telephone\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string newName;
            std::cout << "Enter new name: ";
            std::getline(std::cin, newName);
            personToUpdate.updateDetails(newName, personToUpdate.address, personToUpdate.tel);
            std::cout << "Name updated successfully!\n";
            system("pause");
            break;
        }
        case 2: {
            std::string newAddress;
            std::cout << "Enter new address: ";
            std::getline(std::cin, newAddress);
            personToUpdate.updateDetails(personToUpdate.name, newAddress, personToUpdate.tel);
            std::cout << "Address updated successfully!\n";
            system("pause");
            break;
        }
        case 3: {
            std::string newTel;
            std::cout << "Enter new telephone: ";
            std::cin >> newTel;
            personToUpdate.updateDetails(personToUpdate.name, personToUpdate.address, newTel);
            std::cout << "Telephone updated successfully!\n";
            system("pause");
            break;
        }
        default:
            std::cout << "Invalid choice!\n";
            system("pause");
            break;
        }
    }
    else {
        std::cout << role << " with ID " << id << " does not exist.\n";
        system("pause");
    }
}

void Management::findPerson(const LinkedList<Person>& list, const std::string& role) const {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to find: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::find_if(list.begin(), list.end(), [id](const Person& p) {
        return p.id == id;
        });

    if (it != list.end()) {
        it->displayPerson();
        system("pause");
    }
    else {
        std::cout << role << " with ID " << id << " does not exist. Returning to main menu.\n";
        system("pause");
    }
}

void Management::sortPersonById(LinkedList<Person>& list, bool ascending) {
    std::sort(list.begin(), list.end(),
        [ascending](const Person& a, const Person& b) {
            return ascending ? (a.getId() < b.getId()) : (a.getId() > b.getId());
        });
    return;
}

void Management::exportToFile(const LinkedList<Person>& list, const std::string& filename, const std::string& role) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    outFile << role << ":\n";
    outFile << "==============================\n";
    for (const auto& person : list) {
        person.exportData(outFile);
    }
}
//---------//
void Management::addShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    system("CLS");
    int status, pstatus;
    std::string goods, ShipmentId, senderId, receiverId;
    Date sDate, rDate;

    std::cout << "Enter the information for new Shipment" << std::endl;

    auto findPersonById = [](LinkedList<Person>& persons, std::string id) -> Person& {
        for (auto& person : persons) {
            if (person.getId() == id) {
                return person;
            }
        }
        throw std::runtime_error("Person with ID not found.");
    };

    auto findShipmentById = [&list](std::string id) -> bool {
        for (auto& Shipment : list) {
            if (Shipment.getShipmentId() == id) {
                return true;
            }
        }
        return false;
    };

    std::cout << "Enter the Sender ID: ";
    std::cin >> senderId;

    Person* sender = nullptr;
    try {
        sender = &findPersonById(senders, senderId);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        system("pause");
        return;
    }

    std::cout << "Enter the Receiver ID: ";
    std::cin >> receiverId;

    Person* receiver = nullptr;
    try {
        receiver = &findPersonById(receivers, receiverId);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        system("pause");
        return;
    }

    std::cout << "Enter the Shipment ID: ";
    std::cin >> ShipmentId;

    if (findShipmentById(ShipmentId)) {
        std::cerr << "Shipment with ID " << ShipmentId << " already exists." << std::endl;
        system("pause");
        return;
    }

    std::cout << "Send Date (day month year): "; std::cin >> sDate.day >> sDate.month >> sDate.year;
    std::cout << "Receive Date (day month year): "; std::cin >> rDate.day >> rDate.month >> rDate.year;
    std::cin.ignore();
    std::cout << "Goods information: "; std::getline(std::cin, goods);
    std::cout << "Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): "; std::cin >> status;
    std::cout << "Payment Status: Unpaid (0) / Paid (1): "; std::cin >> pstatus;

    Shipment newShipment(ShipmentId, sDate, rDate, *sender, *receiver, goods, static_cast<ShipmentStatus>(status), static_cast<PaymentStatus>(pstatus));
    list.push_back(newShipment);

    sender->totalShipments++;
    receiver->totalShipments++;

    std::cout << "Shipment added successfully!" << std::endl;
    system("pause");
}

void Management::printAllShipments(const LinkedList<Shipment> list) const {
    system("CLS");
    std::cout << "All Shipments:\n";
    for (const auto& Shipment : list) {
        Shipment.displayShipment();
    }
    system("pause");
}

void Management::deleteShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to delete: ";
    std::cin >> id;

    // Tìm kiếm shipment trong danh sách liên kết
    Node<Shipment>* shipmentNode = list.find([id](const Shipment& o) {
        return o.getShipmentId() == id;
        });

    if (shipmentNode) {
        // Hàm tìm kiếm Person trong LinkedList
        auto findPersonById = [](LinkedList<Person>& persons, const std::string& id) -> Person* {
            Node<Person>* current = persons.find([id](const Person& p) {
                return p.getId() == id;
                });
            if (current) {
                return &(current->data);
            }
            return nullptr; // Trả về nullptr nếu không tìm thấy
        };

        // Tìm sender và receiver
        Person* sender = findPersonById(senders, shipmentNode->data.getSenderId());
        Person* receiver = findPersonById(receivers, shipmentNode->data.getReceiverId());

        if (!sender || !receiver) {
            std::cerr << "Error: Sender or Receiver not found!" << std::endl;
            system("pause");
            return;
        }

        // Giảm số lượng shipments của sender và receiver
        sender->totalShipments--;
        receiver->totalShipments--;

        // Xóa shipment khỏi danh sách
        list.remove(shipmentNode->data);

        std::cout << "Shipment with ID " << id << " deleted successfully!\n";
        system("pause");
    }
    else {
        std::cout << "Shipment with ID " << id << " does not exist.\n";
        system("pause");
    }
}
void Management::updateShipment(LinkedList<Shipment>& list) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to update: ";
    std::cin >> id;

    auto it = std::find_if(list.begin(), list.end(), [id](const Shipment& o) { return o.ShipmentId == id; });

    if (it != list.end()) {
        int choice;
        bool updateAgain = true;

        while (updateAgain) {
            system("CLS");
            std::cout << "\nSelect field to update for Shipment ID " << id << ":" << std::endl;
            std::cout << "1. Send Date\n";
            std::cout << "2. Receive Date\n";
            std::cout << "3. Status\n";
            std::cout << "4. Payment Status\n";
            std::cout << "5. Goods Info\n";
            std::cout << "6. Exit update\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                // Update Send Date
                Date newSendDate;
                std::cout << "Enter new Send Date (day month year): ";
                std::cin >> newSendDate.day >> newSendDate.month >> newSendDate.year;
                it->sendDate = newSendDate;
                std::cout << "Shipment with ID " << id << "'s Send Date updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                // Update Receive Date
                Date newReceiveDate;
                std::cout << "Enter new Receive Date (day month year): ";
                std::cin >> newReceiveDate.day >> newReceiveDate.month >> newReceiveDate.year;
                it->receiveDate = newReceiveDate;
                std::cout << "Shipment with ID " << id << "'s Receive Date updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                std::cout << "Enter new Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): ";
                int statusChoice; std::cin >> statusChoice; it->status = static_cast<ShipmentStatus>(statusChoice);
                std::cout << "Shipment with ID " << id << "'s Status updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                std::cout << "Enter new Payment Status: Unpaid (0) / Paid (1): ";
                int pstatusChoice; std::cin >> pstatusChoice; it->paymentStatus = static_cast<PaymentStatus>(pstatusChoice);
                std::cout << "Shipment with ID " << id << "'s Payment Status updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                std::string newGoodsInfo;
                std::cout << "Enter new Goods Info: ";
                std::cin.ignore();
                std::getline(std::cin, newGoodsInfo);
                it->goodsInfo = newGoodsInfo;
                std::cout << "Shipment with ID " << id << "'s Goods Info updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 6:
                updateAgain = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
        std::cout << "Shipment with ID " << id << " updated successfully!" << std::endl;
    }
    else {
        std::cout << "Shipment with ID " << id << " not found!" << std::endl;
        system("pause");
    }
}

void Management::findShipment(LinkedList<Shipment>& list) const {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to find: ";
    std::cin >> id;

    auto it = std::find_if(list.begin(), list.end(), [id](const Shipment& o) {
        return o.getShipmentId() == id;
        });

    if (it != list.end()) {
        it->displayShipment();
        system("pause");
    }
    else {
        std::cout << "Shipment with ID " << id << " does not exist. Returning to main menu.\n";
        system("pause");
    }
}

void Management::exportToFileShipment(const LinkedList<Shipment>& list, std::string filename, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    outFile << "ShipmentS" << "\n";
    outFile << "==============================\n";
    for (const auto& Shipment : list) {
        Shipment.exportDataShipment(outFile);
    }
}

void Management::sortShipmentsById(LinkedList<Shipment>& list, bool ascending) {
    std::sort(list.begin(), list.end(),
        [ascending](const Shipment& a, const Shipment& b) {
            return ascending ? (a.ShipmentId < b.ShipmentId) : (a.ShipmentId > b.ShipmentId);
        });
    return;
}

int compareDates(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) return d1.year < d2.year;
    if (d1.month != d2.month) return d1.month < d2.month;
    return d1.day < d2.day;
}

void Management::sortShipmentsByDate(LinkedList<Shipment>& Shipments, bool ascending) {
    std::sort(Shipments.begin(), Shipments.end(), [this, ascending](const Shipment& a, const Shipment& b) {
        return ascending ? compareDates(a.getSendDate(), b.getSendDate()) : compareDates(b.getSendDate(), a.getSendDate());
        });
}
//---------//
void Management::printAllShippers(const LinkedList<Shipper>& list) const {
    system("CLS");
    std::cout << std::left
        << std::setw(10) << "ID"
        << std::setw(20) << "Name"
        << std::setw(16) << "Tel"
        << std::setw(10) << "Shipper Status" << std::endl;
    std::cout << std::string(81, '-');
    std::cout << "\n";
    for (const auto& person : list) {
        person.displayShipper();
    }
    system("pause");
}

void Management::setShipperStatus(LinkedList<Shipper>& shippers) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipper ID to update status: ";
    std::cin >> id;

    auto it = std::find_if(shippers.begin(), shippers.end(), [id](const Shipper& o) { return o.shipperId == id; });
    if (it != shippers.end()) {
        std::cout << "Enter new Shipper Status: ReadyToDeliver (0) / Delivering (1): ";
        int newStatus; std::cin >> newStatus; it->shipperStatus = static_cast<ShipperStatus>(newStatus);
        std::cout << "Shipper with ID " << id << "'s status updated successfully!" << std::endl;
        system("pause");
    }
    else {
        std::cout << "Shipment with ID " << id << " not found!" << std::endl;
        system("pause");
    }
}

void Management::exportToFileShipper(const LinkedList<Shipper>& shippers, std::string filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    outFile << "SHIPPER" << "\n";
    outFile << "=================================\n";
    for (const auto& shipper : shippers) {
        shipper.exportDataShipper(outFile);
    }
}

void Management::addSenders() {
    senders.push_back(Person("John Smith", "Hometown", "002", "0123456789", 0));
    senders.push_back(Person("Emily Johnson", "Springfield", "003", "0987654321", 0));
    senders.push_back(Person("Michael Brown", "Lakeview", "004", "0765432109", 0));
    senders.push_back(Person("Sarah Davis", "Meadow Hills", "005", "0456789123", 0));
    senders.push_back(Person("Daniel Wilson", "Pine Grove", "006", "0543219876", 0));
    senders.push_back(Person("Jessica Martinez", "Sunset Valley", "007", "0678912345", 0));
    senders.push_back(Person("Christopher Garcia", "Riverbend", "008", "0890123456", 0));
    senders.push_back(Person("Amanda Rodriguez", "Clearwater", "009", "0987654321", 0));
    senders.push_back(Person("James Miller", "Cedar Ridge", "010", "0102030405", 0));
    senders.push_back(Person("Ashley Jackson", "Oakwood", "011", "0112233445", 0));
}
void Management::addReceivers() {
    receivers.push_back(Person("Matthew White", "Green Acres", "012", "0123245678", 0));
    receivers.push_back(Person("Elizabeth Lopez", "Golden Heights", "013", "0133456789", 0));
    receivers.push_back(Person("Joshua Hill", "Willow Creek", "014", "0144567890", 0));
    receivers.push_back(Person("Lauren Scott", "Silver Springs", "015", "0155678901", 0));
    receivers.push_back(Person("Andrew King", "Maple Grove", "016", "0166789012", 0));
    receivers.push_back(Person("Olivia Young", "Peachtree", "017", "0177890123", 0));
    receivers.push_back(Person("Ryan Clark", "Hillcrest", "018", "0188901234", 0));
    receivers.push_back(Person("Sophia Lewis", "Birchwood", "019", "0199012345", 0));
    receivers.push_back(Person("David Walker", "Lakeside", "020", "0200123456", 0));
    receivers.push_back(Person("Grace Hall", "Valley View", "021", "0211234567", 0));
}
void Management::addShipper() {
    shippers.push_back(Shipper("Nguyen Viet Anh", "01", "0866986596", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Phung Thanh Thuy", "02", "0123888888", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Tran Cong Tai", "03", "0234999999", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Nguyen Thi Tu", "04", "0345777777", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Phung Anh Tai", "05", "0456111111", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Tran Viet Tu", "06", "0567222222", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Nguyen Cong Thanh", "07", "0678333333", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Phung Viet Thuy", "08", "0789444444", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Tran Thi Anh", "09", "0866555555", ShipperStatus::ReadyToDeliver));
    shippers.push_back(Shipper("Nguyen Thanh Tu", "10", "9999999999", ShipperStatus::ReadyToDeliver));
}

