#include "intestazioni.h"
#include "deque.h"

/*
* Box-Drawing Chars 
*/
#define RB "\e(0\x6a\e(B" // Right Bottom corner
#define RT "\e(0\x6b\e(B" // Right Top corner
#define LB "\e(0\x6d\e(B" // Left Bottom corner
#define LT "\e(0\x6c\e(B" // Left Top corner
#define BC "\e(0\x76\e(B" // Bottom Cross
#define HL "\e(0\x71\e(B" // Horizontal Line

/*
* Returns the necessary tree width that allows all the leaves not to be truncated.
*/
int NecessarySpace(node *p, int height) {
	int local, sl, left, right, below;
	
	if (p == NULL) return 0;
	
	left = NecessarySpace(p->left, height - 1);
	right = NecessarySpace(p->right, height - 1);
	below = (left > right ? left : right);
	
	// defines needed space by p->key at distance height from tree bottom
	local = 0; sl = strlen(p->key);
	while (sl > (1 << (local + height)) - 1) local++;
	
	return (local > below ? local : below);
}

void TreePrint(node *T) {
	int i, height, j, levelNodes;
	int sizeBDC, span, width, sons;
	int keyLen, lSpan, rSpan;
	char *edgeStr, *spaceStr;
	node *np;
	Deque *printDeque;
	
	height = TreeHeight(T);
	width = NecessarySpace(T, height);
	sizeBDC = sizeof(HL);
	levelNodes = 1;
	sons = 0;
	
	// creates a print queue and pushes tree root into it
	printDeque = createDeque();
	pushBack(printDeque, T);
	
	for (i = 0; i < height + 1; i++) {
		// expresses the distance among elements in function of the level
		span = (1 << (height - i + width - 1)) - 1;
		
		// creates a string for the edges with box-drawing chars
		edgeStr = (char *) malloc(span * sizeBDC + sizeof(char)); // (*)
		edgeStr[0] = edgeStr[sizeBDC * span] = '\0';
		for (j = 0; j < span; j++) strcat(edgeStr, HL);
		
		// and one for absent edges and nodes with empty spaces
		spaceStr = (char *) malloc ((span + 1) * sizeof(char)); // (**)
		for (j = 0; j < span; j++) spaceStr[j] = ' ';
		spaceStr[span] = '\0';
		
		/***** EDGE SECTION BEGIN *****/
		for (j = 0; i != 0 && j < levelNodes; j++) {
			// extracts a node
			np = popFront(printDeque);
			
			// sons stores infos about each couple of brothers
			// each bit represents precence/absence a specific brother
			// j = 0 => +1 : there is the 0th (left) brother
			// j = 1 => +2 : there is the 1st (right) brother
			if (np != NULL) sons += 1 << (j % 2);
			
			if (j % 2 == 0) {
				// left edge
				if (np != NULL) printf("%s%s%s", spaceStr, LT, edgeStr);
				else printf("%s %s", spaceStr, spaceStr);
			} else {
				// parent derivation char
				if (sons == 0) printf(" ");
				if (sons == 1) printf(RB);
				if (sons == 2) printf(LB);
				if (sons == 3) printf(BC);
				sons = 0;
				
				// right edge
				if (np != NULL) printf("%s%s%s", edgeStr, RT, spaceStr);
				else printf("%s %s", spaceStr, spaceStr);
				
				// separator among "cousin" nodes' edges
				printf(" ");
			}
			
			// pushes back the node for the key print
			pushBack(printDeque, np);
		}
		if (i != 0) printf("\n");
		
		/***** EDGE SECTION END *****/
		
		/***** NODE SECTION BEGIN *****/
		for (j = 0; j < levelNodes; j++) {
			// extracts a node
			np = popFront(printDeque);
			
			if (np != NULL) {
				// balances the spaces on the sides of the key
				keyLen = strlen(np->key);
				lSpan = span - keyLen / 2;
				rSpan = span + keyLen / 2 - keyLen + 1;
				
				printf("%*s%s%*s", lSpan, "", np->key, rSpan, "");
			} else {
				printf("%s %s", spaceStr, spaceStr);
			}
			// separator among nodes
			printf(" ");
			
			// adds the child nodes to the print queue 
			if (np != NULL) {
				pushBack(printDeque, np->left);
				pushBack(printDeque, np->right);
			} else {
				pushBack(printDeque, NULL);
				pushBack(printDeque, NULL);
			}
		}
		printf("\n");
		/***** NODE SECTION END *****/
		
		free(edgeStr); // (*)
		free(spaceStr); // (**)
		
		levelNodes *= 2;
	}
}

