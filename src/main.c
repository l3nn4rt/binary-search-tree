#include "intestazioni.h"
#include <unistd.h>

/*
* Uses arguments to create a BST; if no argument is passed, demo is used.
*/
int main(int argn, char *args[]) {
	node *T = NULL;
	int i = 1;
	char *demo[] = {"66",	"88",	"33",	"99",	"77",	"2",	"44",	"55",
			"tree",	"999",	"33",	"123",	"77",	"88",	"52",	"70",
			"22",	"5",	"1",	"-88",	"75"};
	
	// demo
	if (argn == 1) {
		i = 0;
		args = demo;
		argn = 21;
	}
	
	for (; i < argn; i++) {
		// clear previous print
		printf("\033[%dA\n", 2 * TreeHeight(T) + 2);
		
		// adding nodes
		T = BSTInsert(T, args[i]);
		// printing
		TreePrint(T);
		
		usleep(250000);
	}
	
	return 0;
}

