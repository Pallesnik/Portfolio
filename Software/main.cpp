#include "Song.h"
#include <iostream>
using namespace std;

int main() {
	Song s1("Buddy Holly");
	s1.setGenre("Rock");
	s1.setDuration(3);
	Artist a1("Weazer");
	a1.setnofSinglesReleased(5);
	a1.setsalaryEarned(100000);
	s1.setArtist(a1);
	s1.display();
	return 0;
}
