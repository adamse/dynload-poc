#include <stdio.h>

#include "iface.h"

int init_module(void) {
  int res = rts_function("hello from module");

  printf("rts says %d\n", res);

  return 1;
}
