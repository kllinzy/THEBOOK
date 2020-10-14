#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/random.h>
#include <stdio.h>
int main(int arg, char *argv[])
{
  void *buf = NULL;
  size_t l = 5;
  unsigned int o = 1;
  int r = syscall(SYS_getrandom, buf, l, o);
  printf("%d\n", r);
  return 0;
}
