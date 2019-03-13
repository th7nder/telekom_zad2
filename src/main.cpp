#include <iostream>
#include <fstream>
#include <string>
#include "ReaderWriter.h"
#include "Transmitter.h"
#include "Receiver.h"
#include "signals.h"
using namespace std;

const int SENDING_MODE = 0;
const int RECEIVING_MODE = 1;

int main(){
	ReaderWriter rw("COM0");

	int workingMode;
	int checksumMode;
	cout << "Wybierz tryb pracy:\n"
		"0) wysylanie\n"
		"1) odbieranie\n";
	cin >> workingMode;
	cout << "Wybierz rodzaj sumy kontrolnej:\n"
		"0) algebraiczna suma kontrolna\n"
		"1) crc16\n";
	cin >> checksumMode;
	cin.get();
	if((workingMode != 0 && workingMode != 1) || (checksumMode != 0 && checksumMode != 1)){
		cout << "Niepoprawne parametry!" << endl;
		return 0;
	}

	if(workingMode == 0){
		cout << "Podaj sciezke do pliku: " << endl;
		string filename;
		getline(cin, filename);
		ifstream is(filename, ios::binary);	
		ByteVector data;
		while(is){
			byte b = is.get();
			if(is)
				data.push_back(b);
		}
		is.close();
		Transmitter tr(&rw);
		tr.sendFile(data, checksumMode);
	}
	if(workingMode == 1){
		cout << "Podaj nazwe pliku do odebrania: " << endl;
		string filename;
		getline(cin, filename);
		Receiver re(&rw);
		ByteVector data = re.receiveFile(checksumMode);
		ofstream os(filename, ios::binary);
		os.write((char*)data.data(), data.size());
		os.close();
	}
	
	/*rw.write(ByteVector({C}));
	while(true){
		cout << hex << (int)rw.read() << endl;	
	}*/
}
