#include "aocutils.h"

struct section_parse {
  char *bos;
  int limits[4];
};

char *
sparse(struct section_parse *sp) {
  char c;
  int n = 0;
  int elf = 0;

  while (1) {
    c = sp->bos[0];
    if (c == '\n') {
      sp->limits[elf] = n;
      break;
    }
    if (c >= '0' && c <= '9') {
      n = n * 10 + c - '0';
    } else {
      sp->limits[elf++] = n;
      n = 0;
    }
    sp->bos++;
  }

  return sp->bos + 1;
}

int part1(char *buf, int bufsize) {
  int total_overlaps = 0;
  struct section_parse s = {0};
  s.bos = buf;

  while (s.bos < buf + bufsize) {
    s.bos = sparse(&s);
    if ((s.limits[0] >= s.limits[2] && s.limits[1] <= s.limits[3]) ||
        (s.limits[2] >= s.limits[0] && s.limits[3] <= s.limits[1])) {
      total_overlaps++;
    }
  }
  return total_overlaps;
}

int part2(char *buf, int bufsize) {
  int total_overlaps = 0;
  struct section_parse s = {0};
  s.bos = buf;

  while (s.bos < buf + bufsize) {
    s.bos = sparse(&s);
    if (!(s.limits[0] > s.limits[3] || s.limits[1] < s.limits[2])) {
      total_overlaps++;
    }
  }
  return total_overlaps;
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

  printf("Day 4\n");
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
