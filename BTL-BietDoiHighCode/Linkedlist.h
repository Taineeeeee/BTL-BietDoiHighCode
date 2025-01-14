#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <functional>

// Cấu trúc Node cho LinkedList
template <typename T>
struct Node {
    T data;         // Dữ liệu của node
    Node* next;     // Con trỏ trỏ đến node tiếp theo

    Node(const T& data) : data(data), next(nullptr) {} // Khởi tạo node với dữ liệu và next là nullptr
};

// Lớp template LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Con trỏ đến node đầu tiên
    Node<T>* tail;  // Con trỏ đến node cuối cùng
    size_t size;    // Kích thước của danh sách

public:
    // Khởi tạo LinkedList với head và tail là nullptr, size là 0
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Hủy LinkedList và giải phóng bộ nhớ
    ~LinkedList() {
        clear();
    }

    // Thêm một phần tử vào cuối danh sách
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value); // Tạo node mới
        if (!head) { // Nếu danh sách rỗng
            head = tail = newNode; // head và tail trỏ đến node mới
        }
        else {
            tail->next = newNode; // Thêm node mới vào cuối danh sách
            tail = newNode;       // Cập nhật tail
        }
        ++size; // Tăng kích thước danh sách
    }

    // Lấy con trỏ đến node đầu tiên
    Node<T>* getHead() const {
        return head;
    }

    // Xóa phần tử đầu tiên thỏa mãn điều kiện predicate
    bool remove(std::function<bool(const T&)> predicate) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (predicate(current->data)) { // Kiểm tra điều kiện
                if (prev) {
                    prev->next = current->next; // Bỏ qua node hiện tại
                }
                else {
                    head = current->next; // Cập nhật head nếu xóa node đầu
                }
                if (current == tail) {
                    tail = prev; // Cập nhật tail nếu xóa node cuối
                }
                delete current; // Giải phóng bộ nhớ
                --size;         // Giảm kích thước danh sách
                return true;    // Trả về true nếu xóa thành công
            }
            prev = current;
            current = current->next;
        }
        return false; // Trả về false nếu không tìm thấy phần tử
    }

    // Tìm phần tử đầu tiên thỏa mãn điều kiện predicate
    Node<T>* find(std::function<bool(const T&)> predicate) const {
        Node<T>* current = head;
        while (current) {
            if (predicate(current->data)) { // Kiểm tra điều kiện
                return current; // Trả về node nếu tìm thấy
            }
            current = current->next;
        }
        return nullptr; // Trả về nullptr nếu không tìm thấy
    }

    // Xóa toàn bộ danh sách
    void clear() {
        while (head) {
            Node<T>* temp = head; // Lưu lại node hiện tại
            head = head->next;    // Di chuyển head đến node tiếp theo
            delete temp;          // Giải phóng bộ nhớ
        }
        tail = nullptr; // Đặt tail về nullptr
        size = 0;       // Đặt kích thước về 0
    }

    // Lấy kích thước của danh sách
    size_t get_size() const {
        return size;
    }

    // Duyệt qua từng phần tử trong danh sách và áp dụng hàm func
    void for_each(std::function<void(const T&)> func) const {
        Node<T>* current = head;
        while (current) {
            func(current->data); // Áp dụng hàm func lên dữ liệu của node
            current = current->next;
        }
    }

};

#endif // LINKEDLIST_H