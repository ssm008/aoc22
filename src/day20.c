#include "aocutils.h"

struct node {
  int value;
  struct node *c;
  struct node *p;
};

struct node numbers[5001];

int part1(char *buf, int bufsize) {
  char *c = buf;
  int num = 0;
  int sign = 1;
  struct node *zero;
  while (c <= buf + bufsize - 1) {
    sign = 1 - 2 * (*c == '-');
    c += *c == '-';
    while (*c >= '0' && *c <= '9') {
      numbers[num].value = numbers[num].value * 10 + *(c++) - '0';
    }
    if (numbers[num].value == 0) {
      zero = &numbers[num];
    }
    numbers[num++].value *= sign;
    numbers[num].p = &numbers[num - 1];
    numbers[num - 1].c = &numbers[num];
    c++;
  }
  num--;
  // connect the ends.
  numbers[num].c = &numbers[0];
  numbers[0].p = &numbers[num];

  // mix it up
  struct node *target;
  for (int i = 0; i <= num; i++) {
    target = &numbers[i];
    sign = numbers[i].value < 0;
    if (sign) {
      for (int s = 0; s >= numbers[i].value; s--) {
        target = target->p;
      }
    } else {
      for (int s = 0; s <= numbers[i].value; s++) {
        target = target->c;
      }
    }
    numbers[i].p->c = numbers[i].c;
    numbers[i].c->p = numbers[i].p;
    numbers[i].p = target->p;
    numbers[i].c = target;
    target->p->c = &numbers[i];
    target->p = &numbers[i];
  }

  int numafterzero[3] = {1000, 2000, 3000};
  for (int i = 0; i < 3; i++) {
    numafterzero[i] = numafterzero[i] % (num + 1);
  }

  int ans = 0;
  for (int n = 0; n < 3; n++) {
    target = zero;
    for (int i = 0; i < numafterzero[n]; i++) {
      target = target->c;
    }
    printf("%d ", target->value);
    ans += target->value;
  }

  return ans;
}

int part2(char *buf, int bufsize) { return 0; }

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[27000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 20\n");
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
