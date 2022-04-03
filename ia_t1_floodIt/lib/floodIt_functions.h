
#include <limits.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 105
#define MAXCOLOR 50
#define COLORED 1
#define UNCOLORED 0

// map info type

typedef struct {
  int status;
  int color;
} map_t;


typedef struct {
  
  int nColored;
  int steps;

  map_t **map;
} mapInfo_t;


typedef struct {
  mapInfo_t *state;
  int heuritic;

  struct node_t **children;
} node_t;


int maxColor;
int  maxCol, maxRow; // the max col or row that was colored in the instance
int nRows;
  int nCols;
  int nColors;

void load_instance(mapInfo_t *mapInfo);

void print_instance(mapInfo_t *mapInfo);

void color (mapInfo_t *mapInfo, int color);

