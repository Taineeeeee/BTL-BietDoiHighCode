
#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Person.h"

struct Date { int day, month, year; };

enum ShipmentStatus { Pending, InTransit, Delivered, Returned };

enum PaymentStatus { Unpaid, Paid };

std::string dateToString(const Date& date);

class Shipment {
private:
    Date sendDate, receiveDate;
    PaymentStatus paymentStatus;
    ShipmentStatus status;
    Person sender, receiver;
    std::string goodsInfo, ShipmentId;
public:

    Shipment(const std::string& ShipmentId, const Date& sendDate, const Date& receiveDate, const Person& sender, const Person& receiver, const std::string& goodsInfo, ShipmentStatus status, PaymentStatus paymentStatus);

    std::string getShipmentId() const ;

    const Date& getSendDate() const ;

    const Date& getReceiveDate() const ;

    Person& getSender();

    Person& getReceiver() ;

    void displayShipment() const ;

    void exportDataShipment(std::ofstream& out) const ;

    friend class Management;
};

#endif