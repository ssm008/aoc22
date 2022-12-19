#include "aocutils.h"

enum direction { LEFT, RIGHT, UP, DOWN };

struct pos {
  int x, y;
};

struct move {
  enum direction dir;
  int steps;
};

struct move
getMove(char **bufpos) {
  char *c = *bufpos;
  int len = 0;
  struct move m = {0, 0};
  switch (*c) {
  case 'L':
    m.dir = LEFT;
    break;
  case 'R':
    m.dir = RIGHT;
    break;
  case 'U':
    m.dir = UP;
    break;
  case 'D':
    m.dir = DOWN;
    break;
  default:
    printf("Input failure\n");
    break;
  }

  len += 2;
  while (*(c + len) >= '0' && *(c + len) <= '9') {
    m.steps = 10 * m.steps + (int)(*(c + len) - '0');
    len++;
  }
  *bufpos += len + 1;
  return m;
}

void step(struct pos *H, enum direction dir) {
  switch (dir) {
  case LEFT:
    H->x--;
    break;
  case RIGHT:
    H->x++;
    break;
  case UP:
    H->y--;
    break;
  case DOWN:
    H->y++;
    break;
  }
}

void follow(struct pos *H, struct pos *T) {
  int dx = H->x - T->x;
  int dy = H->y - T->y;

  T->y += dy - (dy > 0) + (dy < 0);
  T->x += dx - (dx > 0) + (dx < 0);

  if ((dx > 1 || dx < -1) && (dy == -1 || dy == 1)) {
    T->y += dy;
  } else if ((dy > 1 || dy < -1) && (dx == -1 || dx == 1)) {
    T->x += dx;
  }
}

int part1(char *buf, int bufsize) {
  struct pos H = {0, 0};
  struct pos T = {0, 0};
  char *c = buf;
  struct move m;
  int bigassgrid[200][300] = {0};
  int visitnewpos = 0;

  while (c <= buf + bufsize - 1) {
    m = getMove(&c);
    for (int i = 0; i < m.steps; i++) {
      step(&H, m.dir);
      follow(&H, &T);
      if (bigassgrid[T.y + 53][T.x + 65] == 0) {
        visitnewpos++;
        bigassgrid[T.y + 53][T.x + 65] = 1;
      }
    }
  }

  return visitnewpos;
}

int part2(char *buf, int bufsize) {
  struct pos H = {0, 0};
  struct pos T[9] = {0};
  char *c = buf;
  struct move m;
  int bigassgrid[200][300] = {0};
  int visitnewpos = 0;

  while (c <= buf + bufsize - 1) {
    m = getMove(&c);
    for (int i = 0; i < m.steps; i++) {
      step(&H, m.dir);
      follow(&H, &T[0]);
      for (int t = 1; t < 9; t++) {
        follow(&T[t - 1], &T[t]);
      }
      if (bigassgrid[T[8].y + 53][T[8].x + 65] == 0) {
        visitnewpos++;
        bigassgrid[T[8].y + 53][T[8].x + 65] = 1;
      }
    }
  }

  return visitnewpos;
}

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[10000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 9\n");
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
