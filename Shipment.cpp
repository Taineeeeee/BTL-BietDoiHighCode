#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Shipment.h"
#include"Linkedlist.h"
    
    
    Shipment::Shipment(const std::string& ShipmentId, const Date& sendDate, const Date& receiveDate, const Person& sender, const Person& receiver, const std::string& goodsInfo, ShipmentStatus status, PaymentStatus paymentStatus)
        : ShipmentId(ShipmentId), sendDate(sendDate), receiveDate(receiveDate), sender(sender), receiver(receiver), goodsInfo(goodsInfo), status(status), paymentStatus(paymentStatus) {}

    std::string Shipment::getShipmentId() const { return ShipmentId; }

    const Date& Shipment::getSendDate() const { return sendDate; }
    const Date& Shipment::getReceiveDate() const { return receiveDate; }

    Person& Shipment::getSender() { return sender; }

    Person& Shipment::getReceiver() { return receiver; }

    void Shipment::displayShipment() const {
        std::cout << std::left
            << std::setw(15) << "ID"
            << std::setw(15) << "Send Date"
            << std::setw(15) << "Receive Date"
            << std::setw(15) << "Goods Info"
            << std::setw(15) << "Status"
            << std::setw(15) << "Payment Status" << std::endl;
        std::cout << std::setw(15) << ShipmentId
            << std::setw(15) << dateToString(sendDate)
            << std::setw(15) << dateToString(receiveDate)
            << std::setw(15) << goodsInfo
            << std::setw(15) << (status == Pending ? "Pending" : status == InTransit ? "In Transit" : status == Delivered ? "Delivered" : "Returned")
            << std::setw(15) << (paymentStatus == Unpaid ? "Unpaid" : "Paid") << std::endl;
        std::cout << "-----Sender information:\n";
        sender.displayPersonForShipment();
        std::cout << "-----Receiver information:\n";
        receiver.displayPersonForShipment();
        std::cout << std::string(100, '-');
        std::cout << "\n";
    }
    // Hàm xuất dữ liệu của đơn hàng ra file
    void Shipment::exportDataShipment(std::ofstream& out) const {
        out << "ID: " << ShipmentId << " | ";
        out << "Send Date: " << dateToString(sendDate) << " | ";
        out << "Receive Date: " << dateToString(receiveDate) << " | ";
        out << "Infor: " << goodsInfo << "\n";
        out << "ID Sender: " << sender.getId() << " | ";
        out << "Name Sender: " << sender.getName() << " | ";
        out << "Address Sender: " << sender.getAddress() << " | ";
        out << "Tel Sender: " << sender.getTel() << "\n";
        out << "ID Receiver: " << receiver.getId() << " | ";
        out << "Name Receiver: " << receiver.getName() << " | ";
        out << "Address Receiver: " << receiver.getAddress() << " | ";
        out << "Tel Receiver: " << receiver.getTel() << "\n";
        out << "-----------------------\n";
    }

    