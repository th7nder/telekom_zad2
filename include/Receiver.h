#ifndef RECEIVER_H
#define RECEIVER_H

#include "ByteVector.h"
#include "checksum.h"
#include "ReaderWriter.h"

class Receiver{
    ReaderWriter* readerWriter;
public:
    Receiver(ReaderWriter* readerWriter) : readerWriter(readerWriter){}
    ByteVector receiveFile(int mode = ALGEBRAIC_CHECKSUM);
};

#endif //RECEIVER_H
