#include "aocutils.h"

#define MAX_INPUT_LENGTH 3000
#define MAX_RET_STR_LEN 100
#define MAX_ELVES 2500

typedef struct part1_ret{
	char text[MAX_RET_STR_LEN];
} PART1;

typedef struct part2_ret{
	char text[MAX_RET_STR_LEN];
} PART2;

PART1 part1(FILE *inputFile)
{
	PART1 ret = {0};
  int calories[MAX_ELVES] = {0};
  int elf = 0;
	int max = 0;
  char s[10] = {0};
  while (fgets(s, 10, inputFile) != NULL) {
		calories[elf] += ato_ui(s);	
		max = max + (calories[elf]-max)*(calories[elf]>max);
		elf += strlen(s) < 2;
  }

  snprintf(ret.text, MAX_RET_STR_LEN, "%d", max);
  return ret;	
}


PART2 part2(FILE *inputFile)
{
	PART2 ret = {0};	
  int calories[MAX_ELVES] = {0};
  int elf = 0;
	int max[3] = {0};
  char s[7] = {0};
	int len = 0;

  while (fgets(s, 10, inputFile) != NULL) {
		len = strlen(s);
		if(len > 2){
			calories[elf] += ato_ui(s);
 			continue; 
		}

		for (int i=0; i<3; i++)
		{
			if (calories[elf] > max[i]){
				for(int j=2; j > i; j--) max[j] = max[j-1];	
				max[i] = calories[elf];
				break;
			}
		}
		//printf("[%d,%d,%d]\n",max[0],max[1],max[2]);

		elf += len < 2;
  }

	int total = max[0]+max[1]+max[2];
	snprintf(ret.text, MAX_RET_STR_LEN, "%d", total);
	return ret;	
}


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[1], "r");
	printf("Day 1\n");

	clock_t timer = clock();
	PART1 part1_solution = part1(inputFile);
	timer = clock() - timer;
	printf("\tPart 1 solution: %s (%d µs)\n", part1_solution.text,
				 (int)((double)timer / CLOCKS_PER_SEC * 1000000));

	rewind(inputFile);
	
	timer = clock();
	PART2 part2_solution = part2(inputFile);
	timer = clock() - timer;
	printf("\tPart 2 solution: %s (%d µs)\n", part2_solution.text,
				 (int)((double)timer / CLOCKS_PER_SEC * 1000000));

	fclose(inputFile);
}

