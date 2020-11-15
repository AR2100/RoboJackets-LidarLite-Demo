#include "LIDARLite.h"
#include "mbed.h"
#include <string>

//working
LIDARLite::LIDARLite(char lidarliteAddress) : sdaPin(p9), sclPin(p10), i2c(sdaPin, sclPin) {
    //short range high speed
    
    //write(0x02,0x1d,lidarliteAddress);
    //write(0x04,0x08,lidarliteAddress); 
    //write(0x1c,0x00,lidarliteAddress); 
    
    //Default
    
    write(0x02, 0x80, lidarliteAddress); 
    //write(0x04, 0x08, lidarliteAddress); 
    write(0x1c, 0x00, lidarliteAddress);
    
    
    char cmd[1];
    cmd[0] = 0x08;
    writeArray(0x04, cmd, 1, lidarliteAddress);
    
    //write(0x04, 0x08, lidarliteAddress); 
    
    /*
    write(0x02, 0x80, lidarliteAddress); 
    write(0x04, 0x08, lidarliteAddress); 
    write(0x1c, 0x00, lidarliteAddress);
    */
}

//working
void LIDARLite::reset(char lidarliteAddress) {
    write(0x00, 0x00, lidarliteAddress);
}

//working
int LIDARLite::getDistance(bool biasCorrection, char lidarliteAddress) {
    
    if(biasCorrection) {
        write(0x00, 0x04, lidarliteAddress);
    }
    
    else {
        write(0x00, 0x03, lidarliteAddress);
    }
    
    char distanceArray[2];
    read(0x8f, distanceArray, 2, lidarliteAddress, true);
    int distance = (distanceArray[0] << 8) + distanceArray[1];
    return distance;
}

//not working
void LIDARLite::changeI2CAddress(char newI2CAddress) {
    char arr[2];
    read(0x96, arr, 2, 0x62, true);
    
    writeArray(0x98, arr, 2, 0x62);
    
    /*
    write(0x18, arr[0], 0x62);
    write(0x19, arr[1], 0x62);
    */
    
    write(0x1a, newI2CAddress, 0x62);
    
    //this works
    write(0x1e, 0x08, 0x62);
}

//working
bool LIDARLite::writeArray(char registerAddr, char* dataArr, int length, char lidarliteAddress) {
    
    char lidarliteAddress_8bit = lidarliteAddress << 1;

    char arr[1 + length];
    arr[0] = registerAddr;
    
    for (int i = 1; i <= length; i++) {
        arr[i] = *(dataArr + i - 1);   
    }
    
    int nack = 1;
    
    while (nack != 0) {
       nack = i2c.write(lidarliteAddress_8bit, arr, length + 1);
    }
    
    return true;
}


bool LIDARLite::write(char registerAddr, char data, char lidarliteAddress) {
    
    char lidarliteAddress_8bit = lidarliteAddress << 1;

    int nack = 1;
    
    char arr[2] = {registerAddr, data};
    
    while (nack != 0) {
       nack = i2c.write(lidarliteAddress_8bit, arr, 2);
    }
    
    return true;
}

//working
bool LIDARLite::read(char registerAddr, char *dataArr, int numBytes,
                            char lidarliteAddress, bool autoIncrement = false) {

    char lidarliteAddress_8bit = lidarliteAddress << 1;
    
    int nack = 1;
    while (nack) {
        nack = i2c.write(lidarliteAddress_8bit, &registerAddr, 1);  
        wait_ms(1);  
    }
    
    nack = 1;
    while (nack) {
        nack = i2c.read(lidarliteAddress_8bit, dataArr, numBytes);  
        wait_ms(1);  
    }
    
    if (nack) return false;
    
    return true;
}