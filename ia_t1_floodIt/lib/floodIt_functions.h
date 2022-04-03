
#include <limits.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 #define DEBUG

#define MAXCOLOR 21
#define COLORED 1
#define UNCOLORED 0

// map info type

typedef struct {
  int status;
  int color;
} map_t;

typedef struct node_s{
  int maxRow, maxCol; // the max col or row that was colored in the instance
  int color;
  float heuristic;

  int nColored;
  int steps;

  map_t **map;

  struct node_s *children[MAXCOLOR];
} node_t;

typedef struct list_s {
  int i;
  struct list_s * next;
} list_t;


int maxColor;
int nRows;
  int nCols;
  int nColors;
int elements;

list_t *list;

void load_instance(node_t *mapInfo);

void print_instance(node_t *mapInfo);

void color (node_t *mapInfo, int color);

void copy_parent(node_t *mapInfo_parent, node_t *mapInfo);

void solve_game(node_t * currentNode);


void print_color_seq(list_t first);

list_t * push (list_t *current, int i);