#include "driver.h"

int driver() {

	int n = 11;
	int h = 5;

	int* values = calloc(n, sizeof(int));

	values[0] = 30;
	values[1] = 31;
	values[2] = 32;
	values[3] = 33;
	values[4] = 34;
	values[5] = 35;
	values[6] = 36;
	values[7] = 37;
	values[8] = 38;
	values[9] = 39;
	values[10] = 40;

	// printf("returnTwo test = %d\n", horPrintGraph(1, h, values, n));

	int* levels = calloc(n, sizeof(int));
	int* slabs = calloc(n, sizeof(int));

	// get information for bar levels
	for(int i = 0; i < n; i++) {
		levels[i] = (int) getLevels(values[i], h, 40);
	}

	// get information for slabs
	for(int i = 0; i < n; i++) {
		slabs[i] = (int) (getLevels(values[i], h, 40) * 8 - levels[i] * 8);
	}

	for(int i = 0; i < n; i++) {
		printf("%d ~ ", values[i]);
		for(int j = 0; j < levels[i]; j++) {
			printf("#");
		}
		printf("%d\n", slabs[i]);
	}



	free(values);
	free(levels);
	free(slabs);

	return 0;
}

