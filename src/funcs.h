#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int msleep(long msec);

typedef struct position{
  int x;
  int y;
}Position;

typedef struct row{
  char *frame;
}Row;

