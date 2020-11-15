#include "mbed.h"
#include "LIDARLite.h"
#include "ArduinoSlave.h"
#include <sstream>
#include <iostream>

//DigitalOut myled(LED1);
//DigitalOut myled(p21);

using namespace std;

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("Start: \n");
    LIDARLite lidar1 = LIDARLite(0x62);
    
    pc.printf("~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    
    lidar1.changeI2CAddress(0x62);
    
    char serial_number[1];
    lidar1.read(0x04, serial_number, 1, 0x60, false);
    pc.printf("register 0x04: %x \n", serial_number[0]);
    
    lidar1.read(0x1a, serial_number, 1, 0x60, false);
    pc.printf("register 0x1a: %x \n", serial_number[0]);
    
    while (1) {
        
        wait(0.5);
        /*
        distance = lidar1.getDistance(true, 0x62);
        
        pc.printf("val: %d \n", distance);
        wait(0.1);
        */
    }
}
