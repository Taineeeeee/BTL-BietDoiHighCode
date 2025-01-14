#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"
#include "LinkedList.h"

class Management {
private:
    LinkedList<Person> senders;
    LinkedList<Person> receivers;
    LinkedList<Shipment> shipments;
    LinkedList<Shipper> shippers;

public:
    // Các phương thức của lớp Management
    void addPerson(LinkedList<Person>& list, const std::string& role);

    void printAllPersons(const LinkedList<Person>& list, const std::string& role) const;

    void deletePerson(LinkedList<Person>& list, const std::string& role);

    void updatePerson(LinkedList<Person>& list, const std::string& role);

    void findPerson(const LinkedList<Person>& list, const std::string& role) const;

    void sortPersonById(LinkedList<Person>& list, bool ascending = true);

    void exportToFile(const LinkedList<Person>& list, const std::string& filename, const std::string& role);

    //---------//

    void addShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers);

    void printAllShipments(const LinkedList<Shipment>& list) const;

    void deleteShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers);

    void updateShipment(LinkedList<Shipment>& list);

    void findShipment(const LinkedList<Shipment>& list) const;

    void sortShipmentsById(LinkedList<Shipment>& list, bool ascending = true);

    void sortShipmentsByDate(LinkedList<Shipment>& shipments, bool ascending = true);

    void exportToFileShipment(const LinkedList<Shipment>& list, std::string filename, LinkedList<Person>& senders, LinkedList<Person>& receivers);

    //---------//

    void printAllShippers(const LinkedList<Shipper>& list) const;

    void setShipperStatus(LinkedList<Shipper>& shippers);

    void exportToFileShipper(const LinkedList<Shipper>& shippers, std::string filename);

    //---thêm dữ liệu lấy ví dụ---//

    void addSenders();

    void addReceivers();

    void addShipper();

    friend void displayMenuManagement(Management& manager);
    friend void displaySenderMenu(Management& manager);
    friend void displayReceiverMenu(Management& manager);
    friend void displayShipmentMenu(Management& manager);
    friend void displayShipperMenu(Management& manager);
};

#endif