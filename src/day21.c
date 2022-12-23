#include "aocutils.h"

struct node {
  long (*op)(struct node *, struct node *);
  struct node *left;
  struct node *right;
  long id;
};

long _add(struct node *L, struct node *R) {
  return L->op(L->left, L->right) + R->op(R->left, R->right);
}
long _sub(struct node *L, struct node *R) {
  return L->op(L->left, L->right) - R->op(R->left, R->right);
}
long _mul(struct node *L, struct node *R) {
  return L->op(L->left, L->right) * R->op(R->left, R->right);
}
long _div(struct node *L, struct node *R) {
  return L->op(L->left, L->right) / R->op(R->left, R->right);
}
long _con(struct node *L, struct node *R) { return (long)L; }

long (*get_op(char o))(struct node *, struct node *) {
  switch (o) {
  case '+':
    return _add;
  case '-':
    return _sub;
  case '*':
    return _mul;
  case '/':
    return _div;
  default:
    printf("Wrong operation\n");
    return 0;
  }
}

int get_id(char *name) {
  return *((int *)name);
}

long part1(char *buf, int bufsize) {
  char *c = buf;
  struct node monkeys[3000];
  int monkindex = 0;
  int nummonkeys = 0;
  int id[3];
  long constant = 0;
  int i;

  while (c <= buf + bufsize - 1) {
    monkeys[monkindex].id = get_id(c);
    monkindex++;
    if (c[7] >= 'a') {
      c += 18;
      continue;
    }
    while (*(c++) != '\n') {
    }
  }

  c = buf;
  nummonkeys = monkindex;
  monkindex = 0;
  while (c <= buf + bufsize - 1) {
    id[0] = get_id(c);
    c += 6;

    // create a monkey with numeric value
    if (*c >= '0' && *c <= '9') {
      for (i = 0; i < nummonkeys; i++) {
        if (monkeys[i].id == id[0]) {
          monkeys[i].left = &monkeys[i];
          monkeys[i].op = _con;
          while (*c >= '0' && *c <= '9')
            constant = constant * 10 + *(c++) - '0';
          monkeys[i].left = (struct node *)constant;
          constant = 0;
          monkindex++;
          c++;
          break;
        }
      }
      continue;
    }

    id[1] = get_id(c);
    c += 5;
    monkeys[monkindex].op = get_op(*c);
    c += 2;

    id[2] = get_id(c);
    c += 5;

    // find the monkeys with the left/right values
    int found = 0;
    for (i = 0; i < nummonkeys; i++) {
      if (monkeys[i].id == id[1]) {
        monkeys[monkindex].left = &monkeys[i];
        if (found++)
          break;
      }
      if (monkeys[i].id == id[2]) {
        monkeys[monkindex].right = &monkeys[i];
        if (found++)
          break;
      }
    }

    monkindex++;
  }

  // find root and calculate whole damn tree.
  long ret = 0;
  int rootid = get_id("root");
  for (i = 0; i < nummonkeys; i++) {
    if (monkeys[i].id == rootid) {
      ret = monkeys[i].op(monkeys[i].left, monkeys[i].right);
    }
  }

  return ret;
}

int part2(char *buf, int bufsize) { return 0; }

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[38200];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 21\n");
  timer = clock() - timer;
  printf("\tBuffering input file: %d bytes in %d µs\n", bufsize,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  timer = clock();
  long part1_solution = part1(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 1 solution: %ld (%d µs)\n", part1_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  timer = clock();
  int part2_solution = part2(buf, bufsize);
  timer = clock() - timer;
  printf("\tPart 2 solution: %d (%d µs)\n", part2_solution,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));
}
