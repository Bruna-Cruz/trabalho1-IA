#include "floodIt_functions.h"
#include <math.h>

//deals with intance of map

void load_instance (mapInfo_t *mapInfo) {

  scanf("%d", &(mapInfo->nRows));
  scanf("%d", &(mapInfo->nCols));
  scanf("%d", &(mapInfo->nColors));

  maxColor = mapInfo->nColors + 1;
  mapInfo->map = (map_t**) malloc(mapInfo->nRows * sizeof(map_t*));

  for (int i= 0; i < mapInfo->nRows; i++) {
    mapInfo->map[i] = (map_t*) malloc(mapInfo->nCols * sizeof(map_t));

    //save map
    for (int j = 0; j < mapInfo->nCols; j++) {
        scanf("%d", &(mapInfo->map[i][j].color));
    }
  }
}

void print_instance (mapInfo_t *mapInfo){

  for(int i= 0; i < mapInfo->nRows; i++) {
    for(int j= 0; j < mapInfo->nCols; j++)
      printf("%d", mapInfo->map[i][j].color);
    printf("\n");

  }

}

void color (mapInfo_t *mapInfo, int color) {

  int currentColor = mapInfo->map[0][0].color;

  #ifndef DEBUG
    printf("current color: %i \n", currentColor);
  #endif



  for (int i= 0; i < mapInfo->nRows; i++) {
    for (int j= 0; j < mapInfo->nCols; j++){
      printf("%d", mapInfo->map[i][j].color);
    }
    printf("\n");

  }

}