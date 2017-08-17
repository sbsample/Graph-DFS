//Staunton Sample
// pa5
//cmps101
//sbsample
// #define _POSIX_C_SOURCE 200809l
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "List.h"
# include "Graph.h"
/*** Constructors-Destructors ***/


// Defines Graph
typedef struct GraphObj
{
    List *adjLists;
    int *color;
    int *parent;
    int *discover;
    int *finish;
    int order;
    int size;
    int source;


}GraphObj;

//newGraph()
// creates new graph with requisite fields
Graph newGraph(int n)
{
    Graph G = malloc(sizeof(GraphObj));
    G -> adjLists = calloc((n + 1), sizeof(List));
    G -> parent = calloc((n + 1), sizeof(int));
    G -> color = calloc((n + 1), sizeof(int));
    G -> discover = calloc((n + 1), sizeof(int));
    G -> finish = calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++)
    {

        G -> adjLists[i] = newList();
        G -> discover[i] = UNDEF;
        G -> finish[i] = UNDEF;
        G -> parent[i] = NIL;
        G -> color[i] = 0;
    }
    G -> source = NIL;
    G -> order = n;
    G -> size = 0;

    return G;
}

// freeGraph()
// frees the graph in memory
void freeGraph(Graph* pG)
{
    // if (pG != NULL && *pG != NULL)
    // {
        for (int i = 1; i < getOrder(*pG); i++ )
        {
            freeList(&(*pG) -> adjLists[i]);
            free((*pG)->adjLists[i]);
            (*pG)->adjLists[i] = NULL;
        }
        free((*pG) -> adjLists);
        free((*pG) -> color);
        free((*pG) -> discover);
        free((*pG) -> finish);
        free((*pG) -> parent);

        (*pG) -> adjLists = NULL;
        (*pG) -> color = NULL;
        (*pG) -> discover = NULL;
        (*pG) -> parent = NULL;
        (*pG) -> finish = NULL;

        free(*pG);
        *pG = NULL;
    // }
}

/*** Access functions ***/
//getDiscover()
// returns discover time of vertex u
int getDiscover(Graph G, int u)
{
    // printf("getDiscover returns :%d\n",G -> discover[u]);
    return G -> discover[u];
}

//getFinish()
// returns finish time of vertex u
int getFinish(Graph G, int u)
{
    // printf("getFinish returns :%d\n",G -> finish[u]);
    return G -> finish[u];
}

// getOrder()
// returns the number of vertices
int getOrder(Graph G)
{
    if (G -> size == 0)
    {
        return NIL;
    }

    return G -> order;
}

//getSize()
// returns size of graph
int getSize(Graph G)
{
    // printf("get size called");
    return G -> size;
}


// getParent()
// returns the parent of of input u
int getParent(Graph G, int u)
{
    return G -> parent[u];
}

// getPath()
// appends to List L the path from u
void getPath(List L, Graph G, int u)
{
    if(u == G -> source)
    {
        append(L, u);
    }
    else if(G -> parent[u] != NIL)
    {
        getPath(L, G, G -> parent[u]);
        append(L, u);
    }
    else
    {
        append(L, NIL);
    }


}
/*** Manipulation procedures ***/
// makeNull()
// Resets Graph G
void makeNull(Graph G)
{
    for (int i = 1; i < G -> size; i++)
    {
        freeList(&G -> adjLists[i]);
        G -> parent[i] = NIL;
        G -> color[i] = 0;
    }
}
// addEdge()
// adds from u to v and v to u
void addEdge(Graph G, int u, int v)
{
    addArc(G,u,v);
    addArc(G,v,u);
    G -> size--;
}
// addArc()
// adds to Adj list u to v
void addArc(Graph G, int u, int v)
{
    moveFront(G -> adjLists[u]);
    for (moveFront(G -> adjLists[u]); index(G -> adjLists[u]) != -1; moveNext(G -> adjLists[u]))
    {

        if (length(G -> adjLists[u]) == 0)
        {
            // printf("addArc size = 0 for insert value u:%d, v:%d \n",u, v);
            append(G -> adjLists[u], v);
            break;
        }
        else if (get(G -> adjLists[u]) > v)
        {
            // printf("addArc else if insert value: u:%d, v:%d \n",u, v);
            insertBefore(G -> adjLists[u], v);
            break;
        }
        else
        {
            // printf("addArc else insert value: u:%d, v:%d \n",u, v);
            insertAfter(G -> adjLists[u], v);
            break;
        }

    }
    G -> size++;
}
// DFS()
// Runs depth first search
void DFS(Graph G, List S)
{
    // printf("pre visit List\n");
    // printf("\n");
    // for (moveFront(S); index(S) != -1; moveNext(S))
    // {
    //      printf("%d ", get(S)) ;
    // }
    // printf("\n");
    int graphTime = 0;
    for (int u = 1; u <= getOrder(G); u++)
    {
        G -> color[u] = 0;
        G -> parent[u] = NIL;
    }
    for (moveFront(S); index(S) != -1; moveNext(S))
    {
        if (G -> color[get(S)] == 0)
        {
            visit(G, S, get(S), &graphTime);
        }
    }
    
    for (int i = 1; i <= getOrder(G); i++)
    {
       deleteBack(S);
    }
    // printf("\n");
    // printf("post visit List\n");
    // for (moveFront(S); index(S) != -1; moveNext(S))
    // {
    //      printf("%d ", get(S));
    // }
    // printf("\n");
}
// visit ()
// recursively visits vertices in DFS
void visit(Graph G, List L, int u, int* t)
{
    // printf("visit called\n");
    int v;
    (*t)++;
    G -> color[u] = 1;
    G -> discover[u] = *t;

    for (moveFront(G -> adjLists[u]); index(G -> adjLists[u]) != -1; moveNext(G -> adjLists[u]))
    {
         if (length(G -> adjLists[u]) == 0)
        {
            break;
        }
        v = get(G -> adjLists[u]);

        if (G -> color[v] == 0)
        {
            G -> parent[v] = u;
            visit(G, L, v, t);
        }
    }
    G -> color[u] = 2;
    (*t)++;
    G -> finish[u] = *t;
    prepend(L,u);


}


/* Other Functions */
// transpose()
// does the filippty flip
Graph transpose(Graph G)
{
    Graph transGraph = newGraph(G -> size);
    for (int i = 0; i <= G -> size; i++)
    {
        for (moveFront(G -> adjLists[i]); index(G -> adjLists[i]) != -1; moveNext(G -> adjLists[i]))
        {
            addArc(G, index(G -> adjLists[i]), i);
        }
    }
    return transGraph;
}

//printGraph()
// prints out graph
void printGraph(FILE* out, Graph G)
{
    for (int i = 1; i <= getOrder(G); i++) {
        fprintf(out,"%d: ",i);
        printList(out, G -> adjLists[i]);
    }
}
