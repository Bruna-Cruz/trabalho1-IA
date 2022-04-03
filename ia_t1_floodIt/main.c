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

	//inicilize status based on the fist color
	color(&mapInfo, mapInfo.map[0][0].color);

  int choosenColor;

  fflush(stdout);

  //NOTE THIS PART IS JUST TO TEST ----TODO IMPLEMENT CHECK THE STATUS OF THE MAP IF IT IS ALL COLORED (maybe nColored++ every time its color elemnt nColored == size matrix  )
  scanf("%i", &choosenColor);

  int elements = nCols * nRows;

	//looping choosing color 
	while(mapInfo.nColored < elements){
		color(&mapInfo, choosenColor);
		
    #ifndef DEBUG
		  print_instance(&mapInfo);
		#endif

    scanf("%i", &choosenColor);

	}
	return 0;
}