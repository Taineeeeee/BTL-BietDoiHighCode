#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ListElement.h"
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"

class Management {
private:
    LinkedList senders;
    LinkedList receivers;
    LinkedList shipments;
    LinkedList shippers;

public:
    //getter 
    LinkedList& getSenders() { return senders; }
    LinkedList& getReceivers() { return receivers; }
    LinkedList& getShipments() { return shipments; }
    LinkedList& getShippers() { return shippers; }
    // Functions for managing persons (senders and receivers)
    void addPerson(LinkedList& list, const std::string& role);
    void printAllPersons(const LinkedList& list, const std::string& role) const;
    void deletePerson(LinkedList& list, const std::string& role);
    void updatePerson(LinkedList& list, const std::string& role);
    void findPerson(const LinkedList& list, const std::string& role) const;

    // Functions for managing shipments
    void addShipment(LinkedList& list, LinkedList& senders, LinkedList& receivers);
    void printAllShipments(const LinkedList& list) const;
    void deleteShipment(LinkedList& list);
    void updateShipment(LinkedList& list);
    void findShipment(const LinkedList& list) const;

    // Functions for managing shippers
    void addShipper(LinkedList& list);
    void printAllShippers(const LinkedList& list) const;

    // Friend functions to display menus
    friend void displayMenuManagement(Management& manager);
    friend void displaySenderMenu(Management& manager);
    friend void displayReceiverMenu(Management& manager);
    friend void displayShipmentMenu(Management& manager);
    friend void displayShipperMenu(Management& manager);
};

#endif
