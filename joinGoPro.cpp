#include "MP4.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if ( argc < 4 ) {
        std::cout << "usage: joinGoPro.exe <first MP4 file> ... <last MP4 file> <resulting joined MP4 file>" << std::endl;
        return 1;
    }

    MP4::Processor processor;

    MP4::Parser parserMain(argv[1]);
    processor.addComponentSubTypeTrack(parserMain,"vide",1);
    processor.addComponentSubTypeTrack(parserMain,"soun",2);
    processor.addDataFormatTrack(parserMain,"gpmd");

    for ( int i = 2; i < (argc - 1); i++) {
        MP4::Parser parserAppend(argv[i]);
        processor.append(parserAppend);
    }

    processor.addUserData(parserMain);

    MP4::Writer writer(processor);
    writer.write(argv[argc-1]);

    return 0;
}