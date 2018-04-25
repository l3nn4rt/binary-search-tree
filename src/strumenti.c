#include "intestazioni.h"

/*
* Returns the height of the binary tree with root N.
* height := number of edges in the longest root-leaf walk.
*/
int TreeHeight(node *N) {
	int lHeight, rHeight;
	
	// the leaf does not exist
	if (N == NULL)
		return -1;
	
	// height of left sub-tree
	lHeight = TreeHeight(N->left);
	
	// height of right sub-tree
	rHeight = TreeHeight(N->right);
	
	// returns the max depth reachable from N
	return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

