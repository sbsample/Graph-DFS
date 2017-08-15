//Staunton Sample
// pa4
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
	char* token;
	int veritces;
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

	Graph adjList = new Graph;
	while (counter < size && u != 0) 
	{
		fscanf(in, "%d ", &u, &v);
		addArc(addArc, u, v);
	}
	
	
	

	free(&adjList);
	
}
