
#include <limits.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 105
#define MAXCOLOR 50

// map informatios type
typedef struct {
  int nRows;
  int nCols;
  int nColors;

  int **map;
} mapInfo_t;

int maxColor;

void load_instance(mapInfo_t *mapInfo);

void print_instance(mapInfo_t *mapInfo);
