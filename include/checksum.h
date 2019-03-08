#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "ByteVector.h"

byte algebraicChecksum(const ByteVector& bytes);
ByteVector crc16Checksum(const ByteVector& bytes);

#endif //CHECKSUM_H
