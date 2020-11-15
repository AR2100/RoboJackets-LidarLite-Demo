#ifndef LIDARLite_h
#define LiDARLite_h

#define LIDARLITE_ADDR_DEFAULT 0x62

#include "mbed.h"

class LIDARLite
{
    public:
        LIDARLite(char =LIDARLITE_ADDR_DEFAULT);
        void reset(char =LIDARLITE_ADDR_DEFAULT);
        int getDistance(bool =true, char =LIDARLITE_ADDR_DEFAULT);
        void LIDARLite::changeI2CAddress(char newI2CAddress);

        /* Read command for LIDARLite
        *
        * Perform an I2C read to the device
        * 
        * registerVal: register to write to in lidarliteAddress
        * val: value to write to register
        * lidarliteAddress: I2C address of the lidarLite
        */
        bool LIDARLite::read(char registerAddr, char *dataArr, int numBytes,
                            char lidarliteAddress, bool autoIncrement);

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
        bool LIDARLite::write(char registerAddr, char data, char lidarliteAddress);
        bool LIDARLite::writeArray(char registerAddr, char* dataArr, int length, char lidarliteAddress);
    private:
        PinName sdaPin;
        PinName sclPin;
        I2C i2c;
};

#endif