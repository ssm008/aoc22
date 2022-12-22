#include "aocutils.h"

static int grid[200][366];
const int coloffset = 317;
int abyss = 0;

struct pos {
  int row, col;
};

void setupgrid(char *buf, int bufsize) {
  char *c = buf;
  struct pos start;
  struct pos stop;
  int numbers[70];
  int skip = 0;
  int nums = 0;
  int drow, dcol;

  while (c <= buf + bufsize - 1) {
    nums = getNumsOnLine(c, numbers, &skip);
    c += skip;
    start.col = numbers[0];
    start.row = numbers[1];
    for (int i = 2; i < nums - 1; i += 2) {
      stop.col = numbers[i];
      stop.row = numbers[i + 1];
      drow = stop.row - start.row;
      dcol = stop.col - start.col;

      while (drow || dcol) {
        grid[stop.row - drow][stop.col - coloffset - dcol] = 1;
        drow += (drow < 0) - (drow > 0);
        dcol += (dcol < 0) - (dcol > 0);
      }
      grid[stop.row - drow][stop.col - coloffset - dcol] = 1;

      if (stop.row > abyss)
        abyss = stop.row;
      start.row = stop.row;
      start.col = stop.col;
    }
  }
}

struct pos stack[300];
int head = 0;
void push(struct pos v) { stack[head++] = v; }
struct pos pop() {
  return stack[--head - 1];
}
struct pos peek() {
  return stack[head - 1];
}
void reset() { head = 0; }

int part1(char *buf, int bufsize) {
  setupgrid(buf, bufsize);
  int row = 0;
  int units = 0;
  struct pos cur = {.row = 0, .col = 183};
  push(cur);
  while (row < abyss) {
    if (!grid[cur.row + 1][cur.col]) {
      cur.row++;
      push(cur);
    }
    else if (!grid[cur.row + 1][cur.col - 1]) {
      cur.row++;
      cur.col--;
      push(cur);
    }
    else if (!grid[cur.row + 1][cur.col + 1]) {
      cur.row++;
      cur.col++;
      push(cur);
    }
    else {
      units++;
      grid[cur.row][cur.col] = 2;
      cur = pop();
    }
    row = cur.row;
  }
  return units;
}

int part2(char *buf, int bufsize) {
  memset(grid, 0, sizeof(grid));
  setupgrid(buf, bufsize);
  for (int i = 0; i < 366; i++) {
    grid[abyss + 2][i] = 1;
  }
  reset();
  int row = 1;
  int units = 0;
  struct pos cur = {.row = 0, .col = 183};
  push(cur);
  while (head) {
    // check below
    if (!grid[cur.row + 1][cur.col]) {
      cur.row++;
      push(cur);
    }
    // check left
    else if (!grid[cur.row + 1][cur.col - 1]) {
      cur.row++;
      cur.col--;
      push(cur);
    }
    // check right
    else if (!grid[cur.row + 1][cur.col + 1]) {
      cur.row++;
      cur.col++;
      push(cur);
    }
    // has come to rest.
    else {
      units++;
      grid[cur.row][cur.col] = 2;
      cur = pop();
    }
    row = cur.row;
  }

  return units;
}

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[25000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 14\n");
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
