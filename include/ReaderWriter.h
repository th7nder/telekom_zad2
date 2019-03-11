#ifndef READERWRITER_H
#define READERWRITER_H

#include "ByteVector.h"

class ReaderWriter{
public:
    virtual ~ReaderWriter(){}
    virtual void write(const ByteVector& bytes) = 0;
    virtual byte read() = 0;
};

#endif //READERWRITER_H
