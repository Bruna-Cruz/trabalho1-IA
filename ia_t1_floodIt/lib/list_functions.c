#include "floodIt_functions.h"
#include <math.h>


// FUNCTIONS TO SAVE LIST OF SEQUENCE RESOLUTION

void print_color_seq(list_t first){
  list_t *aux = first.next;

  while(aux != NULL){
    printf("%i ", aux->i);

    aux = aux->next;
  }

}

list_t * push (list_t *current, int i){
  list_t *newNode = (list_t*) malloc(sizeof(list_t));


current->next = newNode;
  newNode->i = i;
  newNode->next = NULL;

  return newNode;
}