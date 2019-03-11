#include "Transmitter.h"
#include "signals.h"
#include "checksum.h"
#include <cmath>
using namespace std;

void Transmitter::sendFile(ByteVector data){
    int noOfBlocks = (int)ceil(data.size() / 128.0);
    for(int blockIndex = 0; blockIndex < noOfBlocks; blockIndex++){
        ByteVector block(data.begin() + blockIndex * 128, data.begin() + (blockIndex + 1) * 128);
        ByteVector header = {SOH, (byte)blockIndex, (byte)(255 - blockIndex)};
        readerWriter->write(header);
        readerWriter->write(block);
        readerWriter->write(ByteVector({algebraicChecksum(block)}));
            
    }
}
