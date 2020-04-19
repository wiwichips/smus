#include "output.h"

/// Create Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char** createEmptyGraph(int* values, int n, int h, int thick) {
	int w = getGraphWidth(values, n, thick); // width of the graph

	// create canvas for graph to be printed on (graph is (-y,x))
	char** graph = calloc(h + 2, sizeof(char*));
	for(int i = 0; i < h + 2; i++) {
		graph[i] = calloc(w + 1, sizeof(char)); 
		memset(graph[i], ' ', sizeof(char) * w);
	}

	return graph;
}

/// Delete functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// Getter functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double getLevels(int value, int h, int c10) {
	return (int) (value) / (double) c10 * h;
}

int getGraphWidth(int* values, int n, int thick) {
	int c = getMarginSize(values, n);
	return n * (thick + 1) + c + 2;
}

int getGreatest(int* values, int n) {
	int maxIndex = 0;	
	for(int i = 0; i < n; i++) {
		if(values[maxIndex] < values[i]) {
			maxIndex = i;
		}
	}

	return maxIndex;
}

int getScaleHeight(int* values, int n) {
	int maxIndex = getGreatest(values, n);
	return (int) ceil((double) values[maxIndex] / 10.0)*10;
}

int getMarginSize(int* values, int n) {
	int scaleHeight = getScaleHeight(values, n);
	return snprintf(NULL, 0, "%d", scaleHeight);
}

/// Modifier functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void populateGraph(char** graph, int* values, int n, int h, int thick) {
	int w = getGraphWidth(values, n, thick); // width of the graph

	for(int i = h-1; i >= 0; i--) {
		for(int j = 0; j < w; j++) {

		}
	}

	return;
}

char* insertString(char* string, char* toBeInserted, int index) {
	int stringLength = strlen(string);
	int toBeInsertedLength = strlen(toBeInserted);
	
	// error checking
	if(!string || stringLength - index - toBeInsertedLength < 0) {
		return NULL;
	}

	//insert the string
	for(int i = 0; i < toBeInsertedLength; i++) {
		string[index + i] = toBeInserted[i];
	}

	return string;
}

/// Deprecated functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
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
	int maxIndex = getGreatest(values, n);

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
*/
