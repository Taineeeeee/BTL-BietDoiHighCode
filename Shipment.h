<<<<<<< HEAD
#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Person.h"
#include "Linkedlist.h"
#include "ListElement.h"
struct Date { int day, month, year; };

enum ShipmentStatus { Pending, InTransit, Delivered, Returned };

enum PaymentStatus { Unpaid, Paid };

std::string dateToString(const Date& date) {
    return std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
}

class Shipment : public ListElement {

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
=======
#ifndef SHIPMENT_H
#define SHIPMENT_H
#include <stdio.h>
#include "Person.h"

typedef struct { int day, month, year; } Date;

typedef enum { Pending, InTransit, Delivered, Returned } ShipmentStatus;

typedef enum { Unpaid, Paid } PaymentStatus;

typedef struct  {
    Date sendDate;
    Date receiveDate;
    PaymentStatus paymentStatus;
    ShipmentStatus status;
    Person sender, receiver;
    char goodsInfo[100];
    char ShipmentId[100];
} Shipment;

#endif // SHIPMENT_H
>>>>>>> 5aaa9d1ae99940e3ff796104e6c563ee9fc230e8
