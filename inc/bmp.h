#ifndef BMP_H
#define BMP_H

#include <cstdint>

#ifndef __LITTLE_ENDIAN__
	#ifndef __BIG_ENDIAN__
		#define __LITTLE_ENDIAN__
	#endif
#endif

#ifdef __LITTLE_ENDIAN__
	#define BITMAP_SIGNATURE 0x4d42
#else
	#define BITMAP_SIGNATURE 0x424d
#endif

struct FileHeader {
    uint16_t signature;
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
};

struct InfoHeader {
    uint32_t headerSize;
    uint32_t imageWidth;
    uint32_t imageHeight;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    uint32_t xPixelsPerMeter;
    uint32_t yPixelsPerMeter;
    uint32_t colorsInColorTable;
    uint32_t importantColorCount;
    uint32_t redChannelBitmask;
    uint32_t greenChannelBitmask;
    uint32_t blueChannelBitmask;
    uint32_t alphaChannelBitmask;
    uint32_t colorSpaceType;
    uint32_t colorSpaceEndpoints[9];
    uint32_t gammaForRedChannel;
    uint32_t gammaForGreenChannel;
    uint32_t gammaForBlueChannel;
    uint32_t intent;
    uint32_t iccProfileData;
    uint32_t iccProfileSize;
    uint32_t Reserved;
};

typedef struct pixel {
    uint8_t alpha;
    uint8_t green;
    uint8_t red;
    uint8_t blue;
} pixel;

class bmp {
    public:
    bmp();
    ~bmp();
};
#endif