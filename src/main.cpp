#include <iostream>
#include <generic.h>
#include <fstream>
#include <bit>
#pragma pack(1)

struct FirstHeader {
    uint16_t signature;
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
};

struct SecondHeader {
    uint32_t headerSize;
    uint32_t imageWidth;
    uint32_t imageHeight;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    uint32_t xPixelsPerMeter;
    uint32_t yPixelsPerMeter;
};

int main() {
    std::fstream file;
    file.open("../data/test.bmp",std::ios_base::in);
    if(file.is_open()) {
        char header1[sizeof(FirstHeader)];
        char header2[sizeof(SecondHeader)];
        file.read(header1,sizeof(header1));
        file.read(header2,sizeof(header2));
        auto H1 = std::bit_cast<FirstHeader>(header1);
        auto H2 = std::bit_cast<SecondHeader>(header2);
        std::cout << "header1 raw " << header1 << std::endl;
        std::cout << "Signature: " << (char)(H1.signature & 0xFF) << (char)(H1.signature>>8) << std::endl;
        std::cout << "File Size: " << H1.fileSize << std::endl;
        std::cout << "Data Offset: " << H1.dataOffset << std::endl;
        std::cout << "----------" << std::endl;
        std::cout << "Header Size: " << H2.headerSize << std::endl;
        std::cout << "Image Width: " << H2.imageWidth << std::endl;
        std::cout << "Image Height: " << H2.imageHeight << std::endl;
        std::cout << "Planes: " << H2.planes << std::endl;
        std::cout << "Bits Per Pixel: " << H2.bitsPerPixel << std::endl;
        std::cout << "Compression: " << H2.compression << std::endl;
        std::cout << "Image Size: " << H2.imageSize << std::endl;
        std::cout << "X Pixels Per Meter: " << H2.xPixelsPerMeter << std::endl;
        std::cout << "Y Pixels Per Meter: " << H2.yPixelsPerMeter << std::endl;
    }
    file.close();
}