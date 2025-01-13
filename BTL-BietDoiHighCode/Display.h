#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Person.h"
#include "Shipment.h"
#include "Shipper.h"
#include "Management.h"

void displayMenuManagement(Management& manager) ;
void displaySenderMenu(Management& manager) ;
void displayReceiverMenu(Management& manager) ;
void displayShipmentMenu(Management& manager);
void displayShipperMenu(Management& manager);

#endif