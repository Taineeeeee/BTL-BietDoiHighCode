#ifndef SHIPPER_H
#define SHIPPER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Linkedlist.h"
#include "Shipment.h"

// Enum định nghĩa trạng thái của Shipper
enum ShipperStatus { ReadyToDeliver, Delivering };

// Lớp Shipper đại diện cho một người giao hàng
class Shipper {

private:
    std::string name;           // Tên của người giao hàng
    std::string shipperId;      // ID của người giao hàng
    std::string tel;            // Số điện thoại của người giao hàng
    ShipperStatus shipperStatus; // Trạng thái hiện tại của người giao hàng
    LinkedList<Shipment> shipments; // Danh sách các đơn hàng
    int totalShipments;         // Tổng số đơn hàng

public:
    // Constructor khởi tạo một Shipper với các thông tin cơ bản
    Shipper(const std::string& name, const std::string& shipperId, const std::string& tel, ShipperStatus shipperStatus, int totalShipments);

    // Phương thức trả về ID của người giao hàng
    std::string getShipperId();

    // Phương thức xuất dữ liệu của Shipper ra file
    void exportDataShipper(std::ofstream& out) const;

    // Phương thức hiển thị thông tin của Shipper ra màn hình
    void displayShipper() const;

    // Thêm một đơn hàng vào danh sách
    void addShipment(const Shipment& shipment);

    // Xóa một đơn hàng theo ID
    bool removeShipmentById(const std::string& shipmentId);

    // Hiển thị danh sách các đơn hàng
    void displayAllShipments() const;

    // Lớp Management là bạn của Shipper để có thể truy cập các thành phần private
    friend class Management;
};

#endif // SHIPPER_H
