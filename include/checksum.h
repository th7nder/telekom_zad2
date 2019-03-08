#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <vector>
#include <cstdint>

typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef std::vector<byte> ByteVector;

byte algebraicChecksum(const ByteVector& bytes);
ByteVector crc16Checksum(const ByteVector& bytes);

#endif
