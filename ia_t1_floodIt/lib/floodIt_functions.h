
#include <limits.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 // #define DEBUG

#define MAXCOLOR 21
#define COLORED 1
#define UNCOLORED 0


typedef struct {
  int status; // COLORED or UNCOLORED 
  int color; // color
} map_t;

typedef struct node_s{
  int maxRow, maxCol; // the max col or row that was colored in the instance
  
  int color; //color of the instance
  float heuristic; 

  int nColored; //how many is colored 
  int steps; //how many steps until itself

  map_t **map; //state 

  struct node_s *children[MAXCOLOR]; 
} node_t;

// struct to save the solution
typedef struct list_s {
  int i;
  struct list_s * next;
} list_t;

//size of map
int nRows; 
int nCols;

//number of color on the game
int nColors;

//area of the map
int elements;


void load_instance(node_t *mapInfo);

void print_instance(node_t *mapInfo);

void color (node_t *mapInfo, int color);

void copy_parent(node_t *mapInfo_parent, node_t *mapInfo);

void solve_game(node_t * currentNode);

void print_color_seq(list_t first);

list_t * push (list_t *current, int i);