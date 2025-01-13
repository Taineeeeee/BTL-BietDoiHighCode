#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"Display.h"

int main() {
    Management manager;
    manager.addShipper(); //example
    manager.addSenders(); //example
    manager.addReceivers(); //example
    displayMenuManagement(manager);
    return 0;
}