#ifndef LIDARLite_h
#define LiDARLite_h

#define LIDARLITE_ADDR_DEFAULT 0x62

#include "mbed.h"

class LIDARLite
{
    public:
        
        LIDARLite();

        /* Read command for LIDARLite
        *
        * Perform an I2C read to the device
        * 
        * registerVal: register to write to in lidarliteAddress
        * val: value to write to register
        * lidarliteAddress: I2C address of the lidarLite
        */
        void read();

        /* Write command for LIDARLite
        *
        * Perform an I2C write to the device
        * 
        * registerVal: register to write to in lidarliteAddress
        * val: value to write to register 
        * lidarliteAddress: I2C address of the lidarLite
        * numBytes: number of bytes to read from LIDARLite
        * busyFlag: if true, routine will repeatedly read the 
        *   status register until the busy flag (LSB) is low
        */
        void write(lidarliteAddress, cmd, 1);

    private:
        PinName sdaPin(p9);
        PinName sclPin(p10);
        I2C i2c(sdaPin, sclPin);
}

#endif