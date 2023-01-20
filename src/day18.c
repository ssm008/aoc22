#include "aocutils.h"

// dimension size need for the volume + flood filling stuff.
#define X 24
#define Y 24
#define Z 24

typedef struct cube {
  int x;
  int y;
  int z;
} cube;

int volume[X][Y][Z] = {0};
cube neighbours[] = {{0, 0, 1},  {0, 1, 0},  {1, 0, 0},
                     {0, 0, -1}, {0, -1, 0}, {-1, 0, 0}};

cube add(cube *a, cube *b) {
  cube ret;
  ret.x = a->x + b->x;
  ret.y = a->y + b->y;
  ret.z = a->z + b->z;
  return ret;
}

int count_surfaces1(cube *a) {
  int count = 0;
  cube n;
  for (int i = 0; i < 6; i++) {
    n = add(a, &neighbours[i]);
    count += volume[n.x][n.y][n.z] == 0;
  }
  return count;
}

int part1(char *buf, int bufsize) {
  int numcubes = 0;
  char *c = buf;
  int xyz[3];
  int len;
  cube next;
  cube cubes[3000];
  while (c < buf + bufsize - 1) {
    getNumsOnLine(c, xyz, &len);
    // I do this so that there is empty space around the droplet in the volume.
    next.x = xyz[0] + 1;
    next.y = xyz[1] + 1;
    next.z = xyz[2] + 1;
    cubes[numcubes] = next;
    volume[next.x][next.y][next.z] = 1;
    numcubes++;
    c += len;
  }

  int surfaces = 0;
  for (int i = 0; i < numcubes; i++) {
    surfaces += count_surfaces1(&cubes[i]);
  }

  return surfaces;
}

cube stack[13000];
int head = 0;
void push(cube v) { stack[head++] = v; }
cube pop() { return stack[--head - 1]; }
void reset() { head = 0; }

int find_neighbour(cube *a) {
  // returns 0 if no neighbours found
  cube n;
  for (int i = 0; i < 6; i++) {
    n = add(a, &neighbours[i]);
    // gotta have some boundries, man
    if (n.x > X - 1 || n.y > Y - 1 || n.z > Z - 1 || n.x < 0 || n.y < 0 ||
        n.z < 0)
      continue;
    if (volume[n.x][n.y][n.z] == 0) {
      a->x = n.x;
      a->y = n.y;
      a->z = n.z;
      return 1;
    }
  }

  return 0;
}

int count_surfaces2(cube *a) {
  int count = 0;
  cube n;
  for (int i = 0; i < 6; i++) {
    n = add(a, &neighbours[i]);
    count += volume[n.x][n.y][n.z] == 2;
  }
  return count;
}

int part2(char *buf, int bufsize) {
  int numcubes = 0;
  char *c = buf;
  int xyz[3];
  int len;
  cube next;
  cube cubes[3000];
  while (c < buf + bufsize - 1) {
    getNumsOnLine(c, xyz, &len);
    // I add 1 so that there is empty space around the droplet in the volume.
    next.x = xyz[0] + 1;
    next.y = xyz[1] + 1;
    next.z = xyz[2] + 1;

    cubes[numcubes] = next;
    volume[next.x][next.y][next.z] = 1;
    numcubes++;

    c += len;
  }

  // Flood fill, starting from 0,0,0 and doing depth first search through all
  // the empty space around the droplet.
  memset(&next, 0, sizeof(int) * 3);
  volume[0][0][0] = 2;
  push(next);
  while (1) {
    if (find_neighbour(&next)) {
      // found a neighbour and wrote coordinates to next
      volume[next.x][next.y][next.z] = 2;
      push(next);
    } else {
      next = pop();
    }

    if (next.x == 0 && next.y == 0 && next.z == 0) break;
  }

  // And finally, check which surfaces are in contact with the flood filled
  // stuff
  int surfaces = 0;
  for (int i = 0; i < numcubes; i++) {
    surfaces += count_surfaces2(&cubes[i]);
  }

  return surfaces;
}

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
