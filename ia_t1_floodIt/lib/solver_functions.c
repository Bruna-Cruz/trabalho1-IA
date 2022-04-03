#include "floodIt_functions.h"
#include <math.h>

void inicilize_children(node_t *currentNode){ 
  for( int i=0 ; i< nColors; i++)
    currentNode->children[i] = (node_t *) malloc(sizeof(node_t) );
}

float calc_heuristic(int nColored){
  printf("\n heuristicaa %i %i %i\n", elements, nColored, nColors);     
  return (elements - nColored)/(float)nColors;
}

void solve_game(node_t * currentNode){
  #ifndef DEBUG 
    printf("Inciando solver \n");
  #endif

  int *solution;
  int indexBetter= 0;

  
  #ifndef DEBUG
    print_instance(currentNode);
  #endif

  

list_t first;
list_t *currentList = &first;
  
//checks if found a solution
while(elements != currentNode->nColored) {

    inicilize_children(currentNode);
    currentNode->steps++;
    indexBetter = 0;
    currentNode->children[indexBetter]->heuristic = calc_heuristic(currentNode->children[indexBetter]->nColored);

    //explore children
    for(int i = 0; i < nColors ; i++){

      //skip color if it is the same
      if(currentNode->color != i+1){
        printf("-- %i -- ", i);
        copy_parent(currentNode, currentNode->children[i]);

        color(currentNode->children[i], i+1);
        currentNode->children[i]->heuristic = calc_heuristic(currentNode->children[i]->nColored);
        //update the better child
        if (currentNode->children[i]->heuristic < currentNode->children[indexBetter]->heuristic){
          indexBetter = i; 
        }

        #ifndef DEBUG
          print_instance(currentNode->children[i]);
          printf("HEURISTICA %f\n\n\n", currentNode->children[i]->heuristic);
        #endif
      }
    }
    printf("%i ", indexBetter);
    currentNode = currentNode->children[indexBetter];

    currentList = push(currentList, currentNode->color);
    
  }
  
  printf("finished solving in %i steps\n", currentNode->steps);
  print_color_seq(first);

}

