#include "lib/floodIt_functions.h"

int main() {
	mapInfo_t mapInfo; 

	maxRow = maxCol = 0;
	int fim = 0, *sequencia, t;

	
	//load instance of the game 
	printf("Inciando \n");
	load_instance(&mapInfo);

	#ifndef DEBUG
		print_instance(&mapInfo);
	#endif

	return 0;
}