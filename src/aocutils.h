#ifndef AOCUTIL_H
#define AOCUTIL_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/*Gets all numbers before newline, you make sure the ret buffer is big enough*/
unsigned int getNumsOnLine(char *buf, int *ret, int *line_len) {
  char *c = buf;
  int cnt = 0;
  int num = 0;
  int parsing_num = 0;
  while (*(c) != '\n') {
    if (*c >= '0' && *c <= '9') {
      parsing_num = 1;
      num = num * 10 + (int)(*c - '0');
    } else {
      if (parsing_num) {
        parsing_num = 0;
        ret[cnt++] = num;
        num = 0;
      }
    }
    c++;
  }
  if (parsing_num) {
    ret[cnt++] = num;
  }
  *line_len = (int)(c - buf) + 1;
  return cnt;
}


#endif
