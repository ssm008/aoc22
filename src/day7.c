#include "aocutils.h"

typedef struct tree {
  char name[12];
  long size;
  struct tree *child[100];
  struct tree *parent;
} Tree;

int check_if_child(Tree *dir, char *name) {
  int i = 0;
  int ischild = 0;
  while (dir->child[i] != NULL) {
    for (int j = 0; *(name + j) != '\n'; j++) {
      if (dir->child[i]->name[j] != *(name + j))
        goto ischild_next;
    }
    ischild = 1;
    break;
  ischild_next:
    i++;
  }
  return ischild;
}

int part1(char *buf, int bufsize) {
  Tree nodes[1000] = {0};
  Tree *cwd = nodes;
  char *c = buf;
  int node_cnt = 0;
  int i = 0;

  while (c <= buf + bufsize) {
    if (*c == '$') {
      c += 2; // from $ to cd
      if (*c == 'c') {
        c += 3; // from cd to name
        nodes[node_cnt].parent = cwd;
        cwd = &nodes[node_cnt++];
        if (*c == '.' && *(c + 1) == '.') {
          cwd = cwd->parent;
          c += 3; // to next line
        } else {
          for (i = 0; *(c + i) != '\n'; i++) {
            cwd->name[i] = *(c + i);
          }
          c += i + 1;
        }
      }
      // process command until \n
    } else if (*c >= '0' && *c <= '9') {
      // process content until \n
    } else {
      // process dir until \n
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

  char buf[15000];
  fread(buf, 1, bufsize, inputFile);
  buf[bufsize] = 0;
  fclose(inputFile);

  printf("Day 7\n");
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
