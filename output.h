#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/// Create Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** creates an empty canvas for the graph
 *@pre values has been set
 *@post return value needs to be deleted (freed)
 *@return 2d char array representing the canvas for a bar chart
 *@param values - array of scrobbles per bar
 *@param n - number of bars / elements in the values array
 *@param h - height of the bar chart (total height is h + 2)
 *@param thick - how many characters thick each bar is
**/
char** createEmptyGraph(int* values, int n, int h, int thick);


/// Delete functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


/// Getter functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Gets the number of blocks for a specified height
 *@return number of blocks required for each value given a height h
 *@param value - scrobble for a specific bar
 *@param h - height of the bar chart
 *@param c10 - highest value rounded up to nearest ten, used for scale
**/
double getLevels(int value, int h, int c10);

/** Gets the width of the graph canvas 
 *@return graph width
 *@param n - number of bars
 *@param thick - how many characters wide each bar is
 *@param values - array of scrobbles per bar
**/
int getGraphWidth(int* values, int n, int thick);

/** Gets the index of the greatest value of the array
 *@pre values has been set
 *@return the index for the greatest value in values
 *@param values - array of scrobbles per bar
 *@param n - number of bars / elements in the values array
**/
int getGreatest(int* values, int n);

// 
/** Gets the scale height for the y axis label measurement
 *@pre values has been set
 *@return the number for the top of the bar chart 
 *@param values - array of scrobbles per bar
 *@param n - number of bars / elements in the values array
**/
int getScaleHeight(int* values, int n);

int getMarginSize(int* values, int n);

/// Modifier functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Populates the graph with the bars of scrobbles per period
 *@pre graph canvass has been created, values has been set
 *@param graph - 2d char array for the canvas to draw the graph on
 *@param values - array of scrobbles per bar
 *@param n - number of bars / elements in the values array
 *@param h - the height of the graph (total height is h + 2)
 *@param thick - how many characters wide each bar is
**/
void populateGraph(char** graph, int* values, int n, int h, int thick);

/** Inserts a string in another string at a given index
 *@pre both strings are not NULL, index is valid
 *@post returns null on failure
 *@return the pointer to the original string, NULL on failure
 *@param string - the original string
 *@param toBeInserted - the string to be placed inside of string
 *@param index - the index of origina string that starts where inserti
**/
char* insertString(char* string, char* toBeInserted, int index);


/// Deprecated functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// creates a string to use for the legend measure (string must free)
char* horCreateLegend(int graphSize, int maxHeight); 

// prints the graph horizontally
int horPrintGraph(int thick, int graphSize, int* values, int numValues);

