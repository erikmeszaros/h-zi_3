#include <iostream>
#include <cstdlib>
#include "Character.h"

using namespace std;


int main(int argc, char* argv[]) {	
	if (argc != 3) {
		cerr << argv[0] << "2 files' name\n";;
	}
	else {
		// command prompt parameters
		try {
			Character p1=Character::parseUnit(argv[1]);
			Character p2=Character::parseUnit(argv[2]);
			
		}
		catch (int x){
			if (x==-99) cerr<< "Can not open the files!\n";
			else cerr<<"Something went wrong!\n";
			return 1;
		}
	}
	return 0;
}
