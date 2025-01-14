// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

// Node structure template for the LinkedList
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

// LinkedList class template
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    // Add an element to the end of the list
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    // Remove the first occurrence of a value from the list
    bool remove(const T& value) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = prev;
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

    // Find an element in the list
    Node<T>* find(int search_id) {
        Node<T>* current = head;
        while (current) {
            if (current->data.id == search_id) {
                return current;  // Trả về phần tử tìm thấy
            }
            current = current->next;
        }
        return nullptr;  // Không tìm thấy phần tử nào thỏa mãn
    }

    // Clear the list
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Get size of the list
    size_t get_size() const {
        return size;
    }

    // Iterate through the list
    void for_each(void (*func)(const T&)) const {
        Node<T>* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
    }

    // Overload operator[] for indexing
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
};

#endif // LINKEDLIST_H
