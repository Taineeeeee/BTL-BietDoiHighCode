#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Display.h"

// Hiển thị menu quản lý chính
void displayMenuManagement(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================MENU-MANAGEMENT===================\n";
        std::cout << "==               1.Sender Management                ==\n";
        std::cout << "==               2.Receiver Management              ==\n";
        std::cout << "==               3.Shipment Management              ==\n";
        std::cout << "==               4.Shipper Management               ==\n";
        std::cout << "==               5.Exit                             ==\n";
        std::cout << "======================================================\n";
        std::cout << " Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displaySenderMenu(manager); // Hiển thị menu quản lý người gửi
            break;
        case 2:
            displayReceiverMenu(manager); // Hiển thị menu quản lý người nhận
            break;
        case 3:
            displayShipmentMenu(manager); // Hiển thị menu quản lý lô hàng
            break;
        case 4:
            displayShipperMenu(manager); // Hiển thị menu quản lý shipper
            break;
        case 5:
            std::cout << "Exiting...\n"; // Thoát chương trình
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n"; // Thông báo lỗi nếu lựa chọn không hợp lệ
            system("pause");
            break;
        }
    } while (choice != 5);
}

// Hiển thị menu quản lý người gửi
void displaySenderMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SENDER-MANAGEMENT===================\n";
        std::cout << "==               1.Add Sender                         ==\n";
        std::cout << "==               2.Print Sender List                  ==\n";
        std::cout << "==               3.Delete Sender By ID                ==\n";
        std::cout << "==               4.Update Sender By ID                ==\n";
        std::cout << "==               5.Find Sender By ID                  ==\n";
        std::cout << "==               6.Sort Sender List By ID             ==\n";
        std::cout << "==               7.Export Sender List To File         ==\n";
        std::cout << "==               8.Return To Main Menu                ==\n";
        std::cout << "========================================================\n";
        std::cout << " Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addPerson(manager.senders, "Sender"); // Thêm người gửi
            break;
        case 2:
            manager.printAllPersons(manager.senders, "Sender"); // In danh sách người gửi
            break;
        case 3:
            manager.deletePerson(manager.senders, "Sender"); // Xóa người gửi theo ID
            break;
        case 4:
            manager.updatePerson(manager.senders, "Sender"); // Cập nhật thông tin người gửi
            break;
        case 5:
            manager.findPerson(manager.senders, "Sender"); // Tìm người gửi theo ID
            break;
        case 6:
            system("CLS");
            int personChoice;
            std::cout << "1. Ascending\n2. Descending" << std::endl;
            std::cout << "Enter your choice: "; std::cin >> personChoice;
            if (personChoice == 1) {
                manager.sortPersonById(manager.senders, true); // Sắp xếp tăng dần theo ID
                std::cout << "Senders sorted by ID (Ascending)!" << std::endl;
                system("pause");
            }
            else if (personChoice == 2) {
                manager.sortPersonById(manager.senders, false); // Sắp xếp giảm dần theo ID
                std::cout << "Senders sorted by ID (Descending)!" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Invalid Shipment choice!" << std::endl; // Thông báo lỗi nếu lựa chọn không hợp lệ
            }
            break;
        case 7: {
            system("CLS");
            std::string fname;
            std::cout << "Enter the filename: ";
            std::cin >> fname;
            manager.exportToFilePerson(manager.senders, fname, "Sender"); // Xuất danh sách người gửi ra file
            std::cout << "\nExport File Successfully !\n"; }
              system("pause");
              break;
        case 8:
            return; // Quay lại menu chính
        default:
            std::cout << "Invalid choice! Please try again.\n"; // Thông báo lỗi nếu lựa chọn không hợp lệ
            system("pause");
            break;
        }
    } while (choice != 8);
}

// Hiển thị menu quản lý người nhận
void displayReceiverMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================RECEIVER-MANAGEMENT===================\n";
        std::cout << "==               1.Add Receiver                         ==\n";
        std::cout << "==               2.Print Receiver List                  ==\n";
        std::cout << "==               3.Delete Receiver By ID                ==\n";
        std::cout << "==               4.Update Receiver By ID                ==\n";
        std::cout << "==               5.Find Receiver By ID                  ==\n";
        std::cout << "==               6.Sort Receiver List By ID             ==\n";
        std::cout << "==               7.Export Receiver List To File         ==\n";
        std::cout << "==               8.Return To Main Menu                  ==\n";
        std::cout << "==========================================================\n";
        std::cout << " Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addPerson(manager.receivers, "Receiver"); // Thêm người nhận
            break;
        case 2:
            manager.printAllPersons(manager.receivers, "Receiver"); // In danh sách người nhận
            break;
        case 3:
            manager.deletePerson(manager.receivers, "Receiver"); // Xóa người nhận theo ID
            break;
        case 4:
            manager.updatePerson(manager.receivers, "Receiver"); // Cập nhật thông tin người nhận
            break;
        case 5:
            manager.findPerson(manager.receivers, "Receiver"); // Tìm người nhận theo ID
            break;
        case 6:
            system("CLS");
            int personChoice;
            std::cout << "1. Ascending\n2. Descending" << std::endl;
            std::cout << "Enter your choice: "; std::cin >> personChoice;
            if (personChoice == 1) {
                manager.sortPersonById(manager.receivers, true); // Sắp xếp tăng dần theo ID
                std::cout << "Receivers sorted by ID (Ascending)!" << std::endl;
                system("pause");
            }
            else if (personChoice == 2) {
                manager.sortPersonById(manager.receivers, false); // Sắp xếp giảm dần theo ID
                std::cout << "Receivers sorted by ID (Descending)!" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Invalid Shipment choice!" << std::endl; // Thông báo lỗi nếu lựa chọn không hợp lệ
            }
            break;
        case 7: {
            system("CLS");
            std::string fname;
            std::cout << "Enter the filename: ";
            std::cin >> fname;
            manager.exportToFilePerson(manager.receivers, fname, "Receiver"); // Xuất danh sách người nhận ra file
            std::cout << "\nExport File Successfully !\n"; }
              system("pause");
              break;
        case 8:
            return; // Quay lại menu chính
        default:
            std::cout << "Invalid choice! Please try again.\n"; // Thông báo lỗi nếu lựa chọn không hợp lệ
            system("pause");
            break;
        }
    } while (choice != 8);
}

