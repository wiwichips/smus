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
double getLevelRatio(int value, int h, int c10) {
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
	return snprintf(NULL, 0, "%d ", scaleHeight);
}

int getLevel(int* values, int n, int index, int h) {
	int c10 = getScaleHeight(values, n);
	return (int) getLevelRatio(values[index], h, c10);
}

/// Modifier functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void populateGraph(char** graph, int* values, int n, int h, int thick) {
	int marg = getMarginSize(values, n);
	int width = getGraphWidth(values, n, thick); // width of the graph

	for(int i = 0, b = 0, p = 0, s = 1; i < width - marg; i++) {

		if(++p >= thick + 1) {
			p = 0;
			b++;
			printf("b = %d\n", b);
		}

		int level = getLevel(values, n, b, h);

		for(int j = h - 1; j >= 0; j--) {
			if(h - j < level) {
				graph[j][i + marg] = '#';
			} else if (s) {
				graph[j][i + marg] = '0' + b;
				s = 0;
			}
		}
		s = 1;
	}

	// add y margin labels
	insertString(graph[0], "40", 0);
	insertString(graph[h/2], "20", 0);
	insertString(graph[h-1], "0", 0);

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
