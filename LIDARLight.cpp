//LIDARLight.cpp

#include "LIDARLight.h"
LIDARLight::LIDARLight(unsigned char lidarliteAddress)
{
	//short range high speed
	write(0x02,0x1d,lidarliteAddress);
	write(0x04,0x08,lidarliteAddress); 
	write(0x1c,0x00,lidarliteAddress); 
	/*
	Default
	write(0x02,0x80,lidarliteAddress); 
	write(0x04,0x08,lidarliteAddress); 
	write(0x1c,0x00,lidarliteAddress); 
	*/
}
void LIDARLight::reset(unsigned char lidarliteAddress)
{
	wirte(0x00, 0x00, lidarliteAddress);
}
int LIDARLight::getDistance(bool biasCorrection, unsigned char lidarliteAddress);
{
	if(biasCorrection)
	{
		write(0x00, 0x04, lidarliteAddress);
	}
	
	else
	{
		write(0x00, 0x03, lidarliteAddress)
	}
	
	unsigned char distanceArray[2];
	read(0x8f,2,2,distanceArray,true,lidarliteAddress);
	unsigned short distance = distanceArray[0]<<8 | distanceArray[1];
	return distance;
	
}
