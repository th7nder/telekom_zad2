#ifndef RECEIVER_H
#define RECEIVER_H

#include "ByteVector.h"
#include "ReaderWriter.h"

class Receiver{
    ReaderWriter* readerWriter;
public:
    Receiver(ReaderWriter* readerWriter) : readerWriter(readerWriter){}
    ByteVector receiveFile();
};

#endif //RECEIVER_H