// Hiển thị menu quản lý lô hàng
void displayShipmentMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SHIPMENT-MANAGEMENT===================\n";
        std::cout << "==               1.Add Shipment                         ==\n";
        std::cout << "==               2.Print Shipment List                  ==\n";
        std::cout << "==               3.Delete Shipment By ID                ==\n";
        std::cout << "==               4.Update Shipment By ID                ==\n";
        std::cout << "==               5.Find Shipment By ID                  ==\n";
        std::cout << "==               6.Sort Shipment List By ID             ==\n";
        std::cout << "==               7.Sort Shipment List By Date           ==\n";
        std::cout << "==               8.Export Shipment List To File         ==\n";
        std::cout << "==               9.Return To Main Menu                  ==\n";
        std::cout << "==========================================================\n";
        std::cout << " Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addShipment(manager.shipments, manager.senders, manager.receivers); // Thêm lô hàng
            break;
        case 2:
            manager.printAllShipments(manager.shipments); // In danh sách lô hàng
            break;
        case 3:
            manager.deleteShipment(manager.shipments, manager.senders, manager.receivers); // Xóa lô hàng theo ID
            break;
        case 4:
            manager.updateShipment(manager.shipments); // Cập nhật thông tin lô hàng
            break;
        case 5:
            manager.findShipment(manager.shipments); // Tìm lô hàng theo ID
            break;
        case 6:
            system("CLS");
            int ShipmentChoice;
            std::cout << "1. Ascending\n2. Descending" << std::endl;
            std::cout << "Enter your choice: "; std::cin >> ShipmentChoice;
            if (ShipmentChoice == 1) {
                manager.sortShipmentsById(manager.shipments, true); // Sắp xếp tăng dần theo ID
                std::cout << "shipments sorted by ID (Ascending)!" << std::endl;
                system("pause");
            }
            else if (ShipmentChoice == 2) {
                manager.sortShipmentsById(manager.shipments, false); // Sắp xếp giảm dần theo ID
                std::cout << "shipments sorted by ID (Descending)!" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Invalid Shipment choice!" << std::endl; // Thông báo lỗi nếu lựa chọn không hợp lệ
            }
            break;
        case 7:
            system("CLS");
            int dateChoice;
            std::cout << "1. Ascending\n2. Descending" << std::endl;
            std::cout << "Enter your choice: "; std::cin >> dateChoice;
            if (dateChoice == 1) {
                manager.sortShipmentsByDate(manager.shipments, true); // Sắp xếp tăng dần theo ngày
                std::cout << "shipments sorted by Date (Ascending)!" << std::endl;
                system("pause");
            }
            else if (dateChoice == 2) {
                manager.sortShipmentsByDate(manager.shipments, false); // Sắp xếp giảm dần theo ngày
                std::cout << "shipments sorted by Date (Descending)!" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Invalid date choice!" << std::endl; // Thông báo lỗi nếu lựa chọn không hợp lệ
            }
            break;
        case 8: {
            system("CLS");
            std::string fname;
            std::cout << "Enter the filename: ";
            std::cin >> fname;
            manager.exportToFileShipment(manager.shipments, fname, manager.senders, manager.receivers); // Xuất danh sách lô hàng ra file
            std::cout << "\nExport File Successfully !\n";
        }
              fflush;
              system("pause");
              break;
        case 9:
            return; // Quay lại menu chính
        default:
            std::cout << "Invalid choice! Please try again.\n"; // Thông báo lỗi nếu lựa chọn không hợp lệ
            system("pause");
            break;
        }
    } while (choice != 9);
}

// Hiển thị menu quản lý shipper
void displayShipperMenu(Management& manager) {
    int choice;
    do {
        system("CLS");
        std::cout << "\t\t   BIET DOI HIGH CODE\t" << std::endl;
        std::cout << "====================SHIPPER-MANAGEMENT===================\n";
        std::cout << "==               1.Print Shipper List                  ==\n";
        std::cout << "==               2.Set Shipper Status                  ==\n";
        std::cout << "==               3.Export Shipper List To File         ==\n";
        std::cout << "==               4.Return To Main Menu                 ==\n";
        std::cout << "=========================================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.printAllShippers(manager.shippers); // In danh sách shipper
            break;
        case 2:
            manager.setShipperStatus(manager.shippers); // Cập nhật trạng thái shipper
            break;
        case 3: {
            system("CLS");
            std::string fname;
            std::cout << "Enter the filename: ";
            std::cin >> fname;
            manager.exportToFileShipper(manager.shippers, fname); // Xuất danh sách shipper ra file
            fflush;
            std::cout << "\nExport File Successfully !\n"; }
              system("pause");
              break;
        case 4:
            return; // Quay lại menu chính
        default:
            std::cout << "Invalid choice! Please try again.\n"; // Thông báo lỗi nếu lựa chọn không hợp lệ
            system("pause");
            break;
        }
    } while (choice != 4);
}