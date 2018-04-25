#include <stdlib.h>
#include "deque.h"

Deque *createDeque(void) {
	Deque *D = (Deque *) malloc(sizeof(Deque));
	// if a new deque was creted, it is initialized as empty
	if (D != NULL) {
		D->top = D->bottom = NULL;
	}
	return D;
}

Deque *deleteDeque(Deque *D) {
	struct DequeNode *p;
	
	// empties the deque
	if (D != NULL) {
		p = D->top;
		while (p != NULL && p->succ != NULL) {
			p = p->succ;
			free(p->prec);
		}
		free(p);
		// memory to null
		D->top = D->bottom = NULL;
		D->count = 0;
		// finally, deletes the struct deque
		free(D);
	}
	return NULL;
}

short isEmpty(Deque *D) {
	// there is no deque: ERROR
	if (D == NULL) return -1;
	// deque is empty
	if (D->top == NULL && D->bottom == NULL) return 1;
	// deque is corrupted: ERROR
	if (D->top == NULL || D->bottom == NULL) return -2;
	// deque is not empty
	return 0;
}

Deque *pushFront(Deque *D, void *newptr) {
	struct DequeNode *p;
	
	if (D != NULL) {
		p = (struct DequeNode *) malloc(sizeof(struct DequeNode));
		if (p == NULL) exit(-1);
		
		p->ptr = newptr;
		p->prec = NULL;
		p->succ = D->top;
		D->top = p;
		// there was at least another node
		if (p->succ != NULL) {
			p->succ->prec = p;
		}
		// p is the only node
		if (D->bottom == NULL) {
			D->bottom = p;
		}
		D->count++;
	}
	return D;
}

Deque *pushBack(Deque *D, void *newptr) {
	struct DequeNode *p;
	
	if (D != NULL) {
		p = (struct DequeNode *) malloc(sizeof(struct DequeNode));
		if (p == NULL) exit(-2);
		
		p->ptr = newptr;
		p->succ = NULL;
		p->prec = D->bottom;
		D->bottom = p;
		// there was at least another node
		if (p->prec != NULL) {
			p->prec->succ = p;
		}
		// p is the only node
		if (D->top == NULL) {
			D->top = p;
		}
		D->count++;
	}
	return D;
}

void *top(Deque *D) {
	if (D != NULL && D->top != NULL)
		return D->top->ptr;
	return NULL;
}

void *bottom(Deque *D) {
	if (D != NULL && D->bottom != NULL)
		return D->bottom->ptr;
	return NULL;
}

void *popFront(Deque *D) {
	void *p = NULL;
	struct DequeNode *t;
	// if deque is not empty and has first node
	if (D != NULL && D->top != NULL) {
		t = D->top;
		p = t->ptr;
		
		D->top = t->succ;
		if (D->top != NULL) {
			D->top->prec = NULL;
		}
		// deque is empty
		if (D->top == NULL) {
			D->bottom = NULL;
		}
		free(t);
		D->count--;
	}
	return p;
}

void *popBack(Deque *D) {
	void *p = NULL;
	struct DequeNode *b;
	// if deque is not empty and has last node
	if (D != NULL && D->bottom != NULL) {
		b = D->bottom;
		p = b->ptr;
		
		D->bottom = b->prec;
		if (D->bottom != NULL) {
			D->bottom->succ = NULL;
		}
		// deque is empty
		if (D->bottom == NULL) {
			D->top = NULL;
		}
		free(b);
		D->count--;		
	}
	return p;
}

unsigned nodeCount(Deque *D) {
	return D->count;
}

