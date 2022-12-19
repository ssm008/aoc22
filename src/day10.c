#include "aocutils.h"

int getInstruction(char **buf, int *isNoop) {
  char *c = *buf;
  int r = 0;
  int len = 4;

  *isNoop = *c == 'n';
  len += 1 - *isNoop;

  int sign = 1;
  if (*(c + len) == '-') {
    sign = -1;
    len++;
  }

  while (*(c + len) >= '0' && *(c + len) <= '9') {
    r = 10 * r + (int)(*(c + len) - '0');
    len++;
  }

  *buf += len + 1;
  return sign * r;
}

int part1(char *buf, int bufsize) {
  int isNoop = 0;
  char *c = buf;
  int register_value = 1;
  int value = 0;
  int cycle = 0;
  int sigstrength = 0;
  while (c <= buf + bufsize) {
    value = getInstruction(&c, &isNoop);
    cycle++;
    if ((cycle - 20) % 40 == 0 || cycle == 20) {
      sigstrength += cycle * register_value;
    }

    if (!isNoop) {
      cycle++;
      if ((cycle - 20) % 40 == 0 || cycle == 20) {
        sigstrength += cycle * register_value;
      }
    }

    register_value += value;
  }
  return sigstrength;
}

int part2(char *buf, int bufsize) {
  int isNoop = 0;
  char *c = buf;
  int register_value = 1;
  int value = 0;
  int cycle = 0;
  char CRT[6][40];
  char *w = &CRT[0][0];
  while (c <= buf + bufsize) {
    value = getInstruction(&c, &isNoop);
    if (cycle % 40 >= register_value - 1 && cycle % 40 <= register_value + 1) {
      w[cycle] = '#';
    } else {
      w[cycle] = '.';
    }
    cycle++;

    if (!isNoop) {
      if (cycle % 40 >= register_value - 1 &&
          cycle % 40 <= register_value + 1) {
        w[cycle] = '#';
      } else {
        w[cycle] = '.';
      }
      cycle++;
    }

    register_value += value;
  }

  for (int r = 0; r < 6; r++) {
    for (int c = 0; c < 40; c++) {
      printf("%c", CRT[r][c]);
    }
    printf("\n");
  }

  return 0;
}

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[1000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 10\n");
  timer = clock() - timer;
  printf("\tBuffering input file: %d bytes in %d µs\n", bufsize,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  timer = clock();
  int part1_solution = part1(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 1 solution: %d (%d µs)\n", part1_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  timer = clock();
  int part2_solution = part2(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 2 solution: %d (%d µs)\n", part2_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));
}
