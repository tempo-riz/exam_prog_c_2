#include "tree.h"

int main() {

  node_t *tree = bst_create();
  int input[15];

  for(int i=0;i<15;i++){
    scanf("%d",&input[i]);
    tree = bst_insert(tree, input[i]);
  }
  
  // manque de temps je fais l'affichage seulement

  bst_to_array_incr(tree);
  bst_to_array_decr(tree);

 
  bst_destroy(tree);
}