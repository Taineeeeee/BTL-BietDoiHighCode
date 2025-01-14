#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Linkedlist.h"
#include "ListElement.h"

class Person : public ListElement {

private:

    std::string name, address, id, tel;
    int totalShipments;

public:
    Person(const std::string& name, const std::string& address, const std::string& id, const std::string& tel, int totalShipments = 0);

    std::string getId() const ;

    std::string getName() const ;
    
    std::string getAddress() const ;
    
    std::string getTel()  const ;

    void displayPerson() const ;
    
    void displayPersonForShipment() const ;
   
    void exportData(std::ofstream& out) const ;

    void updateDetails(const std::string& name, const std::string& address, const std::string& tel) ;

    friend class Management;
};

#endif
