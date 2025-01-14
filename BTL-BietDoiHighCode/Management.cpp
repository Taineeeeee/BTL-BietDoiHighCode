#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Management.h"

// Thêm một người vào danh sách (sender hoặc receiver)
void Management::addPerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string name, address, id, tel;

    std::cout << "Enter " << role << " ID: ";
    std::cin >> id;
    std::cin.ignore();

    bool idExists = false;

    // Kiểm tra xem ID đã tồn tại trong danh sách chưa
    list.for_each([&id, &idExists](const Person& p) {
        if (p.id == id) {
            idExists = true;
        }
        });

    if (idExists) {
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

    list.push_back(Person(name, address, id, tel));
    std::cout << role << " added successfully!\n";
    system("pause");
}

// Hiển thị tất cả người trong danh sách (senders hoặc receivers)
void Management::printAllPersons(const LinkedList<Person>& list, const std::string& role) const {
    system("CLS");
    std::cout << std::left
        << std::setw(10) << "ID"
        << std::setw(20) << "Name"
        << std::setw(20) << "Address"
        << std::setw(16) << "Tel"
        << std::setw(10) << "Shipments" << std::endl;

    std::cout << std::string(81, '-') << "\n";
    list.for_each([](const Person& person) {
        person.displayPerson();
        });
    system("pause");
}

// Xóa một người khỏi danh sách (sender hoặc receiver)
void Management::deletePerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to delete: ";
    std::cin >> id;

    Node<Person>* current = list.find([id](const Person& p) {
        return p.id == id;
        });

    if (current) {
        list.remove([id](const Person& p) {
            return p.id == id;
            });

        std::cout << role << " with ID " << id << " deleted successfully!\n";
        system("pause");
    }
    else {
        std::cout << role << " with ID " << id << " does not exist.\n";
        system("pause");
    }
}

