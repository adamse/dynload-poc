#include <dlfcn.h>
#include <stdio.h>

#include "iface.h"

int rts_function(char * what) {
  printf("%s\n", what);
  return 100;
}

int main(int argc, char * argv[]) {

  void * obj = dlopen("./obj.so", RTLD_NOW);
  perror("dlopen");
  printf("dlopen: %s\n", dlerror());
  printf("loaded at: %p\n", obj);

  init_module_t * init_module;
  init_module = (init_module_t *)dlsym(obj, "init_module");
  perror("dlopen");
  printf("dlopen: %s\n", dlerror());
  printf("loaded at: %p\n", init_module);
  printf("initialising module\n");

  init_module();

  return 0;
}
