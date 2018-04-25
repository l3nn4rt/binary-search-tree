/*
 * [EN]
 * A deque is both a stack and a queue.
 *
 * This implementation of deque uses a pointer to the struct Deque.
 * A deque node contains the pointer that was passed when created.
 * Extracting (deleting) a node does not modify the content of the pointer it 
 * is containing.
 * A struct Deque contanins two pointers, to the first (front) and 
 * to the last (back) nodes of the deque.
 *
 * A deque does not exist if the referencing pointer is NULL.
 * An empty deque is a pointer (not NULL) to a couple of NULL pointers.
 * A new deque is an empty deque.
 * Deletion of a deque implies deletion of all its nodes and deletion of the 
 * struct Deque (couple of pointer front and back).
 *
 *
 * [IT]
 * Una deque è sia una pila che una coda.
 *
 * Questa implementazione di deque usa un puntatore alla struct Deque.
 * Il nodo di una deque contiene il puntatore passato quando è stato creato.
 * L'estrazione (rimozione) di un nodo non modifica il contenuto del puntatore 
 * al suo interno. 
 * Una struct Deque contiene due puntatori, al primo nodo (front) ed 
 * all'ultimo nodo (back) della deque.
 *
 * Una deque non esiste se il puntatore che la referenzia è NULL.
 * Una deque vuota è un puntatore (non NULL) ad una coppia di puntatori NULL.
 * Una nuova deque è una deque vuota.
 * La cancellazione di una deque ne comporta la cancellazione dei nodi 
 * e della relativa struct Deque (coppia di puntatori front e back).
 */

#ifndef _DEQUE_H_
#define _DEQUE_H_

struct DequeNode {
    void *ptr;
    struct DequeNode *succ;
    struct DequeNode *prec;
};

struct Deque {
	unsigned count;
	struct DequeNode *top;
	struct DequeNode *bottom;
};

typedef struct Deque Deque;

// creates a new, empty, deque
Deque *createDeque(void);
// destroys deque and nodes (not what it was containing)
Deque *deleteDeque(Deque *);

// returns the ptr in the first node (without removing it)
void *front(Deque *);
// returns the ptr in the last node (without removing it)
void *back(Deque *);

// adds a node at the front of the deque
Deque *pushFront(Deque *, void *);
// adds a node at the back of the deque
Deque *pushBack(Deque *, void *);

// removes the node at the front and returns its ptr
void *popFront(Deque *);
// removes the node at the back and returns its ptr
void *popBack(Deque *);

// verifies the presence (0) or absence (1) of nodes in a deque;
// can return errors:
//	-1) deque does not exist;
//	-2) deque is corrupted.
short isEmpty(Deque *);

// returns the non-negative number of nodes in a deque
unsigned nodeCount(Deque *);

#endif

