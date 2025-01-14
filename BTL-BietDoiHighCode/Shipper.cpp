#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Shipper.h"

// Constructor khởi tạo đối tượng Shipper với các thông tin cơ bản
Shipper::Shipper(const std::string& name, const std::string& shipperId, const std::string& tel, ShipperStatus shipperStatus)
    : name(name), shipperId(shipperId), tel(tel), shipperStatus(shipperStatus) {}

// Trả về ID của shipper
std::string Shipper::getShipperId() {
    return shipperId;
}

// Hiển thị thông tin chi tiết của shipper ra màn hình
void Shipper::displayShipper() const {
    std::cout << std::left
        << std::setw(10) << shipperId
        << std::setw(20) << name
        << std::setw(16) << tel
        << std::setw(10) << (shipperStatus == ReadyToDeliver ? "Ready to deliver" : "Delivering") << std::endl;
}

// Xuất thông tin của shipper ra file
void Shipper::exportDataShipper(std::ofstream& out) const {
    out << "ID Shipper: " << shipperId << " | ";
    out << "Name Shipper: " << name << " | ";
    out << "Tel: " << tel << " | ";
    out << "Shipper Status: " << (shipperStatus == ReadyToDeliver ? "Ready to deliver" : "Delivering") << "\n";
    out << "-----------------------\n";
}