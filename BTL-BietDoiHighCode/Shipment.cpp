#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Shipment.h"

// Chuyển đổi đối tượng Date thành chuỗi định dạng "dd/mm/yyyy"
std::string dateToString(const Date& date) {
    return std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);
}

// Constructor khởi tạo đối tượng Shipment với các thông tin cơ bản
Shipment::Shipment(const std::string& ShipmentId, const Date& sendDate, const Date& receiveDate, const Person& sender, const Person& receiver, const std::string& goodsInfo, ShipmentStatus status, PaymentStatus paymentStatus)
    : ShipmentId(ShipmentId), sendDate(sendDate), receiveDate(receiveDate), sender(sender), receiver(receiver), goodsInfo(goodsInfo), status(status), paymentStatus(paymentStatus) {}

// Trả về ID của shipment
std::string Shipment::getShipmentId() const {
    return ShipmentId;
}

// Trả về ngày gửi của shipment
const Date& Shipment::getSendDate() const {
    return sendDate;
}

// Trả về ngày nhận của shipment
const Date& Shipment::getReceiveDate() const {
    return receiveDate;
}

// Trả về thông tin người gửi (sender)
Person& Shipment::getSender() {
    return sender;
}

// Trả về thông tin người nhận (receiver)
Person& Shipment::getReceiver() {
    return receiver;
}

// Hiển thị thông tin chi tiết của shipment ra màn hình
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

// Xuất thông tin của shipment ra file
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