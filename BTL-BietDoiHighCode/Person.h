
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

class Person {

private:
    std::string name, address, id, tel;
    int totalShipments;
public:
    Person(const std::string& name, const std::string& address, const std::string& id, const std::string& tel, int totalShipments = 0);

    std::string getId() const ;

    std::string getName() const ;

    std::string getAddress() const ;

    std::string getTel()  const ;

    //void updateDetails(const std::string& name, const std::string& address, const std::string& tel);

    void displayPerson() const ;

    void displayPersonForShipment() const ;

    void exportData(std::ofstream& out) const ;

    friend class Management;
};

#endif