//LIDARLight.h 	

#ifndef LIDARLight_h
#define LIDARLight_h
#define lidarLiteAddressD 0x62;
class LIDARLight
{
	public:
		LIDARLight(unsigned char =lidarLiteAddressD);
		void reset(unsigned char =lidarLiteAddressD);
		int getDistance(bool = true, unsigned char =lidarLiteAddressD);
}
#endif