#include "aocutils.h"

int calc_score1(char they, char you)
{
	return 6*(they == 'A' && you == 'Y' || 
					  they == 'B' && you == 'Z' ||
					  they == 'C' && you == 'X') +
				 3*(they == 'A' && you == 'X' || 
					  they == 'B' && you == 'Y' ||
					  they == 'C' && you == 'Z') +
					(you - 'X' + 1);
}

int calc_score2(char they, char you)
{
	int move = 	(you == 'X')*((they - 'A' + 2)%3) + 
							(you == 'Y')*(they-'A') + 
							(you == 'Z')*((they-'A'+1)%3);
	return 6*(you == 'Z') + 3*(you == 'Y') + move + 1;
}

int part1(FILE *inputFile)
{
	char s[5] = {0};
	int score = 0;
	while (fgets(s, 5, inputFile) != NULL)
	{
		score += calc_score1(s[0], s[2]);
	}
	return score;
}


int part2(FILE *inputFile)
{
	char s[5] = {0};
	int score = 0;
	while (fgets(s, 5, inputFile) != NULL)
	{
		score += calc_score2(s[0], s[2]);
	}
	return score;
}


int main(int argc, char *argv[]) {
	FILE *inputFile = fopen(argv[1], "r");
	printf("Day 2\n");

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

