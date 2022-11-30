#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_LENGTH 3000
#define MAX_RET_STR_LEN 100

typedef struct part1_ret{
	char text[MAX_RET_STR_LEN];
} PART1;

typedef struct part2_ret{
	char text[MAX_RET_STR_LEN];
} PART2;

PART1 part1(FILE *inputFile)
{
	PART1 ret = {0};	
	snprintf(ret.text, MAX_RET_STR_LEN, "%d", 0);
	return ret;	
}


PART2 part2(FILE *inputFile)
{
	PART2 ret = {0};	

	snprintf(ret.text, MAX_RET_STR_LEN, "%d", 0);
	return ret;	
}


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[1], "r");
	printf("Day #\n");

	clock_t timer = clock();
	PART1 part1_solution = part1(inputFile);
	timer = clock() - timer;
	printf("Part 1 solution: %s (%f ms)\n", part1_solution.text, (double)timer/CLOCKS_PER_SEC*1000);
	
	rewind(inputFile);
	
	timer = clock();
	PART2 part2_solution = part2(inputFile);
	timer = clock() - timer;
	printf("Part 2 solution: %s (%f ms)\n", part2_solution.text, (double)timer/CLOCKS_PER_SEC*1000);

	fclose(inputFile);
}

