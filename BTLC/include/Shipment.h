#ifndef SHIPMENT_H
#define SHIPMENT_H
#include <stdio.h>
#include "Person.h"

typedef struct { int day, month, year; } Date;

typedef enum { Pending, InTransit, Delivered, Returned } ShipmentStatus;

typedef enum { Unpaid, Paid } PaymentStatus;

typedef struct  {
    Date sendDate;
    Date receiveDate;
    PaymentStatus paymentStatus;
    ShipmentStatus status;
    Person sender, receiver;
    char goodsInfo[100];
    char ShipmentId[100];
} Shipment;

#endif // SHIPMENT_H
