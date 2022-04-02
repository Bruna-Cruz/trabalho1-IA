#include "floodIt_functions.h"
#include <math.h>

//deals with intance of map

void load_instance (mapInfo_t *mapInfo) {

  scanf("%d", &(mapInfo->nRows));
  scanf("%d", &(mapInfo->nCols));
  scanf("%d", &(mapInfo->nColors));

  maxColor = mapInfo->nColors + 1;
  mapInfo->map = (int**) malloc(mapInfo->nRows * sizeof(int*));

  for (int i= 0; i < mapInfo->nRows; i++) {
    mapInfo->map[i] = (int*) malloc(mapInfo->nCols * sizeof(int));

    //save map
    for (int j = 0; j < mapInfo->nCols; j++) {
        scanf("%d", &(mapInfo->map[i][j]));
    }
  }
}

void print_instance (mapInfo_t *mapInfo){

  for(int i= 0; i < mapInfo->nRows; i++) {
    for(int j= 0; j < mapInfo->nCols; j++)
      printf("%d", mapInfo->map[i][j]);
    printf("\n");

  }

}
