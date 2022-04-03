#include "lib/floodIt_functions.h"

int main() {
	

    //inicilize node
  node_t currentNode;

	
	//load instance of the game 
	printf("Inciando \n");
	load_instance(&currentNode);

	#ifdef DEBUG
		print_instance(&currentNode);
	#endif

	//inicilize status based on the fist color
	color(&currentNode, currentNode.map[0][0].color);

  int choosenColor;

  fflush(stdout);

  //NOTE THIS PART IS JUST TO TEST ----TODO IMPLEMENT CHECK THE STATUS OF THE MAP IF IT IS ALL COLORED (maybe nColored++ every time its color elemnt nColored == size matrix  )
  // scanf("%i", &choosenColor);



  int elements = nCols * nRows;
  node_t chosenChild;

  solve_game(&currentNode);

	//looping choosing color 
	// while(mapInfo->nColored < elements){


    // scanf("%i", &choosenColor);

	// }
	return 0;
}


