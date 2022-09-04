/*

 * Skeleton code for ps.c

 */

#include "kernel/param.h"

#include "kernel/types.h"

#include "user/uproc.h"

#include "user/user.h"



int

main(int argc, char **argv)

{
  struct uproc uproc[NPROC];

  int nprocs;

  nprocs = getprocs(uproc);

  if (nprocs < 0)

    exit(-1);



  // You can remove the following print statement

  printf("%d processes\n", nprocs);





  exit(0);

}


