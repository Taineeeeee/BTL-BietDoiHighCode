
#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Shipment.h"
#include "Shipper.h"
#include "Person.h"

extern Person senders[100];
extern int sendersCount;

extern Person receivers[100];
extern int receiversCount;

extern Shipment shipments[100];
extern int ShipmentsCount;

extern Shipper shippers[100];
extern int shippersCount;

void addPerson(Person* list, int* listSize, const char* role);

void printAllPersons(const Person* list, int listSize, const char* role);

void deletePerson(Person* list, int* listSize, const char* role);

void updatePerson(Person* list, int listSize, const char* role);

void findPerson(const Person* list, int listSize, const char* role);

void sortPersonById(Person* list, int listSize, int ascending);

void exportToFile(const Person* list, int listSize, const char* filename, const char* role);

void addShipment();

void printAllShipments();

void deleteShipment();

void updateShipment();

void findShipment();

void sortShipmentsById(int ascending);

void sortShipmentsByDate(int ascending);

void exportToFileShipment(const char* filename);

void printAllShippers();

void setShipperStatus();

void exportToFileShipper(const char* filename);

void addSenders();

void addReceivers();

void addShippers();
#endif // MANAGEMENT_H
