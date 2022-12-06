#include "aocutils.h"

int part1(char *buf, int bufsize) {
  char *c = buf;
  char *end = buf + bufsize;
  int start_of_packet_marker = 0;
  while (c <= end - 4) {
    for (int i = 0; i < 4; i++) {
      for (int k = i + 1; k < 4; k++) {
        if (*(c + i) == *(c + k)) {
          goto next;
        }
      }
    }
    start_of_packet_marker = (int)(c - buf) + 4;
    break;
  next:
    c++;
  }

  return start_of_packet_marker;
}

int part2(char *buf, int bufsize) {
  char *c = buf;
  char *end = buf + bufsize;
  int start_of_message_marker = 0;
  while (c <= end - 14) {
    for (int i = 0; i < 14; i++) {
      for (int k = i + 1; k < 14; k++) {
        if (*(c + i) == *(c + k)) {
          goto next;
        }
      }
    }
    start_of_message_marker = (int)(c - buf) + 14;
    break;
  next:
    c++;
  }

  return start_of_message_marker;
}

int main(int argc, char *argv[]) {
  clock_t timer = clock();
  FILE *inputFile = fopen(argv[1], "r");
  int bufsize = 0;

  fseek(inputFile, 0, SEEK_END);
  bufsize = ftell(inputFile);
  rewind(inputFile);

  char buf[5000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 6\n");
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
}
