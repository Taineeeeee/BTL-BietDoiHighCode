#ifndef LISTELEMENT_H
#define LISTELEMENT_H

// Lớp cơ sở trừu tượng để làm giao diện chung
class ListElement {
public:
    virtual ~ListElement() = default; // Destructor ảo cho phép hủy đúng lớp con
    virtual void display() const = 0; // Phương thức ảo để in thônh
};
#endif // LISTELEMENT_H
