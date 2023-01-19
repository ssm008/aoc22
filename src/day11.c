#include "aocutils.h"

typedef struct q {
  int item[40];
  int head;
  int back;
} item_queue;

typedef struct monkey {
  int id;
  item_queue queue;
  int op;
  int opval;
  int ttest;
  int ttrue;
  int tfalse;
} monkey;

void throw_to(monkey *from, monkey *to) {}

int part1(char *buf, int bufsize) {
  char *c = buf;
  monkey m[8] = {0};

  int len = 0;
  int i = 0;
  while (c <= buf + bufsize) {
    getNumsOnLine(c, &m[i].id, &len);
    c += len;
    getNumsOnLine(c, m[i].queue.item, &len);
    while (m[i].queue.item[m[i].queue.back++]) {
    }
    c += len;
    getNumsOnLine(c, &m[i].opval, &len);
    if (c[23] == '*')
      m[i].op = 0;
    else if (c[23] == '+')
      m[i].op = 1;
    c += len;
    getNumsOnLine(c, &m[i].ttest, &len);
    c += len;
    getNumsOnLine(c, &m[i].ttrue, &len);
    c += len;
    getNumsOnLine(c, &m[i].tfalse, &len);
    c += len + 1;
    i++;
  }

  int item = 0;
  int inspections[8] = 0;
  for (int round = 0; round < 20; round++) {
    for (i = 0; i < 8; i++) {
      while (m[i].queue.head < m[i].queue.back) {
        item = m[i].queue.item[m[i].queue.head];
        inspections[i]++;
      }
    }
  }

  return 0;
}

int part2(char *buf, int bufsize) { return 0; }

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[700];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 11\n");
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
