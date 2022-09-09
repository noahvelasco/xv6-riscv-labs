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
  printf("\n---------%d processes active------------\n", nprocs);
    
//  printf("\npid 0 = %d\n", *(&uproc)[0]->pid);
//  struct uproc *up;
//
//  printf("\n");
//  int i = 0;
//  for(up = uproc; up < uproc ; up+=sizeof(uproc) ){
//    if(p->state == UNUSED)
//      continue;
//    if(p->state >= 0 && p->state < NELEM(states) && states[p->state])
//      state = states[p->state];
//    else
//      state = "???";
//    printf("i = %d\n", i);
//    printf("%d %s\n", up->pid, up->name);
//    i++;
//  }

  exit(0);

}


