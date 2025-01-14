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
};

#endif // LINKEDLIST_H