// Cập nhật thông tin của một người trong danh sách (sender hoặc receiver)
void Management::updatePerson(LinkedList<Person>& list, const std::string& role) {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to update: ";
    std::cin >> id;

    Node<Person>* current = list.find([id](const Person& p) {
        return p.id == id;
        });

    if (current) {
        Person& personToUpdate = current->data;
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

// Tìm kiếm một người trong danh sách (sender hoặc receiver)
void Management::findPerson(const LinkedList<Person>& list, const std::string& role) const {
    system("CLS");
    std::string id;
    std::cout << "Enter " << role << " ID to find: ";
    std::cin >> id;
    std::cin.ignore();

    Node<Person>* current = list.find([id](const Person& p) {
        return p.id == id;
        });

    if (current) {
        current->data.displayPerson();
        system("pause");
    }
    else {
        std::cout << role << " with ID " << id << " does not exist. Returning to main menu.\n";
        system("pause");
    }
}

// Sắp xếp danh sách người theo ID (tăng dần hoặc giảm dần)
void Management::sortPersonById(LinkedList<Person>& list, bool ascending) {
    if (list.get_size() <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node<Person>* current = list.getHead();
        Node<Person>* prev = nullptr;

        while (current->next) {
            bool shouldSwap = ascending ? (current->data.getId() > current->next->data.getId())
                : (current->data.getId() < current->next->data.getId());

            if (shouldSwap) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}

// Xuất danh sách người ra file
void Management::exportToFilePerson(const LinkedList<Person>& people, std::string filename, const std::string& role) {
    std::ofstream outFile(filename + ".txt");
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    outFile << role << "\n";
    outFile << "=================================\n";

    people.for_each([&outFile](const Person& person) {
        person.exportDataPerson(outFile);
        });

    outFile.close();
}

// Thêm một shipment mới vào danh sách
void Management::addShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    system("CLS");
    int status, pstatus;
    std::string goods, ShipmentId, senderId, receiverId;
    Date sDate, rDate;

    std::cout << "Enter the information for new Shipment" << std::endl;

    auto findPersonById = [](LinkedList<Person>& persons, const std::string& id) -> Person* {
        Person* result = nullptr;
        persons.for_each([&id, &result](const Person& person) {
            if (person.id == id) {
                result = const_cast<Person*>(&person);
            }
            });
        return result;
    };

    auto findShipmentById = [&list](const std::string& id) -> bool {
        bool exists = false;
        list.for_each([&id, &exists](const Shipment& shipment) {
            if (shipment.getShipmentId() == id) {
                exists = true;
            }
            });
        return exists;
    };

    std::cout << "Enter the Sender ID: ";
    std::cin >> senderId;

    Person* sender = findPersonById(senders, senderId);
    if (!sender) {
        std::cerr << "Sender with ID " << senderId << " not found." << std::endl;
        system("pause");
        return;
    }

    std::cout << "Enter the Receiver ID: ";
    std::cin >> receiverId;

    Person* receiver = findPersonById(receivers, receiverId);
    if (!receiver) {
        std::cerr << "Receiver with ID " << receiverId << " not found." << std::endl;
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

// Hiển thị tất cả shipments trong danh sách
void Management::printAllShipments(const LinkedList<Shipment>& list) const {
    system("CLS");
    std::cout << "All Shipments:\n";

    list.for_each([](const Shipment& shipment) {
        shipment.displayShipment();
        });

    system("pause");
}

// Xóa một shipment khỏi danh sách
void Management::deleteShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to delete: ";
    std::cin >> id;

    Node<Shipment>* shipmentNode = list.find([id](const Shipment& o) {
        return o.getShipmentId() == id;
        });

    if (shipmentNode) {
        auto findPersonById = [](LinkedList<Person>& persons, const std::string& id) -> Person* {
            Node<Person>* current = persons.find([id](const Person& p) {
                return p.getId() == id;
                });
            if (current) {
                return &(current->data);
            }
            return nullptr;
        };

        Person* sender = findPersonById(senders, shipmentNode->data.sender.getId());
        Person* receiver = findPersonById(receivers, shipmentNode->data.receiver.getId());

        if (!sender || !receiver) {
            std::cerr << "Error: Sender or Receiver not found!" << std::endl;
            system("pause");
            return;
        }

        sender->totalShipments--;
        receiver->totalShipments--;

        list.remove([id](const Shipment& shipment) {
            return shipment.getShipmentId() == id;
            });

        std::cout << "Shipment with ID " << id << " deleted successfully!\n";
        system("pause");
    }
    else {
        std::cout << "Shipment with ID " << id << " does not exist.\n";
        system("pause");
    }
}

// Cập nhật thông tin của một shipment
void Management::updateShipment(LinkedList<Shipment>& list) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to update: ";
    std::cin >> id;

    Node<Shipment>* it = list.find([id](const Shipment& shipment) {
        return shipment.ShipmentId == id;
        });

    if (it) {
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
                Date newSendDate;
                std::cout << "Enter new Send Date (day month year): ";
                std::cin >> newSendDate.day >> newSendDate.month >> newSendDate.year;
                it->data.sendDate = newSendDate;
                std::cout << "Shipment with ID " << id << "'s Send Date updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                Date newReceiveDate;
                std::cout << "Enter new Receive Date (day month year): ";
                std::cin >> newReceiveDate.day >> newReceiveDate.month >> newReceiveDate.year;
                it->data.receiveDate = newReceiveDate;
                std::cout << "Shipment with ID " << id << "'s Receive Date updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                std::cout << "Enter new Shipment Status: Pending (0) / InTransit (1) / Delivered (2) / Returned (3): ";
                int statusChoice; std::cin >> statusChoice; it->data.status = static_cast<ShipmentStatus>(statusChoice);
                std::cout << "Shipment with ID " << id << "'s Status updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                std::cout << "Enter new Payment Status: Unpaid (0) / Paid (1): ";
                int pstatusChoice; std::cin >> pstatusChoice; it->data.paymentStatus = static_cast<PaymentStatus>(pstatusChoice);
                std::cout << "Shipment with ID " << id << "'s Payment Status updated successfully!" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                std::string newGoodsInfo;
                std::cout << "Enter new Goods Info: ";
                std::cin.ignore();
                std::getline(std::cin, newGoodsInfo);
                it->data.goodsInfo = newGoodsInfo;
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

// Tìm kiếm một shipment trong danh sách
void Management::findShipment(const LinkedList<Shipment>& list) const {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipment ID to find: ";
    std::cin >> id;

    Node<Shipment>* foundNode = list.find([id](const Shipment& shipment) {
        return shipment.getShipmentId() == id;
        });

    if (foundNode) {
        foundNode->data.displayShipment();
        system("pause");
    }
    else {
        std::cout << "Shipment with ID " << id << " does not exist. Returning to main menu.\n";
        system("pause");
    }
}

// Xuất danh sách shipments ra file
void Management::exportToFileShipment(const LinkedList<Shipment>& shipments, std::string filename, LinkedList<Person>& senders, LinkedList<Person>& receivers) {
    std::ofstream outFile(filename + ".txt");
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    outFile << "SHIPMENT" << "\n";
    outFile << "=================================\n";

    shipments.for_each([&outFile](const Shipment& shipment) {
        shipment.exportDataShipment(outFile);
        });

    outFile.close();
}

// Sắp xếp danh sách shipments theo ID (tăng dần hoặc giảm dần)
void Management::sortShipmentsById(LinkedList<Shipment>& list, bool ascending) {
    if (list.get_size() <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node<Shipment>* current = list.getHead();
        Node<Shipment>* prev = nullptr;

        while (current->next) {
            bool shouldSwap = ascending ? (current->data.getShipmentId() > current->next->data.getShipmentId())
                : (current->data.getShipmentId() < current->next->data.getShipmentId());

            if (shouldSwap) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}

// So sánh hai ngày
int compareDates(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) return d1.year < d2.year;
    if (d1.month != d2.month) return d1.month < d2.month;
    return d1.day < d2.day;
}

// Sắp xếp danh sách shipments theo ngày (tăng dần hoặc giảm dần)
void Management::sortShipmentsByDate(LinkedList<Shipment>& list, bool ascending) {
    if (list.get_size() <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node<Shipment>* current = list.getHead();
        Node<Shipment>* prev = nullptr;

        while (current->next) {
            bool shouldSwap = ascending ? !compareDates(current->data.getSendDate(), current->next->data.getSendDate())
                : compareDates(current->data.getSendDate(), current->next->data.getSendDate());

            if (shouldSwap) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}

// Hiển thị tất cả shippers trong danh sách
void Management::printAllShippers(const LinkedList<Shipper>& list) const {
    system("CLS");
    std::cout << std::left
        << std::setw(10) << "ID"
        << std::setw(20) << "Name"
        << std::setw(16) << "Tel"
        << std::setw(10) << "Shipper Status" << std::endl;
    std::cout << std::string(81, '-') << "\n";
    list.for_each([](const Shipper& shipper) {
        shipper.displayShipper();
        });
    system("pause");
}

// Cập nhật trạng thái của một shipper
void Management::setShipperStatus(LinkedList<Shipper>& shippers) {
    system("CLS");
    std::string id;
    std::cout << "Enter Shipper ID to update status: ";
    std::cin >> id;

    Node<Shipper>* foundNode = shippers.find([id](const Shipper& shipper) {
        return shipper.shipperId == id;
        });

    if (foundNode) {
        std::cout << "Enter new Shipper Status: ReadyToDeliver (0) / Delivering (1): ";
        int newStatus;
        std::cin >> newStatus;
        foundNode->data.shipperStatus = static_cast<ShipperStatus>(newStatus);
        std::cout << "Shipper with ID " << id << "'s status updated successfully!" << std::endl;
        system("pause");
    }
    else {
        std::cout << "Shipper with ID " << id << " not found!" << std::endl;
        system("pause");
    }
}

// Xuất danh sách shippers ra file
void Management::exportToFileShipper(const LinkedList<Shipper>& shippers, std::string filename) {
    std::ofstream outFile(filename + ".txt");
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    outFile << "SHIPPER" << "\n";
    outFile << "=================================\n";

    shippers.for_each([&outFile](const Shipper& shipper) {
        shipper.exportDataShipper(outFile);
        });

    outFile.close();
}

// Thêm danh sách senders mẫu
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

// Thêm danh sách receivers mẫu
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

// Thêm danh sách shippers mẫu
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