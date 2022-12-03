#include "aocutils.h"

int score(char item) {
  if (item <= 'Z') {
    return item - 'A' + 27;
  } else {
    return item - 'a' + 1;
  }
}

int part1(char *buf, int bufsize) {
  char *bol = buf;
  char *eol = buf;
  int tot_score = 0;
  char *middle = buf;

  while (1) {
    eol = strchr(bol, '\n');
    if (eol == NULL)
      break;

    // This is OK, it truly is.
    middle = (char *)(((long)eol + (long)bol) >> 1);

    for (char *c1 = bol; c1 < middle; c1++) {
      for (char *c2 = middle; c2 < eol; c2++) {
        if (*c1 == *c2) {
          tot_score += score(*c1);
          // goto's considered useful.
          goto next_rucksack;
        }
      }
    }

  next_rucksack:
    bol = eol + 1;
  }

  return tot_score;
}

// making use of a 64-bit variable to set 1 where Z-A, z-a can be found
int part2(char *buf, int bufsize) {
  int c = 0;
  long rucksack[3] = {0};
  char item = 0;
  int score = 0;
  long badge = 0;

  for (int i = 0; i <= bufsize; i++) {
    item = buf[i];
    if (item >= 'a')
      rucksack[c] |= (long)1 << (item - 'a' + 1);
    else if (item >= 'A')
      rucksack[c] |= (long)1 << (item - 'A' + 27);
    else // basically a new line then..
      c++;

    if (c == 3) {
      badge = rucksack[0] & rucksack[1] & rucksack[2];
      while (!(badge & 1)) {
        score++;
        badge >>= 1;
      }
      c = 0;
      memset(rucksack, 0, sizeof(rucksack));
    }
  }

  return score;
}

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char *buf = malloc(bufsize + 1);
  fread(buf, 1, bufsize, inputFile);
  fclose(inputFile);

  printf("Day 3\n");
  timer = clock() - timer;
  printf("\tBuffering input file: %d bytes in %d µs\n", bufsize,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  timer = clock();
  int part1_solution = part1(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 1 solution: %d (%d µs)\n", part1_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  rewind(inputFile);

  timer = clock();
  int part2_solution = part2(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 2 solution: %d (%d µs)\n", part2_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  free(buf);
}
