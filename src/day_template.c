#include "aocutils.h"

int part1(FILE *inputFile) { return 0; }

int part2(FILE *inputFile) { return 0; }

int main(int argc, char *argv[]) {
  FILE *inputFile = fopen(argv[1], "r");
  printf("Day #\n");

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

