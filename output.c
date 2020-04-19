#include "output.h"

int findGreatest(int* values, int n) {
	int maxIndex = 0;	
	for(int i = 0; i < n; i++) {
		if(values[maxIndex] < values[i]) {
			maxIndex = i;
		}
	}

	return maxIndex;
}

char* insertString(char* string, char* toBeInserted, int index) {
	int stringLength = strlen(string);
	int toBeInsertedLength = strlen(toBeInserted);
	
	// error checking
	if(!string) {
		return NULL;
	}

	if(!toBeInserted || !toBeInsertedLength) {
		return string;
	}
	
	if(stringLength - index - toBeInsertedLength < 0) {
		// not enough room to fit the string, return null as a failure
		return NULL;
	}

	//insert the string
	for(int i = 0; i < toBeInsertedLength; i++) {
		string[index + i] = toBeInserted[i];
	}

	return string;
}

// h is height of graph, c10 is highest number rounded up to 10
double getLevels(int value, int h, int c10) {
	return (int) (value) / (double) c10 * h;
}

int getGraphWidth(int n, int thick, int c) {
	return n * (thick + 1) + c + 2;
}

// h is height, thick is bar width, n is num things
char** createEmptyGraph(int n, int h, int thick) {
	int c = snprintf(NULL, 0, "%d", h); // required characters for num
	int w = getGraphWidth(n, thick, c); // width of the graph

	// create canvas for graph to be printed on (graph is (-y,x))
	char** graph = calloc(h + 2, sizeof(char*));
	for(int i = 0; i < h + 2; i++) {
		graph[i] = calloc(w + 1, sizeof(char)); 
		memset(graph[i], ' ', sizeof(char) * w);
	}

	return graph;
}

void populateGraph(char** graph, int* values, int n, int h, int thick) {
	
	for(int i = h-1; i >= 0; i--) {
		for(int j = 0; j < getGraphWidth(n, thick, snprintf(NULL, 0, "%d", h)); j++) {

		}
	}

	return;
}

// DEPRECATED FUNCTIONS TO DELETE
/// functions for horizontal bar chartsq
char* horCreateLegend(int graphSize, int maxHeight) {
	// allocate size for the string
	char* string = calloc(graphSize+16, sizeof(char)); //+16 abritrary
	char* temp = calloc(graphSize+8, sizeof(char));

	// convert all to spaces
	for(int i = 0; i < graphSize + 8; i++) {	
		string[i] = ' ';
	}

	// inserts at start, mid, and end
	insertString(string, "0", 0);

	snprintf (temp, graphSize, "%d", maxHeight/2);
	insertString(string, temp, graphSize/2);

	snprintf (temp, graphSize, "%d", maxHeight);
	insertString(string, temp, graphSize);

	// free
	free(temp);

	return string;
}

int horPrintGraph(int thick, int graphSize, int* values, int n){
	int maxIndex = findGreatest(values, n);

	/// set a height for the graph round up to the nearest ten
	int maxHeight = (int) ceil((double) values[maxIndex] / 10.0)*10;

	// create a string to store the information
	char* legend = horCreateLegend(graphSize, maxHeight);
	printf("\t%s\n", legend);
	free(legend);

	// output the boxes
	for(int i = 0; i < n; i++) {
		printf("%d\t", values[i]);

		int k = (int) (values[i] / (float) maxHeight * graphSize);

		// print the bars
		for(int bar = 0; bar < thick; bar++) {
			for(int j = 0; j < k; j++) {
				printf("█");
			}
			printf("\n\t");
		}
		printf("\n");
	}

	// if successful return non zero
	return maxHeight;
}
