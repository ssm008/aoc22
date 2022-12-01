#include "aocutils.h"

int part1(FILE *inputFile)
{
  int calories = 0;
	int max = 0;
  char s[10] = {0};
  while (fgets(s, 10, inputFile) != NULL) {
		calories += atoi(s);	
		max = max + (calories-max)*(calories>max);
		calories *= s[0] != '\n';
  }

  return max;	
}


int part2(FILE *inputFile)
{
  int calories = 0;
	int max[3] = {0};
  char s[7] = {0};

  while (fgets(s, 7, inputFile) != NULL) {
		if(s[0] != '\n'){
			calories += atoi(s);
 			continue; 
		}

		for (int i=0; i<3; i++)
		{
			if (calories > max[i]){
				for(int j=2; j > i; j--) max[j] = max[j-1];	
				max[i] = calories;
				break;
			}
		}

		calories = 0;
  }

	int total = max[0]+max[1]+max[2];
	return total;
}


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[1], "r");
	printf("Day 1\n");

	clock_t timer = clock();
	int part1_solution = part1(inputFile);
	timer = clock() - timer;
	printf("\tPart 1 solution: %d (%d µs)\n", part1_solution,
				 (int)((double)timer / CLOCKS_PER_SEC * 1000000));

	rewind(inputFile);
	
	timer = clock();
	int part2_solution = part2(inputFile);
	timer = clock() - timer;
	printf("\tPart 2 solution: %d (%d µs)\n", part2_solution,
				 (int)((double)timer / CLOCKS_PER_SEC * 1000000));

	fclose(inputFile);
}

