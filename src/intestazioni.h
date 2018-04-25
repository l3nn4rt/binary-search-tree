#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* A node consists of three pointers to near nodes and one string key.
* Note: keys are not unique, thus various nodes can have the same key.
*/
typedef struct BSTnode {
	struct BSTnode *parent, *left, *right;
	char *key;
} node;

/*
* Adds a new node with key Str to the binary search tree R.
* Despite keys are stored as strings, the insertion follows the path established
* by a numerical order and places the new node as a leaf.
* Strings that cannot be evaluated as integers will be treated as zeros. 
*/
node *BSTInsert(node *R, char *Str);

/*
* Returns the height of the binary tree with root R.
* Recursively, establishes the height of left and right sub-trees.
*/
int TreeHeight(node *R);

/*
* Prints the binary tree R level by level.
* First determines the minimum necessary tree width with a recersive analysis.
* After uses a deque for a breadth-first visit.
*/
void TreePrint(node *R);

