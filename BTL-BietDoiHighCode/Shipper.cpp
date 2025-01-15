#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Shipper.h"

// Constructor khởi tạo đối tượng Shipper với các thông tin cơ bản
Shipper::Shipper(const std::string& name, const std::string& shipperId, const std::string& tel, ShipperStatus shipperStatus, int totalShipments)
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

// Thêm một đơn hàng vào danh sách
void Shipper::addShipment(const Shipment& shipment) {
    shipments.push_back(shipment);
}

// Xóa một đơn hàng theo ID
bool Shipper::removeShipmentById(const std::string& shipmentId) {
    return shipments.remove([&shipmentId](const Shipment& shipment) {
        return shipment.getShipmentId() == shipmentId;
    });
}

//Hiển thị tất cả đơn hàng
void Shipper::displayAllShipments() const {
    if (totalShipments==0) {
        std::cout << "No shipments assigned to this shipper.\n";
        return;
    }

    shipments.for_each([](const Shipment& shipment) {
        shipment.displayShipment();
        });

}


