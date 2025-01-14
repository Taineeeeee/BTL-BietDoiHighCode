#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <functional>
#include "ListElement.h"



// Node của danh sách liên kết
struct Node {
    ListElement* data; // Con trỏ tới đối tượng kiểu ListElement
    Node* next;

    // Constructor
    Node(ListElement* data) : data(data), next(nullptr) {}

    // Destructor: Xóa đối tượng được lưu trữ
    ~Node() { delete data; }
};

// Lớp LinkedList
class LinkedList {
private:
    Node* head; // Con trỏ đầu danh sách
    Node* tail; // Con trỏ cuối danh sách
    size_t size; // Kích thước danh sách

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~LinkedList() { clear(); }

    // Thêm phần tử vào cuối danh sách
    void push_back(ListElement* element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = tail = newNode; // Danh sách rỗng, cập nhật cả head và tail
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    // Xóa phần tử chứa đối tượng có điều kiện cho trước
    bool remove(const std::function<bool(const ListElement*)>& predicate) {
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (predicate(current->data)) { // Kiểm tra điều kiện
                if (prev) {
                    prev->next = current->next; // Bỏ qua node hiện tại
                } else {
                    head = current->next; // Xóa phần tử đầu tiên
                }
                if (current == tail) {
                    tail = prev; // Cập nhật tail nếu cần
                }
                delete current;
                --size;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    // Tìm kiếm phần tử thỏa mãn điều kiện cho trước
    ListElement* find(const std::function<bool(const ListElement*)>& predicate) const {
        Node* current = head;
        while (current) {
            if (predicate(current->data)) {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Duyệt và thực thi hàm trên từng phần tử
    void for_each(const std::function<void(const ListElement*)>& func) const {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
    }

    // Xóa toàn bộ danh sách
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Lấy kích thước danh sách
    size_t get_size() const { return size; }
};

#endif // LINKEDLIST_H
