#ifndef PERSON_H
#define PERSON_H


typedef struct {
    char name[100];
    char address[100];
    char id[100];
    char tel[100];
    int shipments = 0;
} Person;

#endif // PERSON_H
