#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "ByteVector.h"
#include "checksum.h"
#include "ReaderWriter.h"

class Transmitter{
    ReaderWriter* readerWriter;
public:
    Transmitter(ReaderWriter* readerWriter) : readerWriter(readerWriter){}
    void sendFile(ByteVector data, int mode = ALGEBRAIC_CHECKSUM);
};

#endif //TRANSMITTER_H
