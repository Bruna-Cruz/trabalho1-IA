#include "lib/floodIt_functions.h"

int main() {
	

  //inicilize node
  node_t currentNode;

	
	//load instance of the game 
	load_instance(&currentNode);

	#ifdef DEBUG
    printf("Inciando \n");
		print_instance(&currentNode);
	#endif

	//inicilize status based on the fist color
	color(&currentNode, currentNode.map[0][0].color);

  int elements = nCols * nRows;

  solve_game(&currentNode);

	return 0;
}


