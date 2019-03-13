#ifndef READERWRITER_H
#define READERWRITER_H

#include "ByteVector.h"
#include <string>
#include <stdexcept>
#include <windows.h>
using namespace std;

class ReaderWriter{
	HANDLE com;
public:
	ReaderWriter(std::string portName);
	~ReaderWriter();
	//write block of bytes (or throw exception)
	void write(const ByteVector& data);
	//reada exactly one byte (or throw exception)
	byte read();
};

class OpeningPortError : public std::runtime_error{
public:
	OpeningPortError(const std::string& what_arg) : std::runtime_error(what_arg){}
};
class ConnectionBrokenError : public std::runtime_error{
public:
	ConnectionBrokenError(const std::string& what_arg) : std::runtime_error(what_arg){}
};

#endif //READERWRITER_H
