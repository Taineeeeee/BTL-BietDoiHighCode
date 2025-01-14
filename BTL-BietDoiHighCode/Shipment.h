#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Person.h"

// Cấu trúc Date để lưu trữ ngày, tháng, năm
struct Date {
    int day, month, year;
};

// Enum để đại diện cho trạng thái của lô hàng
enum ShipmentStatus { Pending, InTransit, Delivered, Returned };

// Enum để đại diện cho trạng thái thanh toán
enum PaymentStatus { Unpaid, Paid };

// Hàm chuyển đổi Date thành chuỗi
std::string dateToString(const Date& date);

// Lớp Shipment đại diện cho một lô hàng
class Shipment {
private:
    Date sendDate;           // Ngày gửi
    Date receiveDate;        // Ngày nhận
    PaymentStatus paymentStatus; // Trạng thái thanh toán
    ShipmentStatus status;   // Trạng thái lô hàng
    Person sender;           // Người gửi
    Person receiver;         // Người nhận
    std::string goodsInfo;   // Thông tin hàng hóa
    std::string ShipmentId;  // ID của lô hàng

public:
    // Constructor để khởi tạo một lô hàng
    Shipment(const std::string& ShipmentId, const Date& sendDate, const Date& receiveDate, const Person& sender, const Person& receiver, const std::string& goodsInfo, ShipmentStatus status, PaymentStatus paymentStatus);

    // Lấy ID của lô hàng
    std::string getShipmentId() const;

    // Lấy ngày gửi
    const Date& getSendDate() const;

    // Lấy ngày nhận
    const Date& getReceiveDate() const;

    // Lấy thông tin người gửi
    Person& getSender();

    // Lấy thông tin người nhận
    Person& getReceiver();

    // Hiển thị thông tin lô hàng
    void displayShipment() const;

    // Xuất thông tin lô hàng ra file
    void exportDataShipment(std::ofstream& out) const;

    // Lớp Management là bạn của Shipment để truy cập các thành viên private
    friend class Management;
};

#endif