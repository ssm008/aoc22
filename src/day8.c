#include "aocutils.h"

int forest[99][99];

int part1(char *buf, int bufsize) {
  int size = 5 * (bufsize == 30) + 99 * (bufsize == 9900);
  char *c = buf;
  int visible[99][99] = {0};
  int row = 0;
  int col = 0;
  while (c <= buf + bufsize) {
    if (*c > '\n') {
      forest[row][col] = *c - '0';
      col++;
    } else {
      col = 0;
      row++;
    }
    c++;
  }

  // piu piu, laser scanner
  int laz0r = 0;
  for (row = 0; row < size; row++) {
    laz0r = forest[row][0];
    col = 0;
    // loop row from left to right until hitting highest tree or end of row.
    while (laz0r <= 9 && col < size) {
      visible[row][col] += laz0r <= forest[row][col];
      laz0r += (laz0r <= forest[row][col]) * (forest[row][col] - laz0r + 1);
      col++;
    }
    laz0r = forest[row][size - 1];
    col = size - 1;
    // loop row from right to left until hitting highest tree or end of row.
    while (laz0r <= 9 && col > 0) {
      visible[row][col] += laz0r <= forest[row][col];
      laz0r += (laz0r <= forest[row][col]) * (forest[row][col] - laz0r + 1);
      col--;
    }
  }

  for (col = 0; col < size; col++) {
    laz0r = forest[0][col];
    row = 0;
    while (laz0r <= 9 && row < size) {
      visible[row][col] += laz0r <= forest[row][col];
      laz0r += (laz0r <= forest[row][col]) * (forest[row][col] - laz0r + 1);
      row++;
    }
    laz0r = forest[size - 1][col];
    row = size - 1;
    while (laz0r <= 9 && row > 0) {
      visible[row][col] += laz0r <= forest[row][col];
      laz0r += (laz0r <= forest[row][col]) * (forest[row][col] - laz0r + 1);
      row--;
    }
  }

  int numvisible = 0;
  int *v = &visible[0][0];
  for (int i = 0; i < 9801; i++) {
    numvisible += v[i] > 0;
  }

  return numvisible;
}

int calc_view_score(int row, int col, int size) {

  int left = 0;
  int right = 0;
  int up = 0;
  int down = 0;
  for (int i = col - 1; i >= 0; i--) {
    left++;
    if (forest[row][i] >= forest[row][col]) {
      break;
    }
  }
  for (int i = col + 1; i <= size - 1; i++) {
    right++;
    if (forest[row][i] >= forest[row][col]) {
      break;
    }
  }
  for (int i = row - 1; i >= 0; i--) {
    up++;
    if (forest[i][col] >= forest[row][col]) {
      break;
    }
  }
  for (int i = row + 1; i <= size - 1; i++) {
    down++;
    if (forest[i][col] >= forest[row][col]) {
      break;
    }
  }
  return left * right * up * down;
}

int part2(char *buf, int bufsize) {
  int size = 5 * (bufsize == 30) + 99 * (bufsize == 9900);
  int viewscore = 0;
  int max = 0;

  for (int row = 1; row < size - 1; row++) {
    for (int col = 1; col < size - 1; col++) {
      viewscore = calc_view_score(row, col, size);
      if (viewscore > max) {
        max = viewscore;
      }
    }
  }

  return max;
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

  printf("Day 8\n");
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
