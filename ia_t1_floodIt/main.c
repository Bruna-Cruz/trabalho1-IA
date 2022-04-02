#include "lib/floodIt_functions.h"

int main() {
	mapInfo_t mapInfo; 

	int fim = 0, *sequencia, t;
	
	//load instance of the game 
	printf("Inciando \n");
	load_instance(&mapInfo);
	print_instance(&mapInfo);
	
	return 0;
}