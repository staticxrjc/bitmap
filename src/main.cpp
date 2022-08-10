#include <iostream>
#include <bmp.h>
#include <fstream>
#include <bit>
#include <memory>
#include <mainFrame.h>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wx.h>
class MyApp : public wxApp
{
public:
	bool OnInit()
	{
		Main* main = new Main(wxT("BMP Image"));
		main->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);

//     std::fstream file;
//     file.open("../data/test.bmp",std::ios_base::in);
//     if(file.is_open()) {
//         // Grab 1st Header
//         char header1[sizeof(FileHeader)];
//         file.read(header1,sizeof(header1));
//         auto H1 = std::bit_cast<FileHeader>(header1);
//         int h2Size = H1.dataOffset - sizeof(FileHeader);
//         std::cout << "BM Str: " << std::hex << BITMAP_SIGNATURE << std::endl;
//         if(BITMAP_SIGNATURE == H1.signature)
//             std::cout << "Bitmap Image" << std::endl;
//         else
//             std::cout << "Not bitmap Image" << std::endl;
//         printf("H2 Size: %d\n",h2Size);

//         // Grab 2nd Header
//         char header2[sizeof(InfoHeader)];
//         file.read(header2,sizeof(header2));
//         auto H2 = std::bit_cast<InfoHeader>(header2);
//         std::cout << "File Size: " << H1.fileSize << std::endl;
//         std::cout << "Data Offset: " << H1.dataOffset << std::endl;
//         std::cout << "----------" << std::endl;
//         std::cout << "Header Size: " << H2.headerSize << std::endl;
//         std::cout << "Image Width: " << H2.imageWidth << std::endl;
//         std::cout << "Image Height: " << H2.imageHeight << std::endl;
//         std::cout << "Planes: " << H2.planes << std::endl;
//         std::cout << "Bits Per Pixel: " << H2.bitsPerPixel << std::endl;
//         std::cout << "Compression: " << H2.compression << std::endl;
//         std::cout << "Image Size: " << H2.imageSize << std::endl;
//         std::cout << "X Pixels Per Meter: " << H2.xPixelsPerMeter << std::endl;
//         std::cout << "Y Pixels Per Meter: " << H2.yPixelsPerMeter << std::endl;
//         std::cout << "Colors in Color Table: " << H2.colorsInColorTable << std::endl;
//         std::cout << "Importang Color Count: " << H2.importantColorCount << std::endl;
//         std::cout << "Red Channel Bitmask: 0x" << std::hex << H2.redChannelBitmask << std::endl;
//         std::cout << "Green Channel Bitmask: 0x" << std::hex << H2.greenChannelBitmask << std::endl;
//         std::cout << "Blue Channel Bitmask: 0x" << std::hex << H2.blueChannelBitmask << std::endl;
//         std::cout << "Alpha Channel Bitmask: 0x" << std::hex << H2.alphaChannelBitmask << std::endl;
//         std::cout << "Color Space Type: 0x" << std::hex << H2.colorSpaceType << std::endl;
        
//         switch (H2.bitsPerPixel) {
//             case 16: {
//                 char pixel[2];
//                 uint16_t pixels;

//                 for(int i = H2.imageHeight; i > 0; i--) {
//                     for(int j = 0; j < H2.imageWidth; j++) {
//                         file.read(pixel, 2);
//                         pixels = std::bit_cast<uint16_t>(pixel);
//                         std::cout << "Pixels: " << std::hex << pixels << std::endl;
//                         uint16_t red = pixels & H2.redChannelBitmask;
//                         red = red >> 8;
//                         uint16_t green = pixels & H2.greenChannelBitmask;
//                         green = green >> 4;
//                         std::cout << "Red: " << red << std::endl;
//                         std::cout << "Green: " << green << std::endl;
//                     }
//                 }
                
//                 break;
//                 }
//             default:
//                 std::cout << "Bits per Pixel: " << H2.bitsPerPixel << " not supported!" << std::endl;
//                 break;
//         }
//     }
    
//     file.close();