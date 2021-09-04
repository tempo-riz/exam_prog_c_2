#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct _node_t {
int val;
struct _node_t *left;
struct _node_t *right;
} node_t;

//BINARY SEARCH TREE (BST)

// Fonctions de création, destruction et affichage
node_t *bst_create(); // création d'un arbre vide (retourne NULL)
void bst_destroy(node_t *tree); // détruit l'arbre et vide la mémoire

void bst_print(node_t *tree, int depth); // affiche l'arbre (voir plus bas)
// insertion de val dans l'arbre et retourne l'arbre (ou NULL si problème)
node_t *bst_insert(node_t *tree, int val);
// efface le premier élément contenant la valeur val dans l'arbre
// et retourne l'arbre (ne fait rien si val est absente)
node_t *bst_delete(node_t *tree, int val);
// la valeur val est-elle présente dans l'arbre?
bool bst_is_present(node_t *tree, int val);
// retourne le noeud où la valeur val se trouve (NULL si absent)
node_t *bst_search(node_t *tree, int val);
// l'arbre est-il un arbre binaire de recherche?
bool bst_is_bst(node_t *tree);
// retourne le noeud avec la valeur minimale de l'arbre (NULL s'il y a pas)
node_t *bst_find_min_node(node_t *tree);
// retourne la valeur la plus petite stockée dans l'arbre (ou MIN_INT)
int bst_find_min(node_t *tree);
// retourne le noeud avec la valeur maximale de l'arbre (NULL s'il y a pas)
node_t *bst_find_max_node(node_t *tree);
// retourne la valeur la plus grande stockée dans l'arbre (ou MAX_INT)
int bst_find_max(node_t *tree);

int count_child(node_t *node);

int* bst_to_array_incr(node_t *tree);

int* bst_to_array_decr(node_t *tree);

int* bst_find_min_and_free(node_t *tree);

#endif