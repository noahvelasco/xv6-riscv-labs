#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"
/*
Ctrl-p should do this aswell

2 main processes

1 sleep  init
2 sleep  sh
*/


int main(int argc, char **argv)

{
  struct uproc uproc[NPROC];
  int nprocs;
  nprocs = getprocs(uproc); //will return # of active processes

  if (nprocs < 0)

    exit(-1);
    
    // You can remove the following print statement
  printf("\n------ In PS -----");
  printf("\n%d processes\n", nprocs);
    
  exit(0);

}


