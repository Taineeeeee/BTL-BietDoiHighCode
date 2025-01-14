#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Person.h"

// Constructor khởi tạo đối tượng Person với các thông tin cơ bản
Person::Person(const std::string& name, const std::string& address, const std::string& id, const std::string& tel, int totalShipments)
    : name(name), address(address), id(id), tel(tel), totalShipments(totalShipments) {}

// Trả về ID của người
std::string Person::getId() const {
    return id;
}

// Trả về tên của người
std::string Person::getName() const {
    return name;
}

// Trả về địa chỉ của người
std::string Person::getAddress() const {
    return address;
}

// Trả về số điện thoại của người
std::string Person::getTel() const {
    return tel;
}

// Cập nhật thông tin chi tiết của người (tên, địa chỉ, số điện thoại)
void Person::updateDetails(const std::string& name, const std::string& address, const std::string& tel) {
    this->name = name;
    this->address = address;
    this->tel = tel;
}

// Hiển thị thông tin chi tiết của người ra màn hình
void Person::displayPerson() const {
    std::cout << std::left
        << std::setw(10) << id
        << std::setw(20) << name
        << std::setw(20) << address
        << std::setw(16) << tel
        << std::setw(10) << totalShipments << std::endl;
}

// Hiển thị thông tin tóm tắt của người phục vụ cho việc giao hàng
void Person::displayPersonForShipment() const {
    std::cout << "ID: " << id << " | "
        << "Name: " << name << " | "
        << "Address: " << address << " | "
        << "Tel: " << tel << "\n";
}

// Xuất thông tin của người ra file
void Person::exportDataPerson(std::ofstream& out) const {
    out << "ID: " << id << " | ";
    out << "Name: " << name << " | ";
    out << "Address: " << address << " | ";
    out << "Tel: " << tel << "\n";
    out << "-----------------------\n";
}