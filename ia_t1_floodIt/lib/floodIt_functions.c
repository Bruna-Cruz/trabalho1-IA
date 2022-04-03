#include "floodIt_functions.h"
#include <math.h>

//deals with intance of map

void load_instance (node_t *mapInfo) {

  scanf("%d", &(nRows));
  scanf("%d", &(nCols));
  scanf("%d", &(nColors));

  elements = nRows * nCols;

  mapInfo->nColored = 1;
  mapInfo->steps = 0;  
  mapInfo->maxCol = mapInfo->maxRow = 0;

  maxColor = nColors + 1;
  mapInfo->map = (map_t**) malloc(nRows * sizeof(map_t*));

  for (int i= 0; i < nRows; i++) {
    mapInfo->map[i] = (map_t*) malloc(nCols * sizeof(map_t));

    //save map
    for (int j = 0; j < nCols; j++) {
        scanf("%d", &(mapInfo->map[i][j].color));
        mapInfo->map[i][j].status = UNCOLORED;
    }
  }

  mapInfo->map[0][0].status = COLORED; 
}

void print_instance (node_t *mapInfo){

  for(int i= 0; i < nRows; i++) {
    for(int j= 0; j < nCols; j++)
      printf("%d", mapInfo->map[i][j].color);
    printf("\n");

  }

  printf("---------------------------------------------------------------------------------------------------\nSTATUS\n");
  for(int i= 0; i < nRows; i++) {
    for(int j= 0; j < nCols; j++)
      printf("%d", mapInfo->map[i][j].status);
    printf("\n");

  }

}

///// test status form neighbors
bool test_conection (node_t *mapInfo, int i, int j){


  if(mapInfo->map[i][j].status == COLORED){
    return true; 
  }

  if(i-1 >= 0)
    if(mapInfo->map[i-1][j].status == COLORED)
      return true; 

  if(j-1 >= 0)
    if(mapInfo->map[i][j-1].status == COLORED)
      return true;
  
  if(i+1 < nCols)
    if(mapInfo->map[i+1][j].status == COLORED)
      return true; 
  
  if(j+1 < nRows)
    if(mapInfo->map[i][j+1].status == COLORED)
      return true; 
    

  return false;
}

void color (node_t *mapInfo, int newColor) {

  int oldColor = mapInfo->map[0][0].color;
  mapInfo->color = newColor;

  #ifndef DEBUG
    printf("current color: %i \n", oldColor);
  #endif

  map_t **auxMap = mapInfo->map;


  for (int i= 0; (i <= mapInfo->maxRow+1) && (i < nRows) ; i++) {
    for (int j= 0; j <= mapInfo->maxCol+1 && (j < nCols); j++){

      if(auxMap[i][j].status == COLORED) {

        auxMap[i][j].color = newColor;
        
        #ifndef DEBUG 
          printf("-->This element has status colored %i %i color is %i\n",i, j,auxMap[i][j].color);
        #endif
       
      } else {
        //test status of neighbors
        if (test_conection(mapInfo, i, j)){
                                                                                                                                                     
          #ifndef DEBUG
            printf("-->Some neighbor has status colored %i %i\n",i, j);
          #endif

          if (auxMap[i][j].color == newColor){
            auxMap[i][j].status = COLORED;
            mapInfo->nColored++;


            //update the max col and row that it is colored just to dont walk throughtout the whole matrix
            if (i > mapInfo->maxRow) mapInfo->maxRow = i;
            if (j > mapInfo->maxCol) mapInfo->maxCol = j; 
          
          }
        }
      }
      printf("%d", auxMap[i][j].color);
    }
    printf("\n");
  }
  #ifndef DEBUG
    print_instance(mapInfo);
  #endif
}

void copy_parent(node_t *mapInfo_parent, node_t *mapInfo){

  mapInfo->map = (map_t**) malloc(nRows * sizeof(map_t*));

  for (int i= 0; i < nRows; i++) {
    mapInfo->map[i] = (map_t*) malloc(nCols * sizeof(map_t));

    //save map
    for (int j = 0; j < nCols; j++) {
        mapInfo->map[i][j].color = mapInfo_parent->map[i][j].color ;
        mapInfo->map[i][j].status = mapInfo_parent->map[i][j].status;
    }
  }

  mapInfo->nColored =  mapInfo_parent->nColored;
  mapInfo->color = mapInfo_parent->color;
  mapInfo->steps = mapInfo_parent->steps;
  mapInfo->maxCol = mapInfo_parent->maxCol;
  mapInfo->maxRow = mapInfo_parent->maxRow;
}
