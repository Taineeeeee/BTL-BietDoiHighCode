#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"
#include "LinkedList.h"

class Management {
private:
    LinkedList<Person> senders;      // Danh sách người gửi
    LinkedList<Person> receivers;    // Danh sách người nhận
    LinkedList<Shipment> shipments;  // Danh sách lô hàng
    LinkedList<Shipper> shippers;    // Danh sách shipper

public:
    // Thêm một người vào danh sách (người gửi hoặc người nhận)
    void addPerson(LinkedList<Person>& list, const std::string& role);

    // In ra tất cả người trong danh sách (người gửi hoặc người nhận)
    void printAllPersons(const LinkedList<Person>& list, const std::string& role) const;

    // Xóa một người khỏi danh sách (người gửi hoặc người nhận)
    void deletePerson(LinkedList<Person>& list, const std::string& role);

    // Cập nhật thông tin của một người trong danh sách (người gửi hoặc người nhận)
    void updatePerson(LinkedList<Person>& list, const std::string& role);

    // Tìm kiếm một người trong danh sách (người gửi hoặc người nhận)
    void findPerson(const LinkedList<Person>& list, const std::string& role) const;

    // Sắp xếp danh sách người theo ID (tăng dần hoặc giảm dần)
    void sortPersonById(LinkedList<Person>& list, bool ascending = true);

    // Xuất danh sách người ra file
    void exportToFilePerson(const LinkedList<Person>& people, std::string filename, const std::string& role);

    // Thêm một lô hàng vào danh sách
    void addShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers, LinkedList<Shipper>& shippers);

    // In ra tất cả lô hàng trong danh sách
    void printAllShipments(const LinkedList<Shipment>& list) const;

    // Xóa một lô hàng khỏi danh sách
    void deleteShipment(LinkedList<Shipment>& list, LinkedList<Person>& senders, LinkedList<Person>& receivers);

    // Cập nhật thông tin của một lô hàng trong danh sách
    void updateShipment(LinkedList<Shipment>& list);

    // Tìm kiếm một lô hàng trong danh sách
    void findShipment(const LinkedList<Shipment>& list) const;

    // Sắp xếp danh sách lô hàng theo ID (tăng dần hoặc giảm dần)
    void sortShipmentsById(LinkedList<Shipment>& list, bool ascending = true);

    // Sắp xếp danh sách lô hàng theo ngày gửi (tăng dần hoặc giảm dần)
    void sortShipmentsByDate(LinkedList<Shipment>& shipments, bool ascending = true);

    // Xuất danh sách lô hàng ra file
    void exportToFileShipment(const LinkedList<Shipment>& list, std::string filename, LinkedList<Person>& senders, LinkedList<Person>& receivers);

    // In ra tất cả shipper trong danh sách
    void printAllShippers(const LinkedList<Shipper>& list) const;

    // Cập nhật trạng thái của một shipper
    void setShipperStatus(LinkedList<Shipper>& shippers);

    // Xuất danh sách shipper ra file
    void exportToFileShipper(const LinkedList<Shipper>& shippers, std::string filename);

    //Hiển thị thông tin đơn hàng của 1 shipper
    void viewShipmentsByShipper(LinkedList<Shipper>& shippers, const std::string& shipperId);

    // Thêm dữ liệu mẫu vào danh sách người gửi
    void addSenders();

    // Thêm dữ liệu mẫu vào danh sách người nhận
    void addReceivers();

    // Thêm dữ liệu mẫu vào danh sách shipper
    void addShipper();

    // Các hàm bạn bè để hiển thị menu quản lý
    friend void displayMenuManagement(Management& manager);
    friend void displaySenderMenu(Management& manager);
    friend void displayReceiverMenu(Management& manager);
    friend void displayShipmentMenu(Management& manager);
    friend void displayShipperMenu(Management& manager);
};

#endif
