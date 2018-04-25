#include "intestazioni.h"

/*
* Adds a new node with key Str to the binary search tree T.
*/
node *BSTInsert(node *T, char *Str){
	node *p = T, *q = NULL;
	
	while (p != NULL) {
		q = p;
		if (atoi(Str) < atoi(p->key))
			p = p->left;
		else
			p = p->right;
	}
	// now q points to the father of the new node
	
	p = malloc(sizeof(node));
	p->left = p->right = NULL;
	p->key = strdup(Str);
	
	p->parent = q;
	if (q != NULL) {
		if (atoi(p->key) < atoi(q->key))
			q->left = p;
		else
			q->right = p;
	}
	if (T == NULL)
		T = p;
	return T;
}

