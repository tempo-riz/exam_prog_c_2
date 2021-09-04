#include "tree.h"

// typedef struct _node_t {
// int val;
// struct _node_t *left;
// struct _node_t *right;
// } node_t;

node_t *test(node_t *tree) {
  if (tree->left != NULL) {
    printf("%d\n",tree->val);
    return bst_find_min_node(tree->left);
  } else {
    return tree;
  }
}


void incr(node_t *tree) { 

  if (tree == NULL) {
    return;
  }
  incr(tree->left);
  printf("%d\n", tree->val);
  
  incr(tree->right);
}

void swap(node_t* a,node_t*b){
  node_t tmp=*a;
  *a=*b;
  *b=tmp;
}
void reverse_tree(node_t* tree){
  if(tree==NULL){
    return;
  }
  if(tree->right!=NULL&&tree->left!=NULL){
    swap(tree->right,tree->left);

  }
    reverse_tree(tree->right);
    reverse_tree(tree->left);
}

int* bst_to_array_incr(node_t *tree){
  //pas assez de temps donc j'affiche seulement les valeurs dans l'ordre
  printf("ordre croissant:\n");
  incr(tree);
  printf("\n");
  //  int *values=malloc(sizeof(int)*15);

  return NULL;
}

int* bst_to_array_decr(node_t *tree){
  //pareil 
  printf("ordre decroissant (presque):\n");
  reverse_tree(tree);
  incr(tree);
  // int *values=malloc(sizeof(int)*15);

  return NULL;
}


// peite gauche et plus grand droite
bool bst_is_empty(node_t *tree) { return tree == NULL; }

static node_t *create_node(int val) {
  node_t *node = malloc(sizeof(node_t));
  if (node == NULL) { // memory error
    return NULL;
  }
  node->left = NULL;
  node->right = NULL;
  node->val = val;
  return node;
}

node_t *bst_create() { return NULL; }

void bst_destroy(node_t *tree) {
  if (!bst_is_empty(tree)) {
    if (tree->left != NULL) {
      bst_destroy(tree->left);
    }
    if (tree->right != NULL) {
      bst_destroy(tree->right);
    }
    free(tree);
  }
}

void bst_print(node_t *tree, int depth) { // affiche l'arbre ordre croissant

  if (tree == NULL) {
    return;
  }
  bst_print(tree->left, depth + 1);
  for (int i = 0; i < depth; i++) {
    printf("-------");
  }
  printf(" %d \n\n", tree->val);
  bst_print(tree->right, depth + 1);
}

// insertion de val dans l'arbre et retourne l'arbre (ou NULL si problème)
node_t *bst_insert(node_t *tree, int val) {

  if (bst_is_empty(tree)) { // root
    tree = create_node(val);
  } else {

    if (val > tree->val) { // right
      if (tree->right == NULL) {
        tree->right = create_node(val);
      } else {
        tree->right = bst_insert(tree->right, val);
      }

    } else { // left
      if (tree->left == NULL) {
        tree->left = create_node(val);
      } else {
        tree->left = bst_insert(tree->left, val);
      }
    }
  }
  return tree;
}

// la valeur val est-elle présente dans l'arbre?
bool bst_is_present(node_t *tree, int val) {
  return bst_search(tree, val) != NULL;
}

// retourne le noeud où la valeur val se trouve (NULL si absent)
node_t *bst_search(node_t *tree, int val) {

  if (!bst_is_empty(tree)) {

    if (val == tree->val) { // found it
      return tree;
    } else if (val > tree->val) { // right
      return bst_search(tree->right, val);
    } else { // left
      return bst_search(tree->left, val);
    }
  }

  return NULL;
}

// l'arbre est-il un arbre binaire de recherche?
bool bst_is_bst(node_t *tree) {
  if(tree==NULL){
    return true;
  }
  if (tree->left != NULL && tree->left->val > tree->val) {
    return false;
  }

  if (tree->right != NULL && tree->right->val < tree->val) {
    return false;
  }
  return bst_is_bst(tree->left) && bst_is_bst(tree->right);
}


node_t *bst_find_min_node(node_t *tree) {
  if (tree->left != NULL) {
    return bst_find_min_node(tree->left);
  } else {
    return tree;
  }
}

int bst_find_min(node_t *tree) { return bst_find_min_node(tree)->val; }

node_t *bst_find_max_node(node_t *tree) {
  if (tree->right != NULL) {
    return bst_find_min_node(tree->right);
  } else {
    return tree;
  }
}

int bst_find_max(node_t *tree) { return bst_find_max_node(tree)->val; }

int count_child(node_t *node) {
  int nb = (node->left != NULL) + (node->right != NULL);
  // printf("%d child(s)\n", nb);
  return nb;
}

node_t *bst_delete(node_t *tree, int val) {
  if (!bst_is_empty(tree)) {

    if (val > tree->val) {
      tree->right = bst_delete(tree->right, val); // go right

    } else if (val < tree->val) {
      tree->left = bst_delete(tree->left, val); // go left

      // found node
    } else if (count_child(tree) == 2) {

      node_t *next = bst_find_min_node(tree->right);
      tree->val = next->val;
      tree->right = bst_delete(next, next->val);

    } else { // 1 or 0 childs
      node_t *tmp = tree;
      if (tmp->left != NULL) { // left
        tree = tree->left;
      } else if (tmp->right != NULL) { // right
        tree = tree->right;
      } else {
        tree = NULL;
      }
      free(tmp);
    }
  }
  return tree;
}
