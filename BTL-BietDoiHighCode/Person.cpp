#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Person.h"
     
    Person::Person(const std::string& name, const std::string& address, const std::string& id, const std::string& tel, int totalShipments )
        : name(name), address(address), id(id), tel(tel), totalShipments(totalShipments) {}

    std::string Person:: getId() const { return id; }
    std::string Person::getName() const { return name; }
    std::string Person::getAddress() const { return address; }
    std::string Person::getTel()  const { return tel; }

    //void Person::updateDetails(const std::string& name, const std::string& address, const std::string& tel) {
    //    this->name = name;
    //    this->address = address;
    //    this->tel = tel;
    //}

    void Person::displayPerson() const {
        std::cout << std::left
            << std::setw(10) << id
            << std::setw(20) << name
            << std::setw(20) << address
            << std::setw(16) << tel
            << std::setw(10) << totalShipments << std::endl;
    }

    void Person::displayPersonForShipment() const {
        std::cout << "ID: " << id << " |" << "Name: " << name << " |" << "Address: " << address << " |" << "Tel: " << tel << "\n";
    }

    void Person::exportData(std::ofstream& out) const {
        out << "ID: " << id << " | ";
        out << "Name: " << name << " | ";
        out << "Address: " << address << " | ";
        out << "Tel: " << tel << "\n";
        out << "-----------------------\n";
    }