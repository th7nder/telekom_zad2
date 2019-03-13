#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "ByteVector.h"

const int ALGEBRAIC_CHECKSUM = 0;
const int CRC16_CHECKSUM = 1;

byte algebraicChecksum(const ByteVector& bytes);
ByteVector crc16Checksum(const ByteVector& bytes);

#endif //CHECKSUM_H
