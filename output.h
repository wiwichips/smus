#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// returns the number of blocks required for each value in values
// returns a malloc'd array that must be freed
double getLevels(int value, int h, int c10);

// returns horizontal size of graph
int getGraphWidth(int n, int thick, int c);



/// graph functions
// creates an empty canvas for the graph
char** createEmptyGraph(int n, int h, int thick);
// returns the graph as a 2d string
void populateGraph(char** graph, int* values, int n, int h, int thick);

// returns the index of the greatest value of the array
int findGreatest(int* values, int numValues);

//inserts one string into another one at index. return null on fail
/*
	string must not be weird
*/
char* insertString(char* string, char* toBeInserted, int index);



/// functions for horizontal bar charts
// creates a string to use for the legend measure (string must free)
char* horCreateLegend(int graphSize, int maxHeight); 

// prints the graph horizontally
int horPrintGraph(int thick, int graphSize, int* values, int numValues);

