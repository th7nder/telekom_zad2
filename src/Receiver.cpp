#include "Receiver.h"
#include "signals.h"
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

ByteVector Receiver::receiveFile(){
    system_clock::time_point start = system_clock::now();
    bool letsStart = false;
    while(system_clock::now() - start < seconds(60)){
        readerWriter->write(ByteVector({NAK}));
        this_thread::sleep_for(seconds(10));
        if(readerWriter->read() == SOH){
            letsStart = true;
            break;
        }
    }
    if(letsStart){
        return ByteVector();
    }else{
        return ByteVector();
    }
}
