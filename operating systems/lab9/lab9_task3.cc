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
	bool pBit = 0, rBit = 0, mBit = 0;
	int frameNo;
}page[32];

struct memory{
	bool occupied;
}mem[12];

main(){
	unsigned char pgNo;
	unsigned short address, address2, offset;
	bool trigger = false;
	for(int k=0; k<12; k++){
		mem[k].occupied = false;
	}
	page[0] = {1,0,0,11};
	page[1] = {0,0,0,0};
	page[2] = {1,1,1,10};
	page[3] = {1,0,0,5};
	page[4] = {1,1,0,7};
	for(int i=0; i<5; i++){
		if(page[i].pBit == 1){
			mem[page[i].frameNo].occupied = true;
		}
	}
	cout << "Enter an address :";
	cin >> hex >> address;
	offset = address & 0x7FF;
	pgNo = address >> 11;
	cout<<"page no is "<<hex<<(int)pgNo<<" and offset is "<<hex<<offset<< endl;

	if(pgNo > 31){
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
		for(int j=0; j<12;j++){
			if(mem[j].occupied == false){
				mem[j].occupied = true;
				page[pgNo].frameNo = j;
				page[pgNo].pBit = 1;
				address2 = (page[pgNo].frameNo << 11) + offset;
				cout << "Memory address is: " << hex << address2 << endl;
				trigger = true;
				break;
			}
		}
		if (trigger == false){
			for(int l=0; l<32; l++){
				if(page[l].rBit == 0 && page[l].mBit == 0){
					address2 = (page[l].frameNo << 11) + offset;
					cout << "Memory address is: " << hex << address2 << endl;
					trigger = true;
					break;	
				}
			}
			if(trigger == false){
				for(int l=0; l<32; l++){
					if(page[l].rBit == 0){
						address2 = (page[l].frameNo << 11) + offset;
						cout << "Memory address is: " << hex << address2 << endl;
						trigger = true;
						break;	
					}
				}
			}
			if(trigger == false){
				for(int l=0; l<32; l++){
					if(page[l].pBit == 1){
						address2 = (page[l].frameNo << 11) + offset;
						cout << "Memory address is: " << hex << address2 << endl;
						trigger = true;
						break;	
					}
				}
			}
		}
	}
	return 0;
}

