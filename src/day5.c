#include "aocutils.h"

#define STACKS 9
#define DEPTH 100

int part1(char *buf, int bufsize, char *ans) {
  char *c = buf;
  char stack[STACKS][DEPTH];
  // push to sp, pop from sp-1
  int sp[STACKS] = {0};

  // init the stack
  for (int s = 0; s < 9; s++) {
    while (1) {
      if (*c == '\n') {
        if (*(c + 1) == '\n') {
          goto instruction_input;
        }
        c++;
        break;
      }
      stack[s][sp[s]++] = *c;
      c++;
    }
  }

instruction_input:
  c += 2; // move past the empty line between initial stack and instructions
  // amount, from, to
  int in[3] = {0};
  int curr = 0;
  while (c <= buf + bufsize) {
    if (*c >= '0' && *c <= '9') {
      in[curr] *= 10;
      in[curr] += *c - '0';
      curr += (*(c + 1) > '9' || *(c + 1) < '0');
    } else if (*c == '\n') {
      curr = 0;
        in[2]--;
        in[1]--;
        for (int i = in[0]; i > 0; i--) {
          stack[in[2]][sp[in[2]]++] = stack[in[1]][sp[in[1]]-- - 1];
        }
      memset(in, 0, sizeof(in));
    }
    c++;
  }

  for (int i = 0; i < 9; i++) {
    ans[i] = stack[i][sp[i] - 1];
  }
  return 0;
}

int part2(char *buf, int bufsize, char *ans) {
  char *c = buf;
  char stack[STACKS][DEPTH];
  // push to sp, pop from sp-1
  int sp[STACKS] = {0};

  // init the stack
  for (int s = 0; s < 9; s++) {
    while (1) {
      if (*c == '\n') {
        if (*(c + 1) == '\n') {
          goto instruction_input2;
        }
        c++;
        break;
      }
      stack[s][sp[s]++] = *c;
      c++;
    }
  }

instruction_input2:
  c += 2;
  // amount, from, to
  int in[3] = {0};
  int curr = 0;
  while (c <= buf + bufsize) {
    if (*c >= '0' && *c <= '9') {
      in[curr] *= 10;
      in[curr] += *c - '0';
      curr += (*(c + 1) > '9' || *(c + 1) < '0');
    } else if (*c == '\n') {
      curr = 0;
      in[2]--;
      in[1]--;
      for (int i = in[0]; i > 0; i--) {
        stack[in[2]][sp[in[2]]++] = stack[in[1]][sp[in[1]] - i];
      }
      sp[in[1]] -= in[0];
      memset(in, 0, sizeof(in));
    }
    c++;
  }

  for (int i = 0; i < 9; i++) {
    ans[i] = stack[i][sp[i] - 1];
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

  char buf[10000];
  fread(buf, 1, bufsize, inputFile);
  fclose(inputFile);

  printf("Day 5\n");
  timer = clock() - timer;
  printf("\tInput file modified manually for initial stack\n");
  printf("\tBuffering input file: %d bytes in %d µs\n", bufsize,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  char *ans = calloc(1, 10);
  timer = clock();
  int part1_solution = part1(buf, bufsize, ans);
  timer = clock() - timer;
  printf("\tPart 1 solution: %s (%d µs)\n", ans,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

  rewind(inputFile);
  memset(ans, 0, 10);
  timer = clock();
  int part2_solution = part2(buf, bufsize, ans);
  timer = clock() - timer;
  printf("\tPart 2 solution: %s (%d µs)\n", ans,
         (int)((double)timer / CLOCKS_PER_SEC * 1000000));

}
