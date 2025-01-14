#ifndef SHIPPER_H
#define SHIPPER_H
#include <stdio.h>

typedef enum { ReadyToDeliver, Delivering }ShipperStatus;

typedef struct  {
    char name[100];
    char shipperId[100];
    char tel[100];
    ShipperStatus shipperStatus;
}Shipper;

#endif // SHIPPER_H
