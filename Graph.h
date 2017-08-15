//Staunton Sample
// pa4
//cmps101
//sbsample
// #define _POSIX_C_SOURCE 200809l
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "List.h"
/*** Constructors-Destructors ***/
#define UNDEF -2
#define NIL -1

typedef struct GraphObj* Graph;
Graph newGraph(int n);
void freeGraph(Graph* pG);
/*** Access functions ***/
int getOrder(Graph G);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);
int getSize(Graph G);
int getParent(Graph G, int u);
void visit(Graph G, List L, int u, int* t);

void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */

/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
/* Other Functions */
Graph transpose(Graph G);
void printGraph(FILE* out, Graph G);
