#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

// Lớp Person đại diện cho một người với các thông tin cơ bản
class Person {

private:
    std::string name;           // Tên của người
    std::string address;        // Địa chỉ của người
    std::string id;             // ID của người
    std::string tel;            // Số điện thoại của người
    int totalShipments;         // Tổng số lần giao hàng đã thực hiện

public:
    // Constructor khởi tạo một đối tượng Person với các thông tin cơ bản
    Person(const std::string& name, const std::string& address, const std::string& id, const std::string& tel, int totalShipments = 0);

    // Trả về ID của người
    std::string getId() const;

    // Trả về tên của người
    std::string getName() const;

    // Trả về địa chỉ của người
    std::string getAddress() const;

    // Trả về số điện thoại của người
    std::string getTel() const;

    // Cập nhật thông tin chi tiết của người (tên, địa chỉ, số điện thoại)
    void updateDetails(const std::string& name, const std::string& address, const std::string& tel);

    // Hiển thị thông tin chi tiết của người ra màn hình
    void displayPerson() const;

    // Hiển thị thông tin tóm tắt của người phục vụ cho việc giao hàng
    void displayPersonForShipment() const;

    // Xuất thông tin của người ra file
    void exportDataPerson(std::ofstream& out) const;

    // Lớp Management là bạn của Person để có thể truy cập các thành phần private
    friend class Management;
};

#endif // PERSON_H