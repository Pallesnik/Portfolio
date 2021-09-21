#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <iostream>
#include <unistd.h>
#include <sys/msg.h>
#include <cstring>

using namespace std;

struct pages{
	bool pBit, rBit, mBit;
	int frameNo;
}page[5];

main(){
	unsigned char pgNo;
	unsigned short address, address2, offset;
	page[0] = {1,0,0,11};
	page[1] = {0,0,0,0};
	page[2] = {1,1,1,10};
	page[3] = {1,0,0,5};
	page[4] = {1,1,0,7};
	cout << "Enter an address :";
	cin >> hex >> address;
	offset = address & 0x7FF;
	pgNo = address >> 11;
	cout<<"page no is "<<hex<<(int)pgNo<<" and offset is "<<hex<<offset<< endl;
	if(pgNo > 4){
		cout << "Not a valid address!" << endl;
	}
	else if(page[pgNo].pBit == 1){
		page[pgNo].rBit = 1;
		cout << "Frame number of address is: " << page[pgNo].frameNo << endl;
		address2 = (page[pgNo].frameNo << 11) + offset;
		cout << "Memory address is: " << hex << address2 << endl;
	}
	else if(page[pgNo].pBit == 0){
		cout << "Page Fault!" << endl;
	}
	return 0;
}

