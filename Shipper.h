#pragma once
#ifndef SHIPPER_H
#define SHIPPER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Linkedlist.h"
#include "ListElement.h"
enum ShipperStatus { ReadyToDeliver, Delivering };

class Shipper: public ListElement {

private:

    std::string name, shipperId, tel;

    ShipperStatus shipperStatus;

public:

    Shipper(const std::string& name, const std::string& shipperId, const std::string& tel, ShipperStatus shipperStatus);

    std::string getShipperId() ;
   
    void exportDataShipper(std::ofstream& out) const ;

    void displayShipper() const ;

    friend class Management;

};

#endif// SHIPPER_H
