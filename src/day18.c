#include "aocutils.h"

typedef struct cube {
  int x[3000];
  int y[3000];
  int z[3000];
} cube;

int touching(int ax, int ay, int az, int bx, int by, int bz) {
  return (abs(ax - bx) + abs(ay - by) + abs(az - bz)) == 1;
}

int part1(char *buf, int bufsize) {
  int numcubes = 0;
  char *c = buf;
  int xyz[3];
  int len;
  cube cubes;
  while (c < buf + bufsize - 1) {
    getNumsOnLine(c, xyz, &len);
    cubes.x[numcubes] = xyz[0];
    cubes.y[numcubes] = xyz[1];
    cubes.z[numcubes] = xyz[2];
    numcubes++;
    c += len;
  }

  int ret = 6 * numcubes;
  for (int a = 0; a < numcubes; a++) {
    for (int b = a + 1; b < numcubes; b++) {
      if (touching(cubes.x[a], cubes.y[a], cubes.z[a], cubes.x[b], cubes.y[b],
                   cubes.z[b])) {
        ret -= 2;
      }
    }
  }

  return ret;
}

int part2(char *buf, int bufsize) { return 0; }

int main(int argc, char *argv[]) {
  clock_t timer = clock();

  struct stat s;
  int fd = open(argv[1], O_RDONLY);
  fstat(fd, &s);
  int bufsize = s.st_size;
  char *buf = (char *)mmap(0, bufsize, PROT_READ, MAP_PRIVATE, fd, 0);

  printf("Day 18\n");
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

  munmap(buf, bufsize);
}
