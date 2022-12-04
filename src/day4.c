#include "aocutils.h"

enum section_limits {
  ELF1_START = 0,
  ELF1_END = 1,
  ELF2_START = 2,
  ELF2_END = 3,
  NUM_OF_LIMITS
};

struct section_parse {
  char *line_start;
  int limits[NUM_OF_LIMITS];
};

char *
sparse(struct section_parse *sp) {
  char c;
  int n = 0;
  int limit = 0;

  while (1) {
    c = sp->line_start[0];
    if (c == '\n') {
      sp->limits[limit] = n;
      break;
    }
    if (c >= '0' && c <= '9') {
      n = n * 10 + c - '0';
    } else {
      sp->limits[limit++] = n;
      n = 0;
    }
    sp->line_start++;
  }

  return sp->line_start + 1;
}

int part1(char *buf, int bufsize) {
  int total_overlaps = 0;
  struct section_parse s = {0};
  s.line_start = buf;

  while (s.line_start < buf + bufsize) {
    s.line_start = sparse(&s);
    if ((s.limits[ELF1_START] >= s.limits[ELF2_START] &&
         s.limits[ELF1_END] <= s.limits[ELF2_END]) ||
        (s.limits[ELF2_START] >= s.limits[ELF1_START] &&
         s.limits[ELF2_END] <= s.limits[ELF1_END])) {
      total_overlaps++;
    }
  }
  return total_overlaps;
}

int part2(char *buf, int bufsize) {
  int total_overlaps = 0;
  struct section_parse s = {0};
  s.line_start = buf;

  while (s.line_start < buf + bufsize) {
    s.line_start = sparse(&s);
    if (!(s.limits[ELF1_START] > s.limits[ELF2_END] ||
          s.limits[ELF1_END] < s.limits[ELF2_START])) {
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
