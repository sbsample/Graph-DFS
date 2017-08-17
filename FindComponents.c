//Staunton Sample
// pa5
//cmps101
//sbsample
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "List.h"
#include "Graph.h"
#include<string.h>

int main(int argc, char* argv[]){
	FILE* in;
	FILE* out;
	int vertices = 0;
	int u, v;


	if(argc != 3){
		fprintf(stderr,"Needs two files\n");
		exit(1);
	}
	/*opening the file for reading and writing*/
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");

	char row[256];
	int rows = 0;

	fscanf(in, "%d", &vertices);

	while(fgets(row, 256, in) != NULL)
	{
		rows++;
	}

	int size = (rows * 2) - 1;

	fclose(in);
	in = fopen(argv[1], "r");
	int counter = 0;

	Graph adjList = newGraph(vertices);
	while (counter < size && u != 0)
	{
		fscanf(in, "%d %d", &u, &v);
		addArc(adjList, u, v);
	}

	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, adjList);
	fprintf(out, "\n");

	fprintf(out, "vertices %d\n", vertices);
	fprintf(out, "rows: %d\n",rows );




	freeGraph(&adjList);

}
