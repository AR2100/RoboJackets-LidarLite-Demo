#include "LIDARLite.h"
#include "mbed.h"


void LIDARLite::write(char registerVal, char val, char lidarliteAddress) {

    /* Create a char of size 1.
     * Need to pass in a pointer to write
     */
    char[] cmd = char[1];

    //First, set register to write
    cmd[0] = registerVal;
    i2c.write(lidarliteAddress, cmd, 1);

    //Write value to register
    cmd[0] = val;
    i2c.write(lidarliteAddress, cmd, 1);

    //sleep for 1ms (thread.sleep?)
}

void LIDARLite::read(char registerVal, int numBytes, char *dataArr, 
                                bool busyFlag, char lidarliteAddress) {

    // First, write to the 0x01 register
    char[] cmd = char[1];
    cmd = 0x01;
    i2c.write(lidarliteAddress, cmd, 1);

    //Set the register to read from
    char[] addrArr = char[1];
    i2c.write(lidarliteAddress, addrArr, 1);

    /* Read from the lidarlite
     *  Pass in a pointer to the data array
     */
    char[] dataArr = char[numBytes];
    i2c.read(lidarliteAddress, dataArr, numBytes);
}